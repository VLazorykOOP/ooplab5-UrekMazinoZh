#include <iostream>
#include <cstring>
#pragma warning(disable : 4996)


using namespace std;

class HardDrive {
private:
    int capacity;  // ����� � �������

public:
    // ����������� �� �������������
    HardDrive() : capacity(0) {}

    // ����������� � ����������
    HardDrive(int capacity) : capacity(capacity) {}

    // ����� ������� �� ������ ��������� �����
    int getCapacity() const {
        return capacity;
    }
};

class Computer {
private:
    char* brand;  // ����� ����'�����
    double price;  // ֳ�� ����'�����
    HardDrive hardDrive;  // ��'��� ����� �������� ����

public:
    // ����������� �� �������������
    Computer() : brand(nullptr), price(0.0), hardDrive() {}

    // ����������� � �����������
    Computer(const char* brand, double price, int hardDriveCapacity)
        : price(price), hardDrive(hardDriveCapacity) {
        this->brand = new char[strlen(brand) + 1];
        strcpy(this->brand, brand);
    }

    // ����������
    ~Computer() {
        delete[] brand;
    }

    // ������� ����� ���������� ��� ����'����
    void printInfo() const {
        cout << "Brand: " << brand << endl;
        cout << "Price: $" << price << endl;
        cout << "Hard Drive Capacity: " << hardDrive.getCapacity() << " MB" << endl;
    }
};

class DesktopComputer : public Computer {
private:
    double monitorSize;  // ����� �������

public:
    // ����������� � �����������
    DesktopComputer(const char* brand, double price, int hardDriveCapacity, double monitorSize)
        : Computer(brand, price, hardDriveCapacity), monitorSize(monitorSize) {}

    // ����������
    ~DesktopComputer() {}

    // ������� ����� ���������� ��� ���������� ����'����
    void printInfo() const {
        Computer::printInfo();  // ������ ������� �������� �����
        cout << "Monitor Size: " << monitorSize << " inches" << endl;
    }
};

int main() {
    // ������� ������������ �����
    DesktopComputer desktop("ABC", 1500.0, 500, 21.5);
    desktop.printInfo();

    return 0;
}
