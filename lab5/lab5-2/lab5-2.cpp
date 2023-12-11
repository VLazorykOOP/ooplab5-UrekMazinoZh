#include <iostream>
#include <cstring>
#pragma warning(disable : 4996)


using namespace std;

class HardDrive {
private:
    int capacity;  // Обсяг в Мбайтах

public:
    // Конструктор за замовчуванням
    HardDrive() : capacity(0) {}

    // Конструктор з параметром
    HardDrive(int capacity) : capacity(capacity) {}

    // Метод доступу до обсягу жорсткого диска
    int getCapacity() const {
        return capacity;
    }
};

class Computer {
private:
    char* brand;  // Марка комп'ютера
    double price;  // Ціна комп'ютера
    HardDrive hardDrive;  // Об'єкт класу жорсткий диск

public:
    // Конструктор за замовчуванням
    Computer() : brand(nullptr), price(0.0), hardDrive() {}

    // Конструктор з параметрами
    Computer(const char* brand, double price, int hardDriveCapacity)
        : price(price), hardDrive(hardDriveCapacity) {
        this->brand = new char[strlen(brand) + 1];
        strcpy(this->brand, brand);
    }

    // Деструктор
    ~Computer() {
        delete[] brand;
    }

    // Функція друку інформації про комп'ютер
    void printInfo() const {
        cout << "Brand: " << brand << endl;
        cout << "Price: $" << price << endl;
        cout << "Hard Drive Capacity: " << hardDrive.getCapacity() << " MB" << endl;
    }
};

class DesktopComputer : public Computer {
private:
    double monitorSize;  // Розмір монітора

public:
    // Конструктор з параметрами
    DesktopComputer(const char* brand, double price, int hardDriveCapacity, double monitorSize)
        : Computer(brand, price, hardDriveCapacity), monitorSize(monitorSize) {}

    // Деструктор
    ~DesktopComputer() {}

    // Функція друку інформації про стільничний комп'ютер
    void printInfo() const {
        Computer::printInfo();  // Виклик функції базового класу
        cout << "Monitor Size: " << monitorSize << " inches" << endl;
    }
};

int main() {
    // Приклад використання класів
    DesktopComputer desktop("ABC", 1500.0, 500, 21.5);
    desktop.printInfo();

    return 0;
}
