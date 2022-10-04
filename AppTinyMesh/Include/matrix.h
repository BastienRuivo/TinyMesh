#pragma once
#include <array>
#include <iostream>
#include "mathematics.h"
#include <math.h>


class Matrix
{
private:
    /* data */
public:
    std::array<double, 9> mArray;
    int dimension = 3;
    Matrix();
    static Vector& epsilonify(Vector & v);
    Matrix(const Matrix & neo);
    Matrix(const std::array<double, 9> & array);
    ~Matrix();

    int getId(const int & x, const int & y) const;

    static Matrix Rotate(const Vector & axis, double angle);
    static Matrix RotateX(double angle);
    static Matrix RotateY(double angle);
    static Matrix RotateZ(double angle);
    static Matrix Scale(const Vector & axis);

    Matrix operator!() const;
    Matrix operator=(const Matrix & neo) const;
    Matrix operator+(const Matrix & neo) const;
    Matrix operator-(const Matrix & neo) const;
    Matrix operator*(const double & factor) const;
    Matrix operator*(const Matrix & neo) const;
    double operator()(int x, int y) const;
    Vector operator*(const Vector & vec) const;
    Matrix operator/(const double & factor) const;
    Matrix Transpose() const;
    friend std::ostream& operator<<(std::ostream& os, const Matrix & m) {
        for (int y = 0; y < m.dimension; y++)
        {
            for (int x = 0; x < m.dimension; x++)
            {
                if(std::signbit(m(x, y))) os<<m(x, y)<<" ";
                else os<<" "<<m(x, y)<<" ";
            }
            os<<std::endl;
        }
        return os;
    }
};