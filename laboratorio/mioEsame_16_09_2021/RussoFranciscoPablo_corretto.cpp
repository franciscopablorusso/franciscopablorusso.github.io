#include <iostream>
#include <cstdlib>
#include <string>
#include <typeinfo>
#include <sstream>
#include <cmath>

using namespace std;

class A{
	private:
		double * vec;
		short len;
	public:
		A(short w, double a, double b){
			w=len;
			vec = new double[w];
			for(int i=0; i<w; i++){
				vec[i] = (rand()%(int)((a-b)+a));	
			}
		}
		
		short getLen(short len){
			return len;
		}
		
		virtual double foo(short a) = 0;
		
		/*virtual ostream &operator <<(ostream &s){
			stringstream ss;
			ss << "vec=[ ";
			ss << " ], ";
		}*/
	protected:
		double get(short i){
			return vec[i%len];
		}
};

class B: public A {
	private:
		int p;
	public:
		B(short m, short x, short y):A(m,x,y){
			p = rand()%(100*y)+(10*x);
		}
		
		double foo(short a){
			return log(prod(a,a/2));
		}
	protected:
		double prod(short s, double v){
			double somma = 0.0;
			//int indice = s%getLen(i);
			for(int i=s%getLen(); i<getLen(); i++){
				somma += get(i);
			}
			double prodotto = v*somma;
			return prodotto;
		}
};

template <typename T>
class C: public A{
	private:
		T y;
	public:
		C(short n, double x, double y){
			if(typeid(y)==typeid(short)){
				y = n;
			}
			else{
				y = 1+cos(pow(n,2));
			}
		}
		
		double foo(short r){
			return g(r);
		}
		
		double g(double k){
			return (2*y)*(k+1);
		}
};

/*ostream &operator << (A &a, ostream &s){
	a.put(s);
}*/

int main(){
	int DIM = 50;
	
	srand(111222333);

    for(int i=0; i<DIM; i++) {
		short n=5+rand()%5;
		switch(rand()%3) {
	  		case 0: 
	    		vec[i]= new B(n, rand()%5 + 1, rand()%10 + 5);
	    	break;
	  		case 1:
	    		vec[i]= new C<double>(n, rand()%5 + 1, rand()%10 + 5);
	    	break;
	  		case 2: 
	    		vec[i]= new C<short>(n, rand()%5 + 1, rand()%10 + 5);
		}
    }
    
    cout << "PUNTO 1" << endl;
	cout << "PUNTO 2" << endl;
	cout << "PUNTO 3" << endl;    
}
