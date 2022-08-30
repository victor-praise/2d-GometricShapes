#include "Canvas.h"
#include <iostream>

using std::endl;
using std::cout;

bool Canvas::check(int r, int c) const
{

	if (r >= getRows() || c >= getColumns()) return false; //returns false if out of bounds

	return true;
}

void Canvas::resize(size_t rows, size_t cols)
{
}

//constructor
Canvas::Canvas(int rows, int columns, char fillChar):grid{ rows, vector<char>(columns, fillChar) }
{
}

//returns number of rows
int Canvas::getRows() const
{
	return grid.size();
}

//returns number of columns
int Canvas::getColumns() const
{
	return  grid[0].size();;
}

//flips horizontally
Canvas Canvas::flip_horizontal() const
{
	Canvas can{ getRows(), getColumns()}; //creates canvas object
	can.grid = this->grid; //copys calling object vector to can
	

	for (int i{}; i <= can.grid.size() - 1; i++) {
		int j{};
		int k = can.getColumns() - 1;

		while (j < k) {
			char temp = can.grid[i][j]; 
			can.grid[i][j] = can.grid[i][k]; //swaps values of last column value with first column value, 
			can.grid[i][k] = temp;			//second value woth second to last value and keeps swapping till it gets to middle
			j++; 
			k--; //decrements k
		}
	}
	return can; //returns can
}

Canvas Canvas::flip_vertical() const
{
	Canvas can{ getRows(), getColumns() }; //creates canvas object

	can.grid = this->grid; //copys calling object vector to can

	for (int i{}; i < can.getColumns() - 1; i++) {
		int j{};
		int k = can.getRows() - 1;
		while (j < k) {
			char temp = can.grid[j][i];
			can.grid[j][i] = can.grid[k][i]; //swaps values of last row value with first row value, 
			can.grid[k][i] = temp;			 //second value woth second to last value and keeps swapping till it gets to middle
			j++;
			k--; //decrements k
		}
	}
	return can;
}


//prints vector
void Canvas::print(ostream& out) const
{
	for (int i = 0; i < grid.size(); i++) //loops through and adds to grid
	{
		for (int j = 0; j < grid[i].size(); j++)
		{
			out << grid[i][j];
		}
		out << endl;
	}
}

//returns specific row and column
char Canvas::get(int r, int c) const
{

	return grid[r][c];
}

//puts into specific row and colunm
void Canvas::put(int r, int c, char ch)
{
	if (check(r, c)) { //ensures r and c are valid then adds to grid
		grid[r][c] = ch;
	}
	
}

//draws string on matrix
void Canvas::drawString(int r, int c, const std::string text)
{
	int column = c;

	for (int i{}; i < text.length(); i++) {
		this->grid[r][column] = text[i]; //loop through string and add to grid char by char
		column++;
	}
}

void Canvas::overlap(const Canvas& can, size_t r, size_t c)
{
	
	for (int i{}; i < can.getRows(); i++) {
		for (int j{}; j < can.getColumns(); j++) {

			if (can.check(i, j)) {
				size_t row{ i + r };

				size_t col{ j + c };

				if (this->check(row, col)) // clip out anything that lands outside the ‘this’ canvas

				{

					this->put(row, col, can.grid[i][j]);

				}
			}
		
				
					
		}
		
		
	}
}

//calls print
ostream& operator<<(ostream& sout, const Canvas& can)
{
	can.print(sout);
	return sout;
}
