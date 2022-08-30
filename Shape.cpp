#include "Shape.h"
#include <iostream>
#include <sstream>

using std::cout;
using std::endl;

ostream& operator<<(ostream& sout, const Shape& shap)
{
	shap.toString(); //calls to string 

	return sout;
	
}

Shape::Shape(string name, char pen):name{name},pen{pen}
{
	identity_number++; //increments identity number
}

Canvas Shape::draw() const
{
	return Canvas();
}

Shape::~Shape()
{
	identity_number--; //decrements id 
}

string Shape::toString() const
{ //prints shape info
	std::ostringstream output;
	cout << "Shape Information" << endl;
	cout << "-----------------" << endl;
	cout << "id: " << getIdentityNumber() << endl;
	cout << "Shape name: " << getName() << endl;
	cout << "Pen character: " << getPen() << endl;
	return output.str();
}

char Shape::getPen() const
{
	return this->pen; //returns pen
}

string Shape::getName() const
{
	return this->name; //returns name
}

int Shape::getIdentityNumber() const
{
	return this->identity_number; //returns id
}

void Shape::setPen(char pen)
{
	this->pen = pen; //sets pen
}

void Shape::setName(string name)
{
	this->name = name; //sets name
}


