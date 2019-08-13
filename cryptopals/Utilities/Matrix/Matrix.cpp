#include "Matrix.h"
#include <cassert>
#include <iostream>
#include <math.h>

// Matrix constructor
Matrix::Matrix(int height, int width)
{
	assert(width > 0 && height > 0 && "Matrix dimensions must be at least 1.");

	m_width = width;
	m_height = height;
	m_data = new char(m_width*m_height);
}

// Setter function to set the value of a matrix element
void Matrix::setElem(int row, int col, char val) 
{ 
	// Bounds checking
	assert(row < m_height
		&& col < m_width
		&& "Row or column index exceeds matrix dimenions");

	// Set the value
	m_data[row*m_width + col] = val; 
	
	return; 
}

// Another setter function - you can set by element number instead of r/c
void Matrix::setElem(int elemNum, char val)
{
	// Bounds checking
	assert(elemNum < m_width * m_height
		&& "Element number given exceeds capacity of matrix "
		&& "(beware zero-indexed).");

	// Set the value
	int row = floor(elemNum / (double) m_width);
	int col = elemNum % m_width;
	m_data[row, col] = val;
}

// Getter function to get the value of a matrix element
char Matrix::getElem(int row, int col) 
{
	// Bounds checking
	assert(row < m_height
		&& col < m_width
		&& "Row or column index exceeds matrix dimenions");

	return m_data[row*m_width + col];
}

// Getter functions for the width and height
int Matrix::getWidth() { return m_width; }
int Matrix::getHeight() { return m_height; }
