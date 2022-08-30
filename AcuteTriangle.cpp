#include "AcuteTriangle.h"
#include <sstream>

using std::cout;
using std::endl;


AcuteTriangle::AcuteTriangle(int b, char pen, string name):Triangle(b,pen,name)
{
    b % 2 != 0 ? this->b = b : this->b = b + 1;

    this->h = (b + 1) / 2;
}

Canvas AcuteTriangle::draw() const
{
    Canvas can{ getHeight(), getWidth() };
    int col = getWidth() - 1;
    
    int middle = ceil(getWidth() / 2);
    for (int i{}; i < getHeight(); ++i) {


        if (col >= 0) { //draws acute triangle
            int column = getWidth() - col;
            int h = middle;
            for (int j{}; j < column; ++j) {
                if (middle >= 0) {

                    can.put(i, h, getPen());
                    h++;
                }

            }
            middle -= 1;
            col -= 2;
        }
           

        
   

    }
    return can; //returns canvas
}

string AcuteTriangle::toString() const
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

char AcuteTriangle::getPen() const
{
    return Triangle::getPen();  //calls triangle method which calls shape method
}

string AcuteTriangle::getName() const
{
    return Triangle::getName(); //calls triangle method which calls shape method
}

int AcuteTriangle::getIdentityNumber() const
{
    return Triangle::getIdentityNumber(); //calls triangle method which calls shape method
}

void AcuteTriangle::setPen(char pen)
{
    Triangle::setPen(pen); //calls triangle method which calls shape method
}

void AcuteTriangle::setName(string name)
{
    Triangle::setName(name); //calls triangle method which calls shape method
}

int AcuteTriangle::getHeight() const
{
    return this->h; //returns height
}

int AcuteTriangle::getWidth() const
{
    return this->b; //returns width
}

double AcuteTriangle::areaGeo() const
{
    double reseult = h*b;
   
    return reseult / 2; //returns geometric area
}

double AcuteTriangle::preimeterGeo() const
{
    double root = sqrt(pow(this->b, 2) + 4 * pow(this->h, 2));
    return this->b + root ; //returns pgeometric perimeter
}

double AcuteTriangle::areaScr() const
{
    return pow(this->h,2); //returns textual area
}

double AcuteTriangle::preimeterScr() const
{
    return 4*(this->h-1); //returns textual perimeter
}

ostream& operator<<(ostream& sout, const AcuteTriangle& acute)
{
    acute.toString(); //calls to string
    return sout;
    
}