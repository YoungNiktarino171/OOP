#include <iostream>
#include <cmath>
#include "Rectangle.h"


Rectangle::Rectangle() {//усе ясно ничего не меняли
    side1 = 0;
    side2 = 0;
}

Rectangle::Rectangle(size_t (s), size_t (k)) : side1(s), side2(k) {
    std::cout << "Rectangle created: " << side1 << side2 << std::endl;
}

Rectangle::Rectangle(std::istream &is) {
    is >> side1;
    is >> side2;
}

double Rectangle::SQUARE() {//площадь наша любимая
    return side1 * side2;
}

void Rectangle::Print() {//площадь
    std::cout << "Стороны прямоугольника = " << side1 << side2 << "\n";
}

Rectangle &Rectangle::operator=(const Rectangle &obj) {//переопределяем оператор типо сравнения, в случае которого возвращаем адрес на объект
    if (this == &obj) return *this;
    side1 = obj.side1;
    side2 = obj.side2;
    return *this;
}

bool Rectangle::operator==(const Rectangle &obj) const {//переопределяем присваивание, тупо и понятно сторона == сторона объекта
    return side1 == obj.side1;
    return side2 == obj.side2;
}

bool Rectangle::operator!=(const Rectangle &obj) const {//тут все ясно
    return side1 != obj.side1;
    return side2 != obj.side2;
}

std::ostream &operator<<(std::ostream &os, const Rectangle &obj) {//оператор вывода фигуры
    os << obj.side1;
    os << obj.side2;
    return os;
}

std::istream &operator>>(std::istream &is, Rectangle &obj) {//оператор ввода фигуры
    std::cout << "Введите сторону: \n";
    is >> obj.side1;
    is >> obj.side2;
    return is;
}
//все операторы нужно прописать так как это сказано в задании лабораторной
