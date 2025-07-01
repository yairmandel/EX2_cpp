SquareMat Project

Author: Yair Mandel

Email: yair340@gmail.com

Overview

This project implements a C++ class SquareMat inside the namespace MatrixLib, representing square matrices of real numbers. It supports a wide range of mathematical operations including addition, subtraction, multiplication, scalar operations, transposition, determinant computation, and more.

Structure

SquareMat.hpp – Header file with full class declaration.

SquareMat.cpp – Implementation of all member and friend functions.

Main.cpp – Demonstration of key matrix operations.

Test.cpp – Unit tests using the doctest framework.

Makefile – Build system for running demo, tests, and memory checks.

 Build & Run
 

Build and run demo:

make makeMain

Run unit tests:

make makeTest

Run memory leak checks:

make makeValgrind

Clean build files:

make makeClean

 Features

Matrix construction from size or 2D vector.

Element access via mat[i][j].

Arithmetic operators: +, -, *, /, %, unary -.

Compound assignment: +=, -=, *=, /=, %=

Comparison: ==, !=, <, <=, >, >= (based on sum of elements).

Transpose: ~mat

Determinant: !mat

Power: mat^n

Increment/Decrement: ++mat, mat++, --mat, mat--

Stream output: std::cout << mat

 Testing

The project uses doctest for unit testing. Each function is tested individually to verify correctness.

 Memory Management

All memory is managed using STL containers (std::vector). There are no raw pointers. The project passes valgrind checks for memory leaks.



פרויקט SquareMat

מחבר: יאיר מנדל

אימייל: yair340@gmail.com

סקירה כללית

הפרויקט מממש מחלקת C++ בשם SquareMat בתוך מרחב השמות MatrixLib, המייצגת מטריצות ריבועיות של מספרים ממשיים. המחלקה תומכת במגוון רחב של פעולות מתמטיות, כולל חיבור, חיסור, כפל, פעולות סקלריות, טרנספוז, חישוב דטרמיננטה ועוד.

מבנה הפרויקט

SquareMat.hpp – קובץ hader עם ההכרזה המלאה של המחלקה.

SquareMat.cpp – מימוש כל הפונקציות החברות (members) והחברים (friends).

Main.cpp – הדגמה של פעולות מרכזיות על מטריצות.

Test.cpp – בדיקות יחידה באמצעות מסגרת doctest.

Makefile – מערכת בנייה להרצת הדגמה, בדיקות ובדיקות זיכרון.

בהרצה

להריץ:

make makeMain

להריץ בדיקות יחידה:

make makeTest

להריץ בדיקות דליפות זיכרון (valgrind):

make makeValgrind

לנקות קבצי בנייה:

make makeClean

תכונות

    בניית מטריצה לפי גודל או וקטור דו־ממדי.

    גישה לאיברים דרך mat[i][j].

    אופרטורים אריתמטיים: +, -, *, /, %, מינוס חד־ערכי (-).

    אופרטורים מורכבים: +=, -=, *=, /=, %=.

    השוואות: ==, !=, <, <=, >, >= (מבוססות על סכום האיברים).

    טרנספוזיציה: ~mat.

    דטרמיננטה: !mat.

    חזקה: mat^n.

    אינקרמנט / דקרמנט: ++mat, mat++, --mat, mat--.

    פלט: std::cout << mat.

בדיקות

הפרויקט משתמש במסגרת doctest לבדיקות יחידה. כל פונקציה נבדקת בנפרד לאימות.

ניהול זיכרון

כל הזיכרון מנוהל באמצעות STL (std::vector). אין שימוש במחווני פוינטרים גולמיים (raw pointers). הפרויקט עובר בהצלחה בדיקות valgrind לדליפות זיכרון.
