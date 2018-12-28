#include <iostream>
#include <cmath>
#include <algorithm>
#include "trapeze.h"

Trapeze::Trapeze() : Trapeze(0, 0, 0, 0)
{
}

Trapeze::Trapeze(int32_t sb, int32_t bb, int32_t ls, int32_t rs): small_base(sb), big_base(bb), l_side(ls), r_side(rs)
{
    if (small_base > big_base) {
        std::swap(small_base, big_base);
    }
    //std::cout << "Trapeze created: " << small_base << ", " << big_base << ", " << l_side << ", " << r_side << std::endl;
}

Trapeze::Trapeze(std::istream &is)
{
    std::cout << "Большая сторона: ";
    is >> big_base;
    std::cout << "Меньшая сторона: ";
    is >> small_base;
    std::cout << "Левая сторона: ";
    is >> l_side;
    std::cout << "Правая сторона: ";
    is >> r_side;
    if (small_base > big_base) {
        std::swap(small_base, big_base);
    }
    if(small_base < 0 || big_base < 0 || l_side < 0 || r_side < 0) {
        std::cerr << "Error: sides should be > 0." << std::endl;
    }
}

Trapeze::Trapeze(const Trapeze &orig)
{
    small_base = orig.small_base;
    big_base = orig.big_base;
    l_side = orig.l_side;
    r_side = orig.r_side;
}

double Trapeze::Square()
{
    double sqr;
    try {
        double h = std::sqrt(l_side * l_side - 0.25 * std::pow((l_side * l_side - r_side * r_side)
            / (big_base - small_base) + big_base - small_base, 2.0));
        sqr =  (big_base + small_base) / 2 + h;
        sqr = (sqr == sqr) ? sqr : -1;
    } catch(...) {
        sqr = -1;
    }
    return sqr;
}

void Trapeze::Print()
{
    std::cout << "Меньшая сторона = " << small_base << ", Большая сторона = " << big_base << ", Левая сторона = " <<  l_side << ", Правая сторона = " << r_side << ", square = " << this->Square() << ", type: трапеция" << std::endl;
}

Trapeze::~Trapeze()
{
}

std::ostream& operator <<(std::ostream &os, const Trapeze &obj)
{
    os << "(" << obj.small_base << " " << obj.big_base << " " << obj.l_side << " " << obj.r_side << ")," << "type: trapeze" << std::endl;
    return os;
}

std::istream& operator >>(std::istream &is, Trapeze &obj)
{
    std::cout << "ольшая сторона: ";
    is >> obj.big_base;
    std::cout << "Меньшая сторона: ";
    is >> obj.small_base;
    std::cout << "Левая сторона: ";
    is >> obj.l_side;
    std::cout << "Правая сторона : ";
    is >> obj.r_side;
    return is;
}

bool Trapeze::operator ==(const Trapeze &obj) const
{
    return small_base == obj.small_base && big_base == obj.big_base && l_side == obj.l_side && r_side == obj.r_side;
}


Trapeze& Trapeze::operator =(const Trapeze &obj)
{
    if (&obj == this) {
        return *this;
    }

    small_base = obj.small_base;
    big_base = obj.big_base;
    l_side = obj.l_side;
    r_side = obj.r_side;

    return *this;
}