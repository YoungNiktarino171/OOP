#include "Rectangle.h"
#include <iostream>
#include <cmath>

 
Rectangle::Rectangle() : Rectangle(0, 0) {}
 
Rectangle::Rectangle(size_t a, size_t b) : side_a(a), side_b(b) {}
 
Rectangle::Rectangle(std::istream &is) {
	is >> side_a;
	is >> side_b;
} 
 
double Rectangle::SQUARE() {
	return side_a * side_b;
}
 
void Rectangle::Print() {
	std::cout << "Прямоугольник создан: " << "a = " << side_a << "; b = " << side_b << std::endl;
 
}
 
Rectangle::~Rectangle() {
	std::cout << "Прямоугольник удалён." << std::endl;
}
