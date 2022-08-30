#pragma once
#include <cmath>
#include <iostream>
#include <typeinfo>
#include <iomanip> 
#include "Triangle.h"

class AcuteTriangle: public Triangle {
private:
	double h;
	double b;
public:
	AcuteTriangle(int b, char pen = '*', string name = "wedge"); //constuctor
	Canvas draw() const override; //draws shape
	string toString() const override; //prints shape info
	char getPen() const override; //gets pen
	string getName() const override;//gets name
	int getIdentityNumber() const override; //gets id
	void setPen(char pen) override; //sets pen
	void setName(string name) override; //sets name
	int getHeight() const; //returns height
	int getWidth() const; //returns width
	double areaGeo() const; //returns geometric area
	double preimeterGeo() const; //returns geometric perimeter
	double areaScr() const; //returns textual area
	double preimeterScr() const; //returns textual perimeter
};

//overloaded << operator
ostream& operator<< (ostream& sout, const AcuteTriangle& acute);