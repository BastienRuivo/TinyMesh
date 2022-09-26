#include "matrix.h"

Matrix::Matrix() 
{

}

Matrix::Matrix(const std::array<double, 9>& array) {
    for (int j = 0; j < dimension; j++)
    {
        for (int i = 0; i < dimension; i++)
        {
            mArray[getId(i, j)] = array[j * dimension + i];
        }
        
    }
    
}

Matrix::Matrix(const Matrix & other) {
    for (int j = 0; j < dimension; j++)
    {
        for (int i = 0; i < dimension; i++)
        {
            mArray[getId(i, j)] = other(i, j);
        }
        
    }
    
}

int Matrix::getId(const int & x, const int & y) const
{
    return y * dimension + x;
}

double Matrix::operator()(int x, int y) const 
{
    return mArray[y * dimension + x];
}

Matrix Matrix::operator+(const Matrix & other) const
{
    Matrix ret;
    for(int y = 0; y < dimension; y++)
        for(int x = 0; x < dimension; x++) {
            ret.mArray[ret.getId(x, y)] = (*this)(x, y) + other(x, y);
        }
    return ret;
}

Matrix Matrix::operator-(const Matrix & other) const
{
    Matrix ret;
    for(int y = 0; y < dimension; y++)
        for(int x = 0; x < dimension; x++) {
            ret.mArray[ret.getId(x, y)] = (*this)(x, y) - other(x, y);
        }
    return ret;
}

Matrix Matrix::operator*(const double & factor) const
{
    Matrix ret;
    for(int y = 0; y < dimension; y++)
        for(int x = 0; x < dimension; x++) {
            ret.mArray[ret.getId(x, y)] = (*this)(x, y) * factor;
        }
    return ret;
}

Matrix Matrix::operator/(const double & factor) const
{
    Matrix ret;
    for(int y = 0; y < dimension; y++)
        for(int x = 0; x < dimension; x++) {
            ret.mArray[ret.getId(x, y)] = (*this)(x, y) / factor;
        }
    return ret;
}

Matrix Matrix::operator*(const Matrix & other) const 
{
    Matrix ret;
    for(int y = 0; y < dimension; y++)
        for(int x = 0; x < dimension; x++) {
            double val = 0;
            for(int s = 0; s < dimension; s++) {
                val += (*this)(s, y) * other(x, s);
            }
            ret.mArray[ret.getId(x, y)] = val;
        }
    return ret;
}


Matrix Matrix::operator!() const
{
    Matrix ret;
    double determinant = 0;
    for(int i = 0; i < dimension; i++) {
        determinant +=  (*this)(i, 0) * 
                        (*this)((i + 1) % dimension, 1) *
                        (*this)((i + 2) % dimension, 2) -
                        (*this)((i + 2) % dimension, 0) *
                        (*this)((i + 1) % dimension, 1) *
                        (*this)(i, 2);
    }

    for (int y = 0; y < dimension; y++)
    {
        for (int x = 0; x < dimension; x++)
        {
            ret.mArray[ret.getId(x, y)] = (((*this)((y+1)%3, (x+1)%3) *
                                     (*this)((y+2)%3, (x+2)%3)) - 
                                    ((*this)((y+1)%3, (x+2)%3) *
                                     (*this)((y+2)%3, (x+1)%3))) / determinant;
        }
    }
    return ret;
}

Vector Matrix::operator*(const Vector & other) const
{
    Vector ret;
    for (int y = 0; y < dimension; y++)
    {
        ret[y] = 0;
        for (int i = 0; i < dimension; i++)
        {
            ret[y] += (*this)(i, y) * other[i];
        }
    }
    return ret;
}

Matrix::~Matrix() {

}

