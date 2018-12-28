#include <iostream>
#include <cmath>
#include "square.h"


Square::Square() {//усе ясно ничего не меняли
    side = 0;
}

Square::Square(size_t (s)) : side(s) {
    std::cout << "Square created: " << side << std::endl;
}

Square::Square(std::istream &is) {
    is >> side;
}

double Square::SQUARE() {//площадь наша любимая
    return side * side;
}

void Square::Print() {//площадь
    std::cout << "Сторона квадрата = " << side << "\n";
}

Square &Square::operator=(const Square &obj) {//переопределяем оператор типо сравнения, в случае которого возвращаем адрес на объект
    if (this == &obj) return *this;
    side = obj.side;
    return *this;
}

bool Square::operator==(const Square &obj) const {//переопределяем присваивание, тупо и понятно сторона == сторона объекта
    return side == obj.side;
}

bool Square::operator!=(const Square &obj) const {//тут все ясно
    return side != obj.side;
}

std::ostream &operator<<(std::ostream &os, const Square &obj) {//оператор вывода фигуры
    os << obj.side;
    return os;
}

std::istream &operator>>(std::istream &is, Square &obj) {//оператор ввода фигуры
    std::cout << "Введите сторону: \n";
    is >> obj.side;
    return is;
}
//все операторы нужно прописать так как это сказано в задании лабораторной