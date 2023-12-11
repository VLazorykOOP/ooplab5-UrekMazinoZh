#include <iostream>
#include <string>

using namespace std;

// ������� ���� "³���"
class Window {
protected:
    int topLeftX, topLeftY; // ���������� ��������� ����� ����
    int bottomRightX, bottomRightY; // ���������� �������� ������� ����
    string bgColor; // ���� ���

public:
    // ����������� �� �������������
    Window() : topLeftX(0), topLeftY(0), bottomRightX(100), bottomRightY(50), bgColor("White") {}

    // ����������� � �����������
    Window(int x1, int y1, int x2, int y2, const string& color)
        : topLeftX(x1), topLeftY(y1), bottomRightX(x2), bottomRightY(y2), bgColor(color) {}

    // ����������
    ~Window() {
        cout << "Window destroyed." << endl;
    }

    // ������� ��� ����� ����
    void print() {
        cout << "Window: (" << topLeftX << ", " << topLeftY << ") - (" << bottomRightX << ", " << bottomRightY
            << "), Background Color: " << bgColor << endl;
    }

    // ������� ��� ���� ������� ���
    void setBackgroundColor(const string& color) {
        bgColor = color;
    }
};

// �������� ���� "³��� � ����"
class MenuWindow : public Window {
private:
    string menuString; // ����� ����

public:
    // ����������� �� �������������
    MenuWindow() : Window(), menuString("Default Menu") {}

    // ����������� � �����������
    MenuWindow(int x1, int y1, int x2, int y2, const string& color, const string& menu)
        : Window(x1, y1, x2, y2, color), menuString(menu) {}

    // ����������
    ~MenuWindow() {
        cout << "MenuWindow destroyed." << endl;
    }

    // ������� ��� ����� ���� � ����
    void print() {
        Window::print(); // ��������� ������� print() �������� �����
        cout << "Menu: " << menuString << endl;
    }

    // ������� ��� ���� ����� ����
    void setMenuString(const string& menu) {
        menuString = menu;
    }
};

int main() {
    // ������� ������� ���� "³���"
    Window window1;
    window1.print();

    Window window2(10, 20, 50, 30, "Blue");
    window2.print();

    // ������� ���� ��� � �������� ������� ��'���
    window2.setBackgroundColor("Green");
    window2.print();

    // ������� �������� ���� "³��� � ����"
    MenuWindow menuWindow1;
    menuWindow1.print();

    MenuWindow menuWindow2(5, 10, 30, 15, "Yellow", "Custom Menu");
    menuWindow2.print();

    // ������� ���� ���, ����� ���� � �������� ������� ��'���
    menuWindow2.setBackgroundColor("Red");
    menuWindow2.setMenuString("Updated Menu");
    menuWindow2.print();

    return 0;
}
