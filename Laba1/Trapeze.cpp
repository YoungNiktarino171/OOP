#include "Trapeze.h"
#include <iostream>
#include <cmath>
#include <math.h>
 
Trapeze::Trapeze() : Trapeze(0, 0, 0) {}
 
Trapeze::Trapeze(size_t a, size_t b, size_t h) : side_a(a), side_b(b), side_h(h) {}
 
Trapeze::Trapeze(std::istream &is) {
	is >> side_a;
	is >> side_b;
	is >> side_h;
}
 
double Trapeze::SQUARE() {
	return ((side_a + side_b) * side_h) / 2;
}
 
void Trapeze::Print() {
	std::cout << "Трапеция создана: " << "a = " << side_a << "; b = " << side_b << "; h = " << side_h << std::endl; 
}
 
Trapeze::~Trapeze() {
	std::cout << "Трапеция удалена." << std::endl;
}