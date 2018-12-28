#ifndef SQUARE_H
#define SQUARE_H
#include <cstdlib>
#include <iostream>
#include "Figure.h"

class Square : public Figure {
public:
    Square();
    Square(std::istream &is);
    Square(size_t a);

    virtual double SQUARE() override;
    virtual void Print() override;   
    virtual ~Square();

private:
    size_t side_a;
};

#endif /* SQUARE_H */