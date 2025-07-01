// yair340@gmail.com
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "SquareMat.hpp"

using namespace MatrixLib;

TEST_CASE("Constructor and getSize") {
    SquareMat mat1(3);
    CHECK(mat1.getSize() == 3);

    std::vector<std::vector<double>> vals = {{1, 2}, {3, 4}};
    SquareMat mat2(vals);
    CHECK(mat2.getSize() == 2);
}

TEST_CASE("Operator [] access and modification") {
    SquareMat mat({{1, 2}, {3, 4}});
    CHECK(mat[0][1] == 2);
    mat[0][1] = 5;
    CHECK(mat[0][1] == 5);
}

TEST_CASE("Operator + and -") {
    SquareMat a({{1, 2}, {3, 4}});
    SquareMat b({{5, 6}, {7, 8}});
    SquareMat c = a + b;

    CHECK(c[0][0] == 6);
    CHECK(c[1][1] == 12);

    SquareMat d = b - a;
    CHECK(d[0][0] == 4);
    CHECK(d[1][1] == 4);
}

TEST_CASE("Unary minus operator") {
    SquareMat a({{1, -2}, {3, -4}});
    SquareMat b = -a;

    CHECK(b[0][0] == -1);
    CHECK(b[0][1] == 2);
    CHECK(b[1][0] == -3);
    CHECK(b[1][1] == 4);
}

TEST_CASE("Scalar multiplication and division") {
    SquareMat a({{1, 2}, {3, 4}});
    SquareMat b = a * 2.0;

    CHECK(b[0][0] == 2);
    CHECK(b[1][1] == 8);

    SquareMat c = b / 2.0;
    CHECK(c[0][0] == 1);
    CHECK(c[1][1] == 4);
}

TEST_CASE("Compound assignment operators") {
    SquareMat a({{1, 1}, {1, 1}});
    SquareMat b({{2, 2}, {2, 2}});

    a += b;
    CHECK(a[0][0] == 3);
    CHECK(a[1][1] == 3);

    a -= b;
    CHECK(a[0][0] == 1);
    CHECK(a[1][1] == 1);

    a *= 2;
    CHECK(a[0][0] == 2);
    CHECK(a[1][1] == 2);

    a /= 2;
    CHECK(a[0][0] == 1);
    CHECK(a[1][1] == 1);
}

TEST_CASE("Transpose operator") {
    SquareMat a({{1, 2}, {3, 4}});
    SquareMat b = ~a;

    CHECK(b[0][1] == 3);
    CHECK(b[1][0] == 2);
}

TEST_CASE("Determinant operator") {
    SquareMat a({{1, 2}, {3, 4}});
    double det = !a;

    CHECK(det == -2);
}

TEST_CASE("Equality and comparison operators") {
    SquareMat a({{1, 2}, {3, 4}});
    SquareMat b({{4, 3}, {2, 1}});
    SquareMat c({{17, 2}, {3, 4}});

    CHECK(a == b);
    CHECK(a != c);
    CHECK(c > b);
    CHECK(a < c);
    CHECK(c >= a);
    CHECK(b <= a);
}