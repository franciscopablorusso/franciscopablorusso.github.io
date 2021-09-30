#include <iostream>
#include <cmath>
#include <typeinfo>
#include <sstream>
using namespace std;
class A {
    private:
    double *vec;
    short len;

    public:
    A(short w, double a, double b) {
        vec = new double[w];
        len = w;
        for (int i = 0; i < len; i++) {
            double r = (double) rand() / RAND_MAX;
            vec[i] = a + r * (b - a);
        }
    }
    virtual double foo(short a) = 0;
    short getLen() {
        return len;
    }

    virtual ostream &put(ostream &os) {
        stringstream ss;
        ss << "vec = [ ";
        for (int i = 0; i < getLen(); i++) {
            ss << vec[i] << " ";
        }
        ss << "] ";
        os << ss.str();
        return os;
    }
    double &operator [] (short i) {
        return vec[i];
    }

    protected:
    double get(short i) {
        return vec[i % len];
    }
};

class B : public A {
    private:
    int p;

    public:
    B(short m, short x, short y) : A(m, x, y) {
        int first = 10 * x;
        int second = 100 * y;
        p = rand() % (first - second) + first;
    }
    double foo(short a) {
        return log(prod(a, a / 2));
    }
    ostream &put(ostream &os) {
        os << "1B, ";
        A::put(os);
        os << "p =" << p << ", foo(3) = " << foo(3);
        return os;
    }

    protected:
    double prod(short s, double v) {
        double sum = 0;
        for (int i = s; i < getLen(); i++) {
            sum += get(i);
        }
        return sum * v;
    }
};

template<typename T> class C : public A {
    private:
    T y;

    public:
    C(short n, double x, double y) : A(n, x, y) {
        if (typeid(y).name() == typeid(short).name()) {
            y = n;
        } else {
            y = getLen() + cos(pow(n, 2));
        }
        this -> y = y;
    }
    double foo(short r) {
        return g(r);
    }
    double g(double k) {
        return (2 * y) * (k + 1);
    }
    ostream &put(ostream &os) {
        os << "1CIsE, ";
        A::put(os);
        os << "y = " << y << ", foo(3) = " << foo(3);
        return os;
    }
};

ostream &operator << (ostream &os, A &a) {
    return a.put(os);
}

int main() {
    int DIM = 50;
    A *vett[DIM];
    srand(111222333);
    for (int i = 0; i < DIM; i++) {
	    short n = 5 + rand() % 5;
	    switch(rand() % 3) {
	    case 0: 
	        vett[i]= new B(n, rand() % 5 + 1, rand() % 10 + 5);
	        break;
	    case 1:
	        vett[i]= new C<double>(n, rand() % 5 + 1, rand() % 10 + 5);
	        break;
	    case 2: 
	        vett[i]= new C<short>(n, rand() % 5 + 1, rand() % 10 + 5);
	    }
    }
    cout << "PUNTO 1" << endl;
    for (int i = 0; i < DIM; i++) {
        cout << i << ") " << *vett[i] << endl;
    }
    cout << "PUNTO 2" << endl;
    double max = vett[0]->foo(3);
    double sum = 0;
    for (int i = 0; i < DIM; i++) {
        if (max < vett[i]->foo(3)) {
            max = vett[i]->foo(3);
        }
        if (dynamic_cast<C<double>*>(vett[i])) {
            sum += ((C<double>*)vett[i])->g(0.5);
        }
    }
    cout << "Max: " << max << ", Avg: " << sum / DIM << endl;

    cout << "PUNTO 3" << endl;
    short sel = 2;
    short index = vett[sel]->getLen() - vett[sel]->getLen() + 1;
    cout << "vett[" << sel << "] " << *vett[sel] << endl;
    cout << "(vet[" << sel << "])[" << index << "] = " << (*vett[sel])[index] << endl;
}
