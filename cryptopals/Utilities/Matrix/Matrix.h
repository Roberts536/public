#ifndef DATE_H
#define DATE_H

#include <cassert>
#include <iostream>

class Matrix
{
private:
	char* m_data;
	int m_width;
	int m_height;

public:
	// Constructor
	Matrix(int height = 1, int width = 1);

	// Getter and setter functions
	void setElem(int row, int col, char val);
	void setElem(int elemNum, char val);
	char getElem(int row, int col);
	int getHeight();
	int getWidth();

};

#endif