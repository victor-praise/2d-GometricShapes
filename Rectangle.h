#pragma once
#include "Shape.h"
#include <cmath>
#include <iostream>
#include <typeinfo>
#include <iomanip> 

class Rectangle:public Shape {
private:
	int h;
	int w;
public:
	Rectangle(int h, int w, char pen = '*', string name = "Rectangle"); //constructor
	Canvas draw() const override; //canvas object
	string toString() const override; //prints info
	char getPen() const override; //gets pen
	string getName() const override; //gets name
	int getIdentityNumber() const override; //gets id
	void setPen(char pen) override; //sets number
	void setName(string name) override; //sets name
	int getHeight() const; //returns height
	int getWidth() const; //returns width
	double areaGeo() const; // calculates geometric area
	double preimeterGeo() const; //calculates geometric perimeter
	double areaScr() const; //calculates textual area
	double preimeterScr() const; //calculates textual perimeter
};
ostream& operator<< (ostream& sout, const Rectangle& Rect);