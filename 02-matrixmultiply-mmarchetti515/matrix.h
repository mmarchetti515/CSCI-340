#ifndef H_MATRIX_MULTIPLY
#define H_MATRIX_MULTIPLY

#include <istream>
#include <vector>

// NOTE: Do not pollute every #includer's namespace by putting 'using' statements in header files!

class matrix
{
public:
    matrix(unsigned int rows=0, unsigned int cols=0);
    void resize(unsigned int rows, unsigned int cols);
    void load(std::istream &is);
    void print(int colWidth) const;

    // Implement both a const and non-const version of at() so can use in 
    // different contexts such as an rvalue or lvalue.
    const int & at(unsigned int row, unsigned int col) const
    {
        return mat[row][col];       // note that mat[row] returns a reference to the col vector
    }
    int & at(unsigned int row, unsigned int col)
    {
        return mat[row][col];       // note that mat[row] returns a reference to the col vector
    }

    matrix operator*(const matrix&) const;  // see CSCI 241 rational.cpp example

    // the number of roiws is the number of column vectors! 
    unsigned int getRows() const { return mat.size(); }

    // Note that if have 0 rows then we have no col vectors to ask about their size!
    unsigned int getCols() const { return (getRows()==0? 0 : mat[0].size()); }

private:

    // can't use vector<vector<int> > A(nrows, vector<int>(ncols)) notation because might 
    // not know the dimension when constructed.
    std::vector<std::vector<int>> mat;      // rows is the outer vector. be careful with the >>
};

#endif
