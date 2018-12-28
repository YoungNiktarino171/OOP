#ifndef TRAPEZE_H
#define TRAPEZE_H
#include <cstdlib>
#include <iostream>
#include "Figure.h"

class Trapeze : public Figure {//Объявляем еще один класс - "подскласс" класса фигура
public:
    Trapeze();//объявляем функции которые прописывали в cpp файле
    Trapeze(std::istream &is);
    Trapeze(size_t side_up,size_t side_low,size_t side_high);
    Trapeze(const Trapeze& orig);

    virtual double SQUARE() override;//override - означает то, что функции у нас переопределены для всех фигур, то есть если trapeze мы например вызываем явно(она не может относиться например к квадрату),
    //то функции площади и печати, когда мы их вызываем подстраиваются под фигуру с которой мы работаем
    void Print() override;// то же самое
    Trapeze &operator=(const Trapeze &obj);
    bool operator==(const Trapeze &obj) const;
    bool operator!=(const Trapeze &obj) const;
    Trapeze &operator++();
    friend std::ostream &operator<<(std::ostream &os, const Trapeze &obj);
    friend std::istream &operator>>(std::istream &is, Trapeze &obj);
    virtual ~Trapeze();

private:
    size_t side_up;//наши публичные составляющие класса, переменные класса используемые здесь - это стороны
    size_t side_low;
    size_t side_high;
};

#endif /* Trapeze_H */