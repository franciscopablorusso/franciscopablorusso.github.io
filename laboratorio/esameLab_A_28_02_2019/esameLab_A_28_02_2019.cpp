#include <iostream>
#include <cstdlib> //per ls funzione rand
#include <ctime>
#include <cmath> //per log e sin
#include <string> 
#include <typeinfo> //serve per utilizzare typeid
#include <sstream>

using namespace std;

class A{
	private:
		short *arr;
		short len;
	public:
		A(short m){
			arr = new short[m];
			len = m;
			for(int i=0; i<len; i++){
				arr[i] = rand()%10+1;
			}
		}

		short getLen(){
			return len;
		}

		virtual double f(short a) = 0;

		virtual ostream &put (ostream &s) const{
			stringstream ss;
			ss << "arr[" << " ";
			for(int i=0; i<len; i++){
				ss << arr[i] << " ";
			}
			ss << "]";
			return s<<ss.str();
		}
	protected:
		short get(short i){
			return arr[i%len];
		}
};

template <typename T> 
class B: public A{
	private:
		T x; //può assumere qualsiasi tipo di valore
	public:
		B(short m, char c):A(m){
			if(typeid(x)==typeid(char)){
				x=c;
			}
			else{
				for(int i=0; i<m; i++){
					x+=c;
				}
			}
		}

		double foo(short s){
			return (double)(log(s) + sin(f(s)));
		}

		double f(short a){
			double media = 0.0;
			short indice = a%getLen();
			for(int i=indice; i<getLen(); i++){
				media+=get(i);
			}
			return media/(getLen() - indice + 1);
		}

		ostream &put (ostream &s) const{
			A::put(s);
			return s<<"x= " << x;
		}
};

class C: public A{
	private:
		int y;
	public:
		C(short n, int k):A(n){
			y=k;
		}
		
		double f(short a){
			double r = get(rand()%getLen());
			return (double)((a+y)/r);
		}

		short g(short w){
			return sin(w+y);
		}

		ostream &put (ostream &s) const{
			A::put(s);
			return s << "y=" << y;
		}

		C & operator ++(){
			y++;
			return(*this);
		}
};


ostream &operator << (ostream &s, const A &a){
	if(typeid(a)==typeid(B<char>)){
		s<<"B<char> ";
	}
	else if(typeid(a)==typeid(B<string>)){
		s<<"B<string >";
	}
	else{
		s<<"C ";
	}
	return a.put(s);
}


int main(){
	int DIM = 50;

	srand(111222333);

    A *vett[DIM];

    for(int i=0; i<DIM; i++) {
		short n=1+rand()%10;
		switch(rand()%3) {
	  	case 0: 
	    	vett[i]= new C(n, rand()%10 + 1);
	   	break;
	  	case 1:
	    	vett[i]= new B<string>(n, rand()%('z' - 'a' + 1) + 'a');
	    break;
	  	case 2: 
	    	vett[i]= new B<char>(n, rand()%('z' - 'a' + 1) + 'a');
		}
    }

    cout << "PUNTO 1" << endl;
    for(int i=0; i<DIM; i++){
    	cout << i << ")" << *vett[i] << ", f(" << 3 << ")=" << vett[i]->f(3) << endl;
    }
    cout << "PUNTO 2" << endl;
    double max = 0.0;
    double sum = 0.0;
    short contaC = 0;
    C * ptr;

    for(int i=0; i<DIM; i++){
    	double tmp = vett[i]->f(3);
    	if(tmp > max){
    		max = tmp;
    	}
    	if((ptr=dynamic_cast<C*>(vett[i])) != NULL){
    		sum += ptr->g(5);
    		contaC++;
    	}
    }
    cout << "Max f(3)=" << max << ", media g(5)=" << sum/contaC << endl;
    cout << "PUNTO 3" << endl;
    for(int i=0; i<DIM; i++){
    	if(typeid(*vett[i]) == typeid(C)){
    		C * ptr = dynamic_cast<C*>(vett[i]);
    		cout << (*ptr) << endl;
    		cout << **(*ptr) << endl;
    		break;
    	}
    }
}