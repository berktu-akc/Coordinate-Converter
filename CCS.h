/*! \mainpage My Personal Index Page
 *
 * \section intro_sec Introduction
 *
 * In this project, define CCS Class with using UML diagram 
 *
 * \section install_sec Installation
 *
 * \subsection step1 UML Diagram of CCS
 * 
 *
 * etc...
 */
/********************************************//**
 *  CCS Class header
 ***********************************************/

#ifndef CCS_H
#define CCS_H

#include <iostream>
#include <string>

using namespace std;

/// The class for convert coordinates type each other
///
/// Details...

class CCS
{
	public:
		/// Constructor function of CCS Class which receives double and int members.
		CCS(double a, double b, double c, double d, double e, double f, int g);
		/// Function prints "Enter" message, prompts coordinates from user and sets coordinates with set functions.
		void setCoordinates();
		/// Function for set first coordinate of chosen type.
		void setCs1_item1(double a);
		/// Function for set second coordinate of chosen type.
		void setCs1_item2(double a);
		/// Function for set third coordinate of chosen type.
		void setCs1_item3(double a);
		/// Function for set first coordinate of converted type.
		void setCs2_item1(double a);
		/// Function for set second coordinate of converted type.
		void setCs2_item2(double a);
		/// Function for set third coordinate of converted type.
		void setCs2_item3(double a);
		/// Function for set choice number which is entered from user.
		void setChoice(int a);
		/// Function for get first coordinate of chosen type.
		double getCs1_item1();
		/// Function for get second coordinate of chosen type.
		double getCs1_item2();
		/// Function for get third coordinate of chosen type.
		double getCs1_item3();
		/// Function for get first coordinate of converted type.
		double getCs2_item1();
		/// Function for get second coordinate of converted type.
		double getCs2_item2();
		/// Function for get third coordinate of converted type.
		double getCs2_item3();
		/// Function for get choice number which is entered from user.
		int getChoice();
		/// Function for print a menu for choosing type, prompt choice number from user.
		void printMenu();
		/// Function for print coordinates, chosen type and converted coordinates.
		void printCoordinates();
	private:
		/// First double type data member of chosen coordinate
		double cs1_item1;
		/// Second double type data member of chosen coordinate
		double cs1_item2;
		/// Third double type data member of chosen coordinate
		double cs1_item3;
		/// First double type data member of converted coordinate
		double cs2_item1;
		/// Second double type data member of converted coordinate
		double cs2_item2;
		/// Third double type data member of converted coordinate
		double cs2_item3;
		/// Integer type data member of choice which is entered from user.
		int choice ;
		/// A string type data member which receives conversion type.
		string conversionType;
		
		/// Function for convert coordinates cartesian to spherical.
		void carToSph();
		/// Function for convert coordinates cartesian to cylindircal.
		void carToCyl();
		/// Function for convert coordinates spherical to cartesian.
		void sphToCar();
		/// Function for convert coordinates cylindircal to cartesian.
		void cylToCar();
		/// Function for get radian angle from degree angle.
		double getRadianFromDegree(double a);
		/// Function for get degree angle from radian angle.
		double getDegreeFromRadian(double a);
		/// Funtion for get conversion type according to choice of user.
		string getConversionType();
};

#endif
