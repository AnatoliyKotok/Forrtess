#include<iostream>
#include<string>
#include"Fortec.h"
using namespace std;

int main() {
	Shooter sh;
   /* Archer ar;
	ar.addA();
	ar.AShoot();
	Range ran;
	ran.addA();
	ran.RShoot();*/
	Fortress fort( 2, "Roks", 2,2.34,68) ;
	fort.AShoot();
	fort.print();
}