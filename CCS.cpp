/********************************************//**
 *  CCS Class Source Code
 ***********************************************/
#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>
#include "CCS.h"

#define PI 3.14159265

using namespace std;

/// CCS constructor fucntion initialize data members with set functions of Class.
CCS::CCS(double a, double b, double c, double d, double e, double f, int g)
{
	setCs1_item1(a);
	setCs1_item2(b);
	setCs1_item3(c);
	setCs2_item1(d);
	setCs2_item2(e);
	setCs2_item3(f);
	setChoice(g);
}

/// Set function for set coordinates which prompted from user.
/// Funtion use getChoice funtion to choosing conversion type.
/// If user select 5th selection, functions uses ecit() function which in <cstdlib>.
/// Sets coordinates with set item functions.
void CCS::setCoordinates()
{
	if(getChoice()==1)
		cout << "Enter x, y and z coordinates " << endl;
	if(getChoice()==2)
		cout << "Enter x, y and z coordinates " << endl;
	if(getChoice()==3)
		cout << "Enter radius, theta and phi coordinates " << endl;
	if(getChoice()==4)
		cout << "Enter rho, phi and z coordinates " << endl;
	if(getChoice()==5){
		cout << "System shuts down... " << endl;
		exit(0);
	}
	
	double a,b,c;
	
	cin >> a >> b >> c;
	
	setCs1_item1(a);
	setCs1_item2(b);
	setCs1_item3(c);
}

void CCS::setCs1_item1(double a)
{
	cs1_item1=a;
}

void CCS::setCs1_item2(double a)
{
	cs1_item2=a;
}

void CCS::setCs1_item3(double a){
	cs1_item3=a;
}

void CCS::setCs2_item1(double a)
{
	cs2_item1=a;
}

void CCS::setCs2_item2(double a)
{
	cs2_item2=a;
}

void CCS::setCs2_item3(double a)
{
	cs2_item3=a;
}

void CCS::setChoice(int a)
{
	choice=a;
}

double CCS::getCs1_item1()
{
	return cs1_item1;
}

double CCS::getCs1_item2()
{
	return cs1_item2;
}

double CCS::getCs1_item3()
{
	return cs1_item3;
}

double CCS::getCs2_item1()
{
	return cs2_item1;
}

double CCS::getCs2_item2()
{
	return cs2_item2;
}

double CCS::getCs2_item3()
{
	return cs2_item3;
}

int CCS::getChoice()
{
	return choice;
}

/// Function prompt choice from user.
/// If the user select invalid selection,
/// fucntion shows error message and countine until the user select valid selection.
void CCS::printMenu()
{
	int chc=0;
	
	cout << "***************************************" << endl;
	cout << "1. Cartesian to Spherical" << endl;
	cout << "2. Cartesian to Cylindrical" << endl;
	cout << "3. Spherical to Cartesian" << endl;
	cout << "4. Cylindrical to Cartesian" << endl;
	cout << "5. Exit" << endl;
	cout << "***************************************" << endl;
	cout << "Enter your choice " << endl;
	
	cin >> chc;
	while(true){
		if(chc<=5 && chc>=1){
			setChoice(chc);
			break;
		}
		else{
			cout << "Invalid selection...Please select valid selection..." << endl;
			cin >> chc;
		}
	}
}

/// Funtion uses getChoice funtion to choosing conversion type and makes decision 
/// to choosing right function for converting coordinates.
/// Then prints chosen coordinates, conversion type and converted coordinates.
/// For infinite loop, function use after all these; printMenu, setCoordinates functions and call itself.
void CCS::printCoordinates()
{
	
	if(getChoice()==1){
		carToSph();
	}
	if(getChoice()==2){
		carToCyl();
	}
	if(getChoice()==3){
		sphToCar();
	}
	if(getChoice()==4){
		cylToCar();
	}
	
	cout << "P(" << getCs1_item1() << "," << getCs1_item2() << "," << getCs1_item3();
	cout << getConversionType();
	cout << getCs2_item1() << "," << getCs2_item2() << "," << getCs2_item3() << ")" << endl;
}

/// Function converts coordinates with using getDegreeFromRadian and <cmath> lib functions
void CCS::carToSph()
{
	setCs2_item1(sqrt(getCs1_item1()*getCs1_item1()+getCs1_item2()*getCs1_item2()+getCs1_item3()*getCs1_item3()));
	setCs2_item2(getDegreeFromRadian(acos(sqrt(getCs1_item1()*getCs1_item1()+getCs1_item2()*getCs1_item2())/getCs1_item3())));
	setCs2_item3(getDegreeFromRadian(atan(getCs1_item2()/getCs1_item1())));
}

/// Function converts coordinates with using getDegreeFromRadian and <cmath> lib functions
void CCS::carToCyl()
{
	setCs2_item1(sqrt(getCs1_item1()*2+getCs1_item2()*getCs1_item2()));
	setCs2_item2(getDegreeFromRadian(atan(getCs1_item2()/getCs1_item1())));
	setCs2_item3(getCs1_item3());
}

/// Function converts coordinates with using getRadianFromDegree and <cmath> lib functions
void CCS::sphToCar()
{
	setCs2_item1(getCs1_item1()*sin(getRadianFromDegree(getCs1_item2()))*cos(getRadianFromDegree(getCs1_item3())));
	setCs2_item2(getCs1_item1()*sin(getRadianFromDegree(getCs1_item2()))*sin(getRadianFromDegree(getCs1_item3())));
	setCs2_item3(getCs1_item1()*cos(getRadianFromDegree(getCs1_item2())));
}

/// Function converts coordinates with using getRadianFromDegree and <cmath> lib functions
void CCS::cylToCar()
{
	setCs2_item1(getCs1_item1()*cos(getRadianFromDegree(getCs1_item1())));
	setCs2_item2(getCs1_item1()*sin(getRadianFromDegree(getCs1_item1())));
	setCs2_item3(getCs1_item3());
}

double CCS::getRadianFromDegree(double a)
{
	return a*(PI/180);
}

double CCS::getDegreeFromRadian(double a)
{
	return a*(180/PI);
}

/// Function calls getChoice function to make decision for choosing convert coordinates.
/// Returns conversion type as string.
string CCS::getConversionType()
{
	if(getChoice()==1)
		return ")=====Cartesian to Spherical=====> PCON(";
	if(getChoice()==2)
		return ")=====Cartesian to Cylindrical=====> PCON(";
	if(getChoice()==3)
		return ")=====Spherical to Cartesian=====> PCON(";
	if(getChoice()==4)
		return ")=====Cylindrical to Cartesian=====> PCON(";
}
