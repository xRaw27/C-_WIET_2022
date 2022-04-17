#include <iostream>
#include <string>

using namespace std;

#include "matrix.h"

TwoDimensionMatrix::TwoDimensionMatrix(const TwoDimensionMatrix &m) {
    for (size_t i = 0; i < size; ++i) {
        for (size_t j = 0; j < size; ++j) {
            matrix[i][j] = m[i][j];
        }
    }
}

TwoDimensionMatrix::TwoDimensionMatrix(const MatrixElement m [size][size]) {
    for (size_t i = 0; i < size; ++i) {
        for (size_t j = 0; j < size; ++j) {
            matrix[i][j] = m[i][j];
        }
    }
}

MatrixElement *TwoDimensionMatrix::operator[](size_t index) {
    return matrix[index];
}

const MatrixElement *TwoDimensionMatrix::operator[](size_t index) const {
    return matrix[index];
}

TwoDimensionMatrix &TwoDimensionMatrix::operator=(const TwoDimensionMatrix &m) {
    if (&m != this) {
        for (size_t i = 0; i < size; ++i) {
            for (size_t j = 0; j < size; ++j) {
                matrix[i][j] = m[i][j];
            }
        }
    }
    return *this;
}

TwoDimensionMatrix &TwoDimensionMatrix::operator*=(MatrixElement number) {
    for (auto & row : matrix) {
        for (MatrixElement & elem : row) {
            elem *= number;
        }
    }

    return *this;
}

TwoDimensionMatrix TwoDimensionMatrix::operator&&(const TwoDimensionMatrix &m) const {
    TwoDimensionMatrix matrix_and;

    for (size_t i = 0; i < size; ++i) {
        for (size_t j = 0; j < size; ++j) {
            matrix_and[i][j] = matrix[i][j] && m[i][j];
        }
    }

    return matrix_and;
}

TwoDimensionMatrix::operator size_t() const {
    return getSize();
}

ostream &operator<<(ostream &os, const TwoDimensionMatrix &m) {
    for (size_t i = 0; i < 2; ++i) {
        os << "{ ";
        for (size_t j = 0; j < 2; ++j) {
            os << m.get(i, j) << ", ";
        }
        os << "}\n";
    }
    return os;
}

istream &operator>>(istream &is, TwoDimensionMatrix &m) {
    const size_t size = TwoDimensionMatrix::getSize();
    char buffer[50 * size];
    size_t pos;

    for (size_t i = 0; i < size; ++i) {
        is.getline(buffer, 50 * size);
        string str(buffer);

        if (buffer[0] == '{' || buffer[0] == ' ') {
            pos = str.find(' ') + 1;
        } else {
            pos = 0;
        }

        for (size_t j = 0; j < size; ++j) {
            str = str.substr(pos, str.length());
            m[i][j] = stoi(str.substr(0, str.find(' ')));
            pos = str.find(' ') + 1;
        }
    }

    return is;
}

TwoDimensionMatrix operator+(const TwoDimensionMatrix& m1, const TwoDimensionMatrix& m2) {
    TwoDimensionMatrix matrix_sum;
    size_t size = TwoDimensionMatrix::getSize();

    for (size_t i = 0; i < size; ++i) {
        for (size_t j = 0; j < size; ++j) {
            matrix_sum[i][j] = m1[i][j] + m2[i][j];
        }
    }

    return matrix_sum;
}
