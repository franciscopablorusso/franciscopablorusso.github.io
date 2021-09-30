#include <iostream>
using namespace std;

class Data{
	private:
	int g, m, a;
	bool val(int gg, int mm, int aa);
	public:
		Data(int gg, int mm, int aa);
		void out();
		void mod(int gg, int mm, int aa);
};

Data::Data(int gg, int mm, int aa){
	if(val(gg,mm,aa)){
		g = gg;
		m = mm;
		a = aa;
	}
	else{
		g = 0;
		m = 0;
		a = 0;
	}
}

void Data::out(){
	cout << endl << g << "." << m << "." << a << endl;
}

bool Data::val(int gg, int mm, int aa){
	if(gg>31 || mm>12 || gg<=0 || mm<=0) return 0;
	else if((mm == 11 || mm == 4 || mm == 6 || mm == 9) && gg > 30) return 0;
	else if(aa%4 != 0 && mm == 2 && gg > 28) return 0;
	else return 1;
}

void Data::mod(int gg, int mm, int aa){
	if(val(gg,mm,aa)){
		g = gg;
		m = mm;
		a = aa;
	}
}

int main(){
	Data d(10,5,2021);
	d.out(); //stampa la data perché è corretta
	d.mod(-1,6,2021);
	d.out(); //non accetta la nuova data errata
	d.mod(3,4,2021);
	d.out(); //stampa la nuova data corretta
}