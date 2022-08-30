#include "RightTriangle.h"
#include <sstream>

using std::cout;
using std::endl;

//constructor
RightTriangle::RightTriangle(int b, char pen, string name):Triangle(b,pen,name)
{
    this->b = b;
    this->h = b;
}

Canvas RightTriangle::draw() const
{
    Canvas can{ getHeight(), getWidth() }; //creates a canvas object
  
    int width = getWidth() - 1; //get width minus 1

    for (int i{}; i < getHeight(); ++i) {
        if (width >= 0) {
            int column = getWidth() - width; //determines how pen character is placed, 16-15,16-14,16-13.......
            for (int j{}; j < column; ++j) { //draws right angle triangle
               
                can.put(i, j, getPen()); //puts pen in appropriate row and column
            }
         
            width -= 1; //decreases width by 1, makes column in next iteration increase by 1
        }
     
        
    }
    return can;
}

string RightTriangle::toString() const
{
    //prints shape info
    std::ostringstream output;
    Triangle::toString();
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

//returns pen char
char RightTriangle::getPen() const
{
    return Triangle::getPen();
}

//returns shape name
string RightTriangle::getName() const
{
    return Triangle::getName();
}

//returns identity number
int RightTriangle::getIdentityNumber() const
{
    return Triangle::getIdentityNumber();
}

//sets pen character
void RightTriangle::setPen(char pen)
{
    //calls base class method
    return Triangle::setPen(pen);
}

//sets pen char
void RightTriangle::setName(string name)
{
    //calls base class method
    return Triangle::setName(name);
}

//gets height of shape
int RightTriangle::getHeight() const
{

    return this->h;
}
//gets width of shape
int RightTriangle::getWidth() const
{
    return this->b;
}

//returns geometric area
double RightTriangle::areaGeo() const
{
    return (this->h*this->b)/2;
}

//returns geometric perimeter
double RightTriangle::preimeterGeo() const
{
    return (2+sqrt(2))*this->h;
}

//returns textual area
double RightTriangle::areaScr() const
{
    return (this->h*(this->h+1))/2;
}

//returns textural perimeter
double RightTriangle::preimeterScr() const
{
    return 3*(this->h-1);
}

ostream& operator<<(ostream& sout, const RightTriangle& Rect)
{
    //calls toString
    Rect.toString();

    return sout;
   
}
