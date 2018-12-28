#ifndef TRAPEZE_H
#define TRAPEZE_H
#include <cstdlib>
#include <iostream>
#include "Figure.h"

class Trapeze : public Figure {
public:
    Trapeze();
    Trapeze(std::istream &is);
    Trapeze(size_t a,size_t b, size_t h);


    virtual double SQUARE() override;
    void Print() override;   
    virtual ~Trapeze();

private:
    size_t side_a;
    size_t side_b;
    size_t side_h;
};

#endif /* TRAPEZE_H */