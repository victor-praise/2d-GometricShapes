#pragma once

#include <iostream>
#include <string>
#include "Canvas.h"

using std::string;
using std::ostream;

class Shape {

private:
	string name;
	char pen;
	 static int identity_number;

public:

	Shape(string name, char pen); //constructor
	virtual ~Shape(); //destructor
	virtual Canvas draw() const = 0; //draw
	virtual string toString() const; //prints shape info
	virtual char getPen() const; //gets pen
	virtual string getName() const; //gets name
	virtual int getIdentityNumber() const; //gets identity number
	virtual void setPen(char pen); //sets pen
	virtual void setName(string name); //sets name

};
//overloaded operator
ostream& operator<< (ostream& sout, const Shape& shap);