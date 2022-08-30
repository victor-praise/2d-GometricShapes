#pragma once
#include "Shape.h"
#include <cmath>
#include <iostream>
#include <typeinfo>
#include <iomanip> 

class Rhombus :public Shape {
private:
	int d;
public:
	Rhombus(int d, char pen = '*', string name = "Rhombus"); //constructor
	Canvas draw() const override; //drwas shape
	string toString() const override; //prints info
	char getPen() const override; //gets pen
	string getName() const override; //gets pen
	int getIdentityNumber() const override; //gets id
	void setPen(char pen) override; //sets pen
	void setName(string name) override; //sets name
	int getHeight() const; //returns height
	int getWidth() const; //returns weight
	double areaGeo() const; //calculates geometric area
	double preimeterGeo() const; //calculates geometric perimeter
	double areaScr() const; //calculates textual area
	double preimeterScr() const; //calculates textual perimeter
};

//overloaded << operator
ostream& operator<< (ostream& sout, const Rhombus& Rhom);