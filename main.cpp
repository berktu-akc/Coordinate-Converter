#include <iostream>
#include "CCS.h"


int main(int argc, char** argv) {
	
	CCS myCCS(0.0,0.0,0.0,0.0,0.0,0.0,0);
	
	
	myCCS.printMenu();
	myCCS.setCoordinates();
	myCCS.printCoordinates();
	
	return 0;
}
