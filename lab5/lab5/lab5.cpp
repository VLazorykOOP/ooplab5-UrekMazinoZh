#include <iostream>
#include <string>

using namespace std;

// Базовий клас "Вікно"
class Window {
protected:
    int topLeftX, topLeftY; // Координати верхнього лівого кута
    int bottomRightX, bottomRightY; // Координати нижнього правого кута
    string bgColor; // Колір тла

public:
    // Конструктор за замовчуванням
    Window() : topLeftX(0), topLeftY(0), bottomRightX(100), bottomRightY(50), bgColor("White") {}

    // Конструктор з параметрами
    Window(int x1, int y1, int x2, int y2, const string& color)
        : topLeftX(x1), topLeftY(y1), bottomRightX(x2), bottomRightY(y2), bgColor(color) {}

    // Деструктор
    ~Window() {
        cout << "Window destroyed." << endl;
    }

    // Функція для друку вікна
    void print() {
        cout << "Window: (" << topLeftX << ", " << topLeftY << ") - (" << bottomRightX << ", " << bottomRightY
            << "), Background Color: " << bgColor << endl;
    }

    // Функція для зміни кольору тла
    void setBackgroundColor(const string& color) {
        bgColor = color;
    }
};

// Похідний клас "Вікно з меню"
class MenuWindow : public Window {
private:
    string menuString; // Рядок меню

public:
    // Конструктор за замовчуванням
    MenuWindow() : Window(), menuString("Default Menu") {}

    // Конструктор з параметрами
    MenuWindow(int x1, int y1, int x2, int y2, const string& color, const string& menu)
        : Window(x1, y1, x2, y2, color), menuString(menu) {}

    // Деструктор
    ~MenuWindow() {
        cout << "MenuWindow destroyed." << endl;
    }

    // Функція для друку вікна з меню
    void print() {
        Window::print(); // Викликаємо функцію print() базового класу
        cout << "Menu: " << menuString << endl;
    }

    // Функція для зміни рядка меню
    void setMenuString(const string& menu) {
        menuString = menu;
    }
};

int main() {
    // Тестуємо базовий клас "Вікно"
    Window window1;
    window1.print();

    Window window2(10, 20, 50, 30, "Blue");
    window2.print();

    // Змінюємо колір тла і виводимо змінений об'єкт
    window2.setBackgroundColor("Green");
    window2.print();

    // Тестуємо похідний клас "Вікно з меню"
    MenuWindow menuWindow1;
    menuWindow1.print();

    MenuWindow menuWindow2(5, 10, 30, 15, "Yellow", "Custom Menu");
    menuWindow2.print();

    // Змінюємо колір тла, рядок меню і виводимо змінений об'єкт
    menuWindow2.setBackgroundColor("Red");
    menuWindow2.setMenuString("Updated Menu");
    menuWindow2.print();

    return 0;
}
