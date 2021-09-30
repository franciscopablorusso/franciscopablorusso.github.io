#include <iostream>
using namespace std;

class Persona{
	private:
		string nome;
	public:
		Persona (string s);
		virtual void print(){
			cout << "Il mio nome è " << nome << endl;
		}
};

Persona::Persona(string s){
	nome = s;
}