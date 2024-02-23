//============================================================================
// Name        : Exam.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
#include "ResisterPart.h"
#include "ResisterConnection.h"
#include "SeriesConnection.h"
#include "ParallelResister.h"

#include <memory>

int main() {

	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!

	ResisterPart R1("R1",1000, 5);
	cout<<R1.toString()<<endl;
///////////////////////////////////////////////////////

	SeriesConnection R2("R2");

	ResisterPart res3("R3",1000, 10);
	ResisterPart res4("R4",4700, 10);
	shared_ptr<Resister> R3 = make_shared<ResisterPart>(res3);
	shared_ptr<Resister> R4 = make_shared<ResisterPart>(res4);
	R2+=R3;
	R2+=R4;
	cout<<R2.toString()<<endl;
/////////////////////////////////////////////////
	ParallelResister R5("R5");

	ResisterPart res6("R6",1000, 10);
	ResisterPart res7("R7",4700, 10);
	shared_ptr<Resister> R6 = make_shared<ResisterPart>(res6);
	shared_ptr<Resister> R7 = make_shared<ResisterPart>(res7);
	R5+=R6;
	R5+=R7;
	cout<<R5.toString();
	return 0;
}
