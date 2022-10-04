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
    return epsilonify(ret);
}

Matrix::~Matrix() {

}

Vector & Matrix::epsilonify(Vector & v)
{
    double e = 0.00001;
    if(v.x() > -e && v.x() < e) v.x() = 0;
    if(v.y() > -e && v.y() < e) v.y() = 0;
    if(v.z() > -e && v.z() < e) v.z() = 0;
    return v;
}

Matrix Matrix::Scale(const Vector & s)
{
    return Matrix({
        s.getX(), 0, 0,
        0, s.getY(), 0,
        0, 0, s.getZ()
    });
}

Matrix Matrix::Rotate(const Vector & axis, double angle)
{
    Vector a = Normalized(axis);
    double s = sin(Math::DegreeToRadian(angle));
    double c = cos(Math::DegreeToRadian(angle));
    double xx = a.x() * a.x();
    double yy = a.y() * a.y();
    double zz = a.z() * a.z();

    double xy = a.x() * a.y();
    double xz = a.x() * a.z();
    double yz = a.y() * a.z();

    double xs = a.x() * s;
    double ys = a.y() * s;
    double zs = a.z() * s;

    double cb = 1.0 - c;

    return Matrix({
        xx * cb +  c, xy * cb - zs, xz * cb + ys,
        xy * cb + zs, yy * cb +  c, yz * cb - xs,
        xz * cb - ys, yz * cb + xs, zz * cb +  c,
    });
}

Matrix Matrix::Transpose() const
{
    return Matrix({
        (*this)(0, 0), (*this)(0, 1), (*this)(0, 2),
        (*this)(1, 0), (*this)(1, 1), (*this)(1, 2),
        (*this)(2, 0), (*this)(2, 1), (*this)(2, 2)
    });
}

Matrix Matrix::RotateX(double angle)
{
    double s = sin(Math::DegreeToRadian(angle));
    double c = cos(Math::DegreeToRadian(angle));
    return Matrix({
        1.0, 0.0, 0.0,
        0.0, c, -s,
        0.0, s, c
    });
}

Matrix Matrix::RotateY(double angle)
{
    double s = sin(Math::DegreeToRadian(angle));
    double c = cos(Math::DegreeToRadian(angle));
    return Matrix({
        c, 0.0, -s,
        0.0, 1.0, 0.0,
        s, 0.0, c
    });
}

Matrix Matrix::RotateZ(double angle)
{
    double s = sin(Math::DegreeToRadian(angle));
    double c = cos(Math::DegreeToRadian(angle));
    return Matrix({
        c, -s, 0.0,
        s, c, 0.0,
        0.0, 0.0, 1.0
    });
}