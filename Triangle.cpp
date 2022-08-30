#include "Triangle.h"
#include <sstream>

using std::cout;
using std::endl;

Triangle::Triangle(double b, char pen, string name) :Shape(name, pen)
{
	this->b = b;

}

Canvas Triangle::draw() const
{
	return Canvas();
}

string Triangle::toString() const
{
	std::ostringstream output;
	Shape::toString();
	return output.str();
}

char Triangle::getPen() const
{
	return Shape::getPen();
}

string Triangle::getName() const
{
	return Shape::getName();
}

int Triangle::getIdentityNumber() const
{
	return Shape::getIdentityNumber();
}

void Triangle::setPen(char pen)
{
	Shape::setPen(pen);
}

void Triangle::setName(string name)
{
	Shape::setName(name);
}
