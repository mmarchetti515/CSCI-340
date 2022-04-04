/*	Michael Marchetti
 *	z1860574
 *	CSCI 340 Data Struct Algorithm Analysis
 *	Class # 1737-Section 0002-Component LEC
 *
 *	I certify that this is my own work and where appropriate an extension
 *	of the starter code provided for the assignment.
 *
 *  Assignment 2
 */

#include <iostream>
#include <cmath>
#include <fstream>
#include <iomanip>
#include <cassert>

#include "matrix.h" 

using namespace std;

/**
 * @brief Construct a new matrix::matrix object
 * Initializes the matrix class, and uses the resize method
 * to initialize the matrix size using rows and cols
 * 
 * @param rows the rows of the matrix
 * @param cols the columns of the matrix
 */
matrix::matrix(unsigned int rows, unsigned int cols)
{
    resize(rows, cols);
}

/**
 * @brief Resize the mat vector to have rows elements and then resize 
 * each of those elements (which are vectors themselves) to have cols elements.
 * This function will also call the resize method from the stl
 * 
 * @param rows 
 * @param cols 
 */
void matrix::resize(unsigned int rows, unsigned int cols)
{
    mat.resize(rows); // this is a call of the resize method from the stl

    for (unsigned int i = 0; i < rows; i++) // this for loop will iterate through the rows of mat
    {
        mat[i].resize(cols); // another call of the stl resize method
    }

}

/**
 * @brief Read the input values from the given input stream (is) and store them 
 * into the 2D matrix (mat). Num row and col are pair of values at top of file.
 * Then calls resize method to properly dimension the matrix, and set the values 
 * using the extraction operator (>>) and the matrix:at() accessor.
 * 
 * @param is 
 */
void matrix::load(istream &is)
{
    unsigned int row, col; // 

    is >> row;
    is >> col;

    resize(row, col); // call resize to properly dimension matrix

    for (unsigned int i=0; i<row; i++) // this will iterate through the rows of mat
    {
        for (unsigned int j=0; j<col; j++) // this will iterate through the cols of mat
        {
            is >> at(i, j); // use of the at accessor and >> operator allow the values to be set 
                            // as the loop iterates through the mat
        }
    }
}

/**
 * @brief Print method will format and display matrices to the console. Certain elements
 * can be easiy dynamically changed while others require more work, but the formatting 
 * is not set.
 * 
 * @param colWidth 
 */
void matrix::print(int colWidth) const
{
    colWidth = 11; // set column width for formatting, can be dynamically changed, but
                   // the dashed header and footer will not change
    cout << getRows() << " x " << getCols() << "\n\n";

    /**
     * used number of columns to determine how many times to print the dashed header
     */
    for(unsigned int i=0; i < getCols(); i++)
    {
        cout << "-------------";
    }
    cout << "-\n";
    /**
     * for loop iterates through the rows
     */
    for(unsigned int i=0; i < getRows(); i++)
    {
        /**
         * for loop iterates through columns 
         */
        for(unsigned int j=0; j < getCols(); j++)
        {
            cout << "|" << setw(colWidth) << at(i,j) << " "; // formatting and separation of cells in table
        }
        cout << "|\n"; // end of row
    }
    /**
     * used number of columns to determine how many times to print the dashed footer
     */
    for(unsigned int i=0; i < getCols(); i++)
    {
        cout << "-------------";
    }
    cout << "-\n"; // needed for formatting
}

/**
 * @brief Implements multiplication operator overloading using 
 * 
 * @param rhs 
 * @return matrix 
 */
matrix matrix::operator*(const matrix &rhs) const
{
    /**
     * @brief lines 138-141 will retrieve the row and column dimensions to be stored in a
     * temporary matrix named result, which is prepared to be printed when the print function
     * is called. This pointer retrieves for the lhs or left hand side, while * used for 
     * the rhs or right hand side. 
     */
    unsigned int lhs_c = (*this).getCols(); 
    unsigned int lhs_r = (*this).getRows();
    unsigned int rhs_c = rhs.getCols();
    unsigned int rhs_r = rhs.getRows();

    assert(lhs_c == rhs_r); // assert() for error checking compatible dimensions

    matrix result(lhs_r, rhs_c); // store the lhs and rhs in the result matrix

    for(unsigned int i = 0; i < lhs_r; i++) // iterate through the lhs
    {
        for(unsigned int j = 0; j < rhs_c; j++) // iterate through the rhs
        {
            for(unsigned int k = 0; k < lhs_c; k++) // iterate through the lhs columns
            {
                result.at(i,j) += (*this).at(i,k) * rhs.at(k,j); // use the at accessor
                // to store the results of the function in the result matrix, function
                // is performed to multiply the matrices
            }
        }
    }
    return result;
}