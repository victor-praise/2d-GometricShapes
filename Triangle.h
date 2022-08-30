#pragma once
#include "Shape.h"
#include <cmath>
#include <iostream>
#include <typeinfo>
#include <iomanip> 

class Triangle:public Shape {
private:
	double b;
public:
	Triangle(double b, char pen = '*', string name = "Triangle"); //constuctor
	Canvas draw() const override; //overiided method
	string toString() const override; //prints shape info
	char getPen() const override; //gets pen
	string getName() const override; //gets name
	int getIdentityNumber() const override; //gets id
	void setPen(char pen) override; //sets pen
	void setName(string name) override; //sets name
	
};