#include <iostream>
using namespace std;

class Contatore{
	int valore; //attributo

	public:

		Contatore();
		void plus();
		void out();
};

Contatore::Contatore(){
	valore = 0;
}

void Contatore::plus(){
	valore++;
}

void Contatore::out(){
	cout << valore;
}

int main(){
	Contatore c;
	c.out(); //stampa 00
	c.plus(); // incrementa valore di 1
	c.out(); //stampa 01
	cout << endl;
}