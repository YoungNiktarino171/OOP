#ifndef RECTANGLE_H
#define RECTANGLE_H
#include <cstdlib>
#include <iostream>
#include "Figure.h"

class Rectangle : public Figure {
public:
    Rectangle();
    Rectangle(std::istream &is);
    Rectangle(size_t a, size_t b);

    virtual double SQUARE() override;
    void Print() override;   
    virtual ~Rectangle();

private:
    size_t side_a;
    size_t side_b;
};

#endif /* RECTANGLE_H */
