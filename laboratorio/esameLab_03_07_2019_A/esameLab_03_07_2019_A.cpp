#include <iostream>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <sstream>

using namespace std;

class A{
	private:
		int* arr;
		short len;
	public:
		A(short m, int a, int b){
			arr = new int[m];
			for(int i=0; i<m; i++){
				arr[i] = rand()%(a-b)+a;
			}
			len = m;
		}
		virtual double func(short i) = 0;
		virtual ostream& put(ostream &os){
			stringstream ss;
			ss << "arr=[ ";
			for(int i=0; i<len; i++){
				ss << arr[i] << " ";
			}
			ss << " ]";
			return os << ss.str();
		}
		short getLen(){
			return len;
		}
		int& operator[](short i){
			return arr[i];
		}
	protected:
		double get(short i){
			return arr[i%len];
		}
};

class B: public A{ //ho ereditato la classe A, erediteremo anche il costruttore di A
	private:
		double p;
	public:
		B(short m, int y, int z, double x):A(m,y,z){
			p=x;
		}
		double func(short i){
			int min = get(0);
			int max = get(0);
			for(int i=1; i<getLen(); i++){
				if(get(i)<min){
					min = get(i);
				}
				if(get(i)>max){
					max = get(i);
				}
			}
			return ((double)(min/max))+p;
		}
		ostream& put(ostream &os){
			os << "1B, ";
			A::put(os);
			os << ", p=" << p << ", func(3)=" << func(3);
			return os;
		}
};

class C: public A{
	private:
		char t;
	public:
		C(short n, char c, int a, int b):A(n,a,b){
			t=c;
		}
		double func(short i){
			int sum = 0;
			double media = 0.0;
			for(int i=0; i<getLen(); i++){
				sum += get(i);
			}
			media = (double)(sum/getLen());
			return media;
		}
		string g(char c, short k){
			string str=" ";
			string str1=" ";
			str=t*c;
			for(int i=0; i<k; i++){
				str1 += str;
			}
			return str1;
		}
		ostream& put(ostream &os){
			os << "1C, ";
			A::put(os);
			os << ", t=" << t << ", func(3)=" << func(3);
			return os;
		}
};


ostream& operator<<(ostream &os, A &a){
	return a.put(os);
}

int main(){
	int DIM = 50;
	A* vett[DIM];

	srand(111222333);

	for(int i=0; i<DIM; i++){
		short n=1+rand()%10;
		if(rand()%2==0)
	  		vett[i]= new B(n, rand()%5+1, rand()%11+10, (double) rand()/(RAND_MAX));
		else
	  		vett[i]= new C(n, (char) (rand()%('z' - 'a' + 1) + 'a'), rand()%5+1, rand()%11+10);
   	}

   	cout<<"Punto 1"<<endl;
   	for(int i=0; i<DIM; i++){
   		cout << i << ")" << *vett[i] << endl;
   	}
   	cout << endl;
   	cout<<"Punto 2"<<endl;
   	double sum = 0.0;
   	double media = 0.0;
   	double item;
   	string item1;
   	int count = -1;
   	for(int i=0; i<DIM; i++){
   		item = vett[i]->func(3);
   		sum += item;
   		if(dynamic_cast<C*>(vett[i]) && count<3){
   			item1 =((C*)vett[i])->g('h',2);
   			cout << "i=" << i << ", g('h',2)=" << item1 << endl;
   			count++;
   		}
   	}
   	media = sum / DIM;
   	cout << "Avg(func(3))=" << media << endl;
   	cout << endl;
   	cout<<"Punto 3"<<endl;
   	for(int i=0; i<2; i++){
   		cout << "vett[5]=" << vett[5]->getLen() << endl;
   	}
}