#pragma once
#include<iostream>
#include<string>
using namespace std;

class Shooter {
protected:
	string nameA;
	size_t countA;
public:
	void shoot(){
		if (countA == 0) {
			throw exception("No amunition");
		}
		countA -= 1;
		cout << "Was spent ammunition->" << nameA << endl;
		cout << "Count amunition->" << countA << endl;
	}
	void addA(const string&name="arrche",size_t count=3) {
		this->nameA = name;
		this->countA = count;
	}
};
class Archer :public Shooter {
public:
	void AShoot() {
		try {
			Shooter::shoot();
			cout << "Archer shooted" << endl;
		}
		catch (exception & ex) {
			cout << ex.what() << endl;
		}

	}
};
class Range :public Shooter {
public:
	void RShoot() {
		try {
			Shooter::shoot();
			cout << "Range shooted" << endl;
		}
		catch (exception & ex) {
			cout << ex.what() << endl;
		}
	}
};
class ArcerTower:public Archer,public Range {
public:
	void ToGiveAm(size_t count=6) {
		Archer::addA("Arrche", count/2);
		Range::addA("Arrche", count /2);
	}
};
class Catapult :public Shooter {
public:
	void CShoot() {
		try {
			Shooter::shoot();
			cout << "Catapult shooted" << endl;
		}
		catch (exception & ex) {
			cout << ex.what() << endl;
		}
	}
};
class Fortress :public ArcerTower, public Catapult {
	double wals;
	size_t door = 100;
public:
	Fortress(size_t count, const string& name, size_t countr,double wals,size_t door):wals(wals),door(door) {
		ArcerTower::ToGiveAm(count);
		Catapult::addA(name, countr);
	}
	void print() {
		cout << "Wals->" << wals << endl;
		cout << "Door->" << door <<"%"<< endl;
	}
};