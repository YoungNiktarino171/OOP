#include "Square.h"
#include <iostream>
#include <cmath>
 
Square::Square() : Square(0) {}
 
Square::Square(size_t (a)) : side_a(a) {}
 
Square::Square(std::istream &is) {
	is >> side_a;
}
 
double Square::SQUARE() {
	return side_a * side_a;
}
 
void Square::Print() {
	std::cout << "Квадрат создан: a = " << side_a << std::endl;
 
}
 
Square::~Square() {
	std::cout << "Квадрат удален." << std::endl;
}
