// yair340@gmail.com
#include <iostream>
#include "SquareMat.hpp"

using namespace MatrixLib;

int main() {
    try {
        // יצירת מטריצות
        SquareMat A({{1, 2}, {3, 4}});
        SquareMat B({{5, 6}, {7, 8}});

        std::cout << "Matrix A:\n" << A << "\n";
        std::cout << "Matrix B:\n" << B << "\n";

        // חיבור
        SquareMat C = A + B;
        std::cout << "A + B =\n" << C << "\n";

        // חיסור
        SquareMat D = B - A;
        std::cout << "B - A =\n" << D << "\n";

        // כפל מטריצות
        SquareMat E = A * B;
        std::cout << "A * B =\n" << E << "\n";

        // כפל בסקלר
        SquareMat F = A * 2.5;
        std::cout << "A * 2.5 =\n" << F << "\n";

        // מודולו איברים (עם מטריצה)
        SquareMat G({{3, 4}, {5, 6}});
        SquareMat H({{2, 3}, {4, 5}});
        G %= H;
        std::cout << "G %= H results in:\n" << G << "\n";

        // טרנספוזה
        SquareMat T = ~A;
        std::cout << "Transpose of A:\n" << T << "\n";

        // דטרמיננטה
        double detA = !A;
        std::cout << "Determinant of A: " << detA << "\n";

        // הגדלת כל איברי המטריצה באחד (pre-increment)
        ++A;
        std::cout << "After ++A:\n" << A << "\n";

    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << "\n";
        return 1;
    }

    return 0;
}
