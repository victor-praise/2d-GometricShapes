#include "Rhombus.h"
#include <sstream>

using std::cout;
using std::endl;

//constuctor
Rhombus::Rhombus(int d, char pen, string name):Shape(name,pen)
{
	d % 2 != 0 ? this->d = d : this->d = d + 1;
}

Canvas Rhombus::draw() const
{
	Canvas can{ getHeight(), getWidth() }; // creates canvas object
	int width = getWidth() - 1;
	int newwidth = getWidth()-2;
	int middle = ceil(getWidth() / 2);
	
	for (int i{}; i < getHeight(); ++i) {
		
		if (width >= 0) { //top half of diamond
			int column = getWidth() - width;
			int h = middle;
			for (int j{}; j < column; ++j) {
				if (middle >= 0) {
				
					can.put(i, h, getPen());
					h++;
				}
				
			}
			middle -= 1;
			width -= 2;
		
		}
		else { //bottom hafl of diamond
			int b = middle + 2;
			
			for (int j{}; j < newwidth; ++j) {
				can.put(i, b, getPen());
				b++;
				
			}
			newwidth -= 2;
			middle += 1;
		
		}
	
	}
	return can; //returns object
}

string Rhombus::toString() const
{
	//prints shape info
	std::ostringstream output;
	Shape::toString();
	cout << "Height: " << getHeight() << endl;
	cout << "width: " << getWidth() << endl;
	cout << "Textual area: " << areaScr() << endl;
	cout << "Geometric area: " << std::fixed <<std::setprecision(2) << areaGeo()<< endl;
	cout << "Textual perimeter: " << preimeterScr() << endl;
	cout << "Geometric pereimeter: "<<preimeterGeo() << endl;
	cout << "Static type: " << typeid(this).name() << endl;
	cout << "Dynamic type: " << typeid(*this).name() << endl;

	return output.str();
}

char Rhombus::getPen() const
{
	return Shape::getPen();  //calls shape method
}

string Rhombus::getName() const
{
	return Shape::getName();  //calls shape method
}

int Rhombus::getIdentityNumber() const
{
	return Shape::getIdentityNumber();  //calls shape method
}

void Rhombus::setPen(char pen)
{
	Shape::setPen(pen);  //calls shape method
}

void Rhombus::setName(string name)
{
	Shape::setName(name);  //calls shape method
}

int Rhombus::getHeight() const
{
	return this->d; //returns height
}

int Rhombus::getWidth() const
{
	return this->d; //returns width
}

double Rhombus::areaGeo() const
{
	//returns geometric area
	return pow(d, 2) / 2;
}

double Rhombus::preimeterGeo() const
{
	double squared = std::sqrt(2);
	
	return (2 * squared) * this->d; //returns geometric perimeter
}

double Rhombus::areaScr() const
{
	double n = ceil(this->d / 2);

	//returns textual area
	return 2 * n * (n + 1) + 1;
}

double Rhombus::preimeterScr() const
{
	double n = ceil(this->d / 2);

	return 2*(this->d-1); //returns textual perimeter
}

ostream& operator<<(ostream& sout, const Rhombus& Rhom)
{
	//calls toString
	Rhom.toString();
	return sout;
	
}
