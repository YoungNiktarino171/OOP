#ifndef RECTANGLE_H//ВСЕ ТО ЖЕ САМОЕ для 2 сторон прямоугольника
#define RECTANGLE_H
#include <cstdlib>
#include <iostream>
#include "Figure.h"

class Rectangle : public Figure {
public:
    Rectangle();
    Rectangle(std::istream &is);
    Rectangle(size_t a, size_t b);
    Rectangle(const Rectangle& orig);

    virtual double SQUARE() override;
    void Print() override;

    Rectangle &operator=(const Rectangle &obj);
    bool operator==(const Rectangle &obj) const;
    bool operator!=(const Rectangle &obj) const;
    Rectangle &operator++();
    friend std::ostream &operator<<(std::ostream &os, const Rectangle &obj);
    friend std::istream &operator>>(std::istream &is, Rectangle &obj);
   

private:
    size_t side1;
    size_t side2;
};

#endif /* Rectangle_H */
