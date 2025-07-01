//yair340@gmail.com
#pragma once
#include <vector>
#include <iostream>
#include <stdexcept>

namespace MatrixLib {

    class SquareMat {
    private:
        std::vector<std::vector<double>> data;
        int size;
        double determinant(const std::vector<std::vector<double>>& mat) const;
        double sumElements() const;

    public:
        SquareMat(int n);
        SquareMat(const std::vector<std::vector<double>>& values);
        int getSize() const;

        
        std::vector<double>& operator[](int index);
        const std::vector<double>& operator[](int index) const;

        
        SquareMat operator+(const SquareMat&) const;
        SquareMat operator-(const SquareMat&) const;
        SquareMat operator-() const;
        SquareMat operator*(const SquareMat&) const;
        SquareMat operator*(double scalar) const;
        SquareMat operator%(const SquareMat&) const;
        SquareMat operator%(int scalar) const;
        SquareMat operator/(double scalar) const;
        SquareMat operator^(int power) const;

        
        SquareMat& operator+=(const SquareMat&);
        SquareMat& operator-=(const SquareMat&);
        SquareMat& operator*=(const SquareMat&);
        SquareMat& operator*=(double scalar);
        SquareMat& operator/=(double scalar);
        SquareMat& operator%=(const SquareMat&);
        SquareMat& operator%=(int scalar);

        
        SquareMat& operator++();    // pre
        SquareMat operator++(int);  // post
        SquareMat& operator--();
        SquareMat operator--(int);

        bool operator==(const SquareMat&) const;
        bool operator!=(const SquareMat&) const;
        bool operator<(const SquareMat&) const;
        bool operator<=(const SquareMat&) const;
        bool operator>(const SquareMat&) const;
        bool operator>=(const SquareMat&) const;

        
        SquareMat operator~() const;

        
        double operator!() const;

        
        friend std::ostream& operator<<(std::ostream&, const SquareMat&);
        friend SquareMat operator*(double scalar, const SquareMat& mat);

    };


}
