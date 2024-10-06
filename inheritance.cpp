#include <iostream>
using namespace std;

class car {

public:

	string brand;
	string model;
	int year;


	car(string b,string m,int y) {

		brand=b;
		model=m;
		year=y;
	}

	void dis() {
		cout<<"CAR BRAND:"<<brand<<endl;
		cout<<"CAR MODEL:"<<model<<endl;
		cout<<"YEAR:"<<year<<endl;
	}

};



class electronic:public car {
public:
	int batterycap;

	electronic(string b,string m,int y,int bc):car(b, m,y) {
		batterycap=bc;

	}


	void dis1() {
		dis();
		cout<<"BATTERY CAPACITY:"<<batterycap<<"Kwh"<<endl<<endl;
	}
};






class gasline:public car {
public:
	int fuelcap;

	gasline(string b,string m,int y,int f):car(b, m,y) {
		fuelcap=f;

	}


	void dis1() {
		dis();
		cout<<"FUEL CAPACITY:"<<fuelcap<<"L"<<endl<<endl;
	}
};







int main() {

	electronic e("Tesla.","S",2022,100);
	e.dis1();
	
electronic d("GTR.","type R",2024,150);
	d.dis1();


	gasline g("Mercedes.","M",2025,15);
	g.dis1();


	
	gasline c("BMW.","R",2024,12);
	c.dis1();




}