#include <iostream>

using namespace std;

class Quadrilateral {
public:
    Quadrilateral() : side1(0), side2(0), side3(0), side4(0) {}
    Quadrilateral(double s1, double s2, double s3, double s4)
        : side1(s1), side2(s2), side3(s3), side4(s4) {}

    // Конструктор копіювання
    Quadrilateral(const Quadrilateral& other) {
        side1 = other.side1;
        side2 = other.side2;
        side3 = other.side3;
        side4 = other.side4;
    }

    // Оператор присвоювання
    Quadrilateral& operator=(const Quadrilateral& other) {
        if (this != &other) {
            side1 = other.side1;
            side2 = other.side2;
            side3 = other.side3;
            side4 = other.side4;
        }
        return *this;
    }

    // Функція виводу в потік
    friend ostream& operator<<(ostream& out, const Quadrilateral& quad) {
        out << "Side1: " << quad.side1 << ", Side2: " << quad.side2
            << ", Side3: " << quad.side3 << ", Side4: " << quad.side4;
        return out;
    }

    // Функція введення з потоку
    friend istream& operator>>(istream& in, Quadrilateral& quad) {
        cout << "Enter Side1: ";
        in >> quad.side1;
        cout << "Enter Side2: ";
        in >> quad.side2;
        cout << "Enter Side3: ";
        in >> quad.side3;
        cout << "Enter Side4: ";
        in >> quad.side4;
        return in;
    }

protected:
    double side1, side2, side3, side4;
};

class Square : public Quadrilateral {
public:
    Square() : Quadrilateral() {}
    Square(double side) : Quadrilateral(side, side, side, side) {}

    // Конструктор копіювання
    Square(const Square& other) : Quadrilateral(other) {}

    // Оператор присвоювання
    Square& operator=(const Square& other) {
        if (this != &other) {
            Quadrilateral::operator=(other);
        }
        return *this;
    }
};

int main() {
    Square square1;
    cout << "Enter data for square1:\n";
    cin >> square1;
    cout << "square1 data: " << square1 << endl;

    Square square2 = square1; // Виклик конструктору копіювання
    cout << "square2 data (copied from square1): " << square2 << endl;

    Square square3;
    square3 = square1; // Виклик оператора присвоювання
    cout << "square3 data (assigned from square1): " << square3 << endl;

    return 0;
}
