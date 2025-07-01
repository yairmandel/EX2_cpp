//yair340@gmail.com
#include "SquareMat.hpp"
#include <iostream>
#include <stdexcept>
#include <cmath>

namespace MatrixLib {

//constructor by num (just frame)
SquareMat::SquareMat(int n) : size(n) {
    if (n <= 0)
        throw std::invalid_argument("Matrix size must be positive");

    data = std::vector<std::vector<double>>(n, std::vector<double>(n, 0.0));
}

//constructor by values (with vectors)
SquareMat::SquareMat(const std::vector<std::vector<double>>& values) {
    int n = values.size();

    if (n == 0)
        throw std::invalid_argument("Matrix cannot be empty");

    for (const auto& row : values) {
        if (row.size() != static_cast<size_t>(n))

            throw std::invalid_argument("Matrix must be square (same number of rows and columns)");
    }

    size = n;
    data = values;
}
int SquareMat::getSize() const{
    return size;
}

//operator[] (Matrix[i][j])
std::vector<double>& SquareMat::operator[](int index) {
    if (index < 0 || index >= size)
        throw std::out_of_range("Row index out of bounds");
    return data[index];
}

//operator[] (Matrix[i][j]) - read only
const std::vector<double>& SquareMat::operator[](int index) const {
    if (index < 0 || index >= size)
        throw std::out_of_range("Row index out of bounds");
    return data[index];
}

//A+B = C
SquareMat SquareMat::operator+(const SquareMat& other) const {
    if (size != other.size)
        throw std::invalid_argument("Cannot add matrices of different sizes");

    SquareMat result(size);  
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            result[i][j] = data[i][j] + other[i][j];
        }
    }

    return result;
}

//A-B = C
SquareMat SquareMat::operator-(const SquareMat& other) const {

    if (size != other.size)
        throw std::invalid_argument("Cannot subtract matrices of different sizes");

    SquareMat result(size);

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            result[i][j] = data[i][j] - other[i][j];
        }
    }

    return result;
}

//A = -A
SquareMat SquareMat::operator-() const {
    SquareMat result(size);

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            result[i][j] = -data[i][j];
        }
    }

    return result;
}

//A*B = C
SquareMat SquareMat::operator*(const SquareMat& other) const {
    if (size != other.size) {
        throw std::invalid_argument("Matrix sizes must match for multiplication");
    }

    SquareMat result(size);

    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            double sum = 0;
            for (int k = 0; k < size; ++k) {
                sum += data[i][k] * other[k][j];
            }
            result[i][j] = sum;
        }
    }

    return result;
}

//A*a = C
SquareMat SquareMat::operator*(double scalar) const {
    SquareMat result(size);

    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            result[i][j] = data[i][j] * scalar;
        }
    }

    return result;
}

//a*A = C
SquareMat operator*(double scalar, const SquareMat& mat) {
    return mat * scalar; 
}

//A\s = C
SquareMat SquareMat::operator/(double scalar) const {
    if (scalar == 0.0) {
        throw std::invalid_argument("Division by zero is not allowed.");
    }

    SquareMat result(size);

    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            result[i][j] = data[i][j] / scalar;
        }
    }

    return result;
}

//A[i][j] * B[i][j] = C[i][j]
SquareMat SquareMat::operator%(const SquareMat& other) const {
    if (size != other.size) {
        throw std::invalid_argument("Matrices must be the same size for element-wise multiplication");
    }

    SquareMat result(size);

    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            result[i][j] = data[i][j] * other[i][j];
        }
    }

    return result;
}

//A%a = C
SquareMat SquareMat::operator%(int scalar) const {
    if (scalar == 0) {
        throw std::invalid_argument("Modulo by zero is not allowed.");
    }

    SquareMat result(size);

    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            result[i][j] = static_cast<int>(data[i][j]) % scalar;
        }
    }

    return result;
}

//A^a = A*A*A(a times)
SquareMat SquareMat::operator^(int power) const {
    if (power < 0) {
        throw std::invalid_argument("Negative powers are not supported.");
    }

    if (power == 0) {
        SquareMat identity(size);
        for (int i = 0; i < size; ++i) {
            identity[i][i] = 1;
        }
        return identity;
    }

    SquareMat result = *this;

    for (int i = 1; i < power; ++i) {
        result = result * (*this);
    }

    return result;
}

// ++A
SquareMat& SquareMat::operator++() {
    for (int i = 0; i < size; ++i)
        for (int j = 0; j < size; ++j)
            ++data[i][j];
    return *this;
}

// A++
SquareMat SquareMat::operator++(int) {
    SquareMat temp = *this;
    ++(*this); 
    return temp;
}

// --A
SquareMat& SquareMat::operator--() {
    for (int i = 0; i < size; ++i)
        for (int j = 0; j < size; ++j)
            --data[i][j];
    return *this;
}

// A--
SquareMat SquareMat::operator--(int) {
    SquareMat temp = *this;
    --(*this);
    return temp;
}

//helper func
double SquareMat::sumElements() const {
    double sum = 0;
    for (const auto& row : data) {
        for (double val : row) {
            sum += val;
        }
    }
    return sum;
}

//A==B
bool SquareMat::operator==(const SquareMat& other) const {
    return this->sumElements() == other.sumElements();
}

//A!=B
bool SquareMat::operator!=(const SquareMat& other) const {
    return !(*this == other);
}

//A<B
bool SquareMat::operator<(const SquareMat& other) const {
    return this->sumElements() < other.sumElements();
}

//A+=B -> A=A+B
SquareMat& SquareMat::operator+=(const SquareMat& other) {
    if (size != other.size) {
        throw std::invalid_argument("Matrices must be the same size for addition");
    }

    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            data[i][j] += other.data[i][j];
        }
    }

    return *this;
}

//A-=B -> A=A-B
SquareMat& SquareMat::operator-=(const SquareMat& other) {
    if (size != other.size) {
        throw std::invalid_argument("Matrices must be the same size for subtraction");
    }

    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            data[i][j] -= other.data[i][j];
        }
    }

    return *this;
}

//A*=B -> A = A*B
SquareMat& SquareMat::operator*=(const SquareMat& other) {
    if (size != other.size) {
        throw std::invalid_argument("Matrices must be the same size for multiplication.");
    }

    SquareMat result(size);

    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            result[i][j] = 0;
            for (int k = 0; k < size; ++k) {
                result[i][j] += data[i][k] * other.data[k][j];
            }
        }
    }

    this->data = result.data;  

    return *this;
}

//A*=a -> A = A*a
SquareMat& SquareMat::operator*=(double scalar) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            data[i][j] *= scalar;
        }
    }
    return *this;
}

//A\=a -> A = A/a
SquareMat& SquareMat::operator/=(double scalar) {
    if (scalar == 0.0) {
        throw std::invalid_argument("Division by zero is not allowed.");
    }

    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            data[i][j] /= scalar;
        }
    }

    return *this;
}

//A%a -> A = A%a
SquareMat& SquareMat::operator%=(int scalar) {
    if (scalar == 0) {
        throw std::invalid_argument("Modulo by zero is not allowed.");
    }

    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            data[i][j] = static_cast<int>(data[i][j]) % scalar;
        }
    }

    return *this;
}

//A%B -> A = A[i][j] % B[i][j]
SquareMat& SquareMat::operator%=(const SquareMat& other) {
    if (size != other.size) {
        throw std::invalid_argument("Matrices must be the same size for element-wise modulo.");
    }

    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            int divisor = static_cast<int>(other.data[i][j]);
            if (divisor == 0) {
                throw std::invalid_argument("Modulo by zero in matrix element.");
            }
            data[i][j] = static_cast<int>(data[i][j]) % divisor;
        }
    }

    return *this;
}

//A>B
bool SquareMat::operator<=(const SquareMat& other) const {
    return *this < other || *this == other;
}
//A <= B
bool SquareMat::operator>(const SquareMat& other) const {
    return !(*this <= other);
}
// A >= B
bool SquareMat::operator>=(const SquareMat& other) const {
    return !(*this < other);
}

//transpose
SquareMat SquareMat::operator~() const {
    SquareMat result(size);

    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            result[i][j] = data[j][i];
        }
    }

    return result;
}


double SquareMat::determinant(const std::vector<std::vector<double>>& mat) const {
    int n = mat.size();
    if (n == 1) return mat[0][0];
    if (n == 2) return mat[0][0]*mat[1][1] - mat[0][1]*mat[1][0];

    double det = 0.0;
    for (int col = 0; col < n; ++col) {
        std::vector<std::vector<double>> subMat(n - 1, std::vector<double>(n - 1));
        for (int i = 1; i < n; ++i) {
            int sub_j = 0;
            for (int j = 0; j < n; ++j) {
                if (j == col) continue;
                subMat[i - 1][sub_j++] = mat[i][j];
            }
        }
        det += (col % 2 == 0 ? 1 : -1) * mat[0][col] * determinant(subMat);
    }
    return det;
}

//determinant
double SquareMat::operator!() const {
    return determinant(data);
}

//<<print A
std::ostream& operator<<(std::ostream& os, const SquareMat& mat) {
    for (int i = 0; i < mat.size; ++i) {
        os << "[ ";
        for (int j = 0; j < mat.size; ++j) {
            os << mat.data[i][j];
            if (j < mat.size - 1)
                os << ", ";
        }
        os << " ]\n";
    }
    return os;
}

}