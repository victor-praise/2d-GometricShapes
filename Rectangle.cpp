#include "Rectangle.h"
#include <sstream>

using std::cout;
using std::endl;

//constructor
Rectangle::Rectangle(int h, int w, char pen, string name):Shape(name,pen)
{
    this->h = h;
    this->w = w;
}

//draws shape
Canvas Rectangle::draw() const
{
    Canvas can{ getHeight(), getWidth() }; //canvas object
    for (int i{}; i < getHeight(); ++i) { //loops through and inserts pen in respective row and columns
        for (int j{}; j < getWidth(); ++j) {
            can.put(i, j, getPen()); //draws shape
        }
    }
    
    return can; //returns object
}

string Rectangle::toString() const
{

    //prints shape information
    std::ostringstream output;
    Shape::toString();
    cout << "Height: " << getHeight() << endl;
    cout << "width: " << getWidth() << endl;
    cout << "Textual area: " << areaScr() << endl;
    cout << "Geometric area: " << std::fixed << std::setprecision(2) << areaGeo() << endl;
    cout << "Textual perimeter: " << preimeterScr() << endl;
    cout << "Geometric pereimeter: " << preimeterGeo() << endl;
    cout << "Static type: " << typeid(this).name() << endl;
    cout << "Dynamic type: " << typeid(*this).name() << endl;

    return output.str();
}

char Rectangle::getPen() const
{
    return Shape::getPen(); //calls shape method
}

string Rectangle::getName() const
{
    return Shape::getName();  //calls shape method
}

int Rectangle::getIdentityNumber() const
{
    return Shape::getIdentityNumber();  //calls shape method
}

void Rectangle::setPen(char pen)
{
    Shape::setPen(pen);  //calls shape method
}

void Rectangle::setName(string name)
{
    Shape::setName(name);  //calls shape method
}

int Rectangle::getHeight() const
{
    return this->h; //returns height
}

int Rectangle::getWidth() const
{
    return this->w; //returns weight
}

double Rectangle::areaGeo() const
{
    return h*w; //returns area
}

double Rectangle::preimeterGeo() const
{
    return 2*(h+w); //returns perimeter area
}

double Rectangle::areaScr() const
{
    return h*w; //returns textual area
}

double Rectangle::preimeterScr() const
{
    return 2 * (h + w)-4; //returns textual perimeter
}

ostream& operator<<(ostream& sout, const Rectangle& Rect)
{
    Rect.toString(); //calls toString

    return sout;
    
}
