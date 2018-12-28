#include "Trapeze.h"
#include <iostream>
#include <cmath>
#include <math.h>
 
Trapeze::Trapeze() : Trapeze(0, 0, 0) {//объявляем трапеция как набор из 2 ее сторон и высоты по умолчанию равных 0
}
 
Trapeze::Trapeze(size_t i, size_t j, size_t k) : side_up(i), side_low(j), side_high(k) {}


Trapeze::Trapeze(std::istream &is) {
    while (true) {
        is >> side_up;//здесь и дальше is << то же самое что и scanf в си
        is >> side_low;
        is >> side_high;
        if (std::cin.peek() == '\n') {
            std::cin.get();
            break;
        }
        else {
            std::cout << "Error! Enter another number: " << std::endl;
            std::cin.clear();
            while (std::cin.get() != '\n'){}
        }
    }
}
 
Trapeze::Trapeze(const Trapeze& orig) {//еще одна хуйня хз что делает и зачем нужна, можно удалить, но в примере было, поэтому оставляем
	std::cout << "Trapeze copy created" << std::endl;
	side_up = orig.side_up;
	side_low = orig.side_low;
	side_high = orig.side_high;
}
 
double Trapeze::SQUARE() {//функция подсчета площади формулой взятой из интернета
	return ((side_up + side_low) * side_high) / 2;
}
 
void Trapeze::Print() {//функция печати
	std::cout << "up = " << side_up << ", low = " << side_low << ", high = " << side_high << std::endl;//ну тут все понятно
 
}

Trapeze &Trapeze::operator=(const Trapeze &obj) {
    if (this == &obj) return *this;
    std::cout << "Trapeze copied" << std::endl;
    side_up = obj.side_up;
    side_low = obj.side_low;
    side_high = obj.side_high;
    return *this;
}

bool Trapeze::operator==(const Trapeze &obj) const {
    return side_up == obj.side_up;
    return side_low == obj.side_low;
    return side_high == obj.side_high;
}

bool Trapeze::operator!=(const Trapeze &obj) const {
    return side_up != obj.side_up;
    return side_low != obj.side_low;
    return side_high != obj.side_high;
}

Trapeze &Trapeze::operator++() {
    side_up++;
	side_low++;
	side_high++;
    return *this;
}
    
Trapeze::~Trapeze() {}

std::ostream &operator<<(std::ostream &os, const Trapeze &obj) {
    os << "Side_up = " << obj.side_up << std::endl;
    os << "Side_low = " << obj.side_low << std::endl;
    os << "Side_high = " << obj.side_high << std::endl;
    return os;
}
    
std::istream &operator>>(std::istream &is, Trapeze &obj) {
    is >> obj.side_up;
    is >> obj.side_low;
    is >> obj.side_high;
    return is;
}
//Никита лох