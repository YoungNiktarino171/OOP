#ifndef SQUARE_H
#define SQUARE_H

#include <iostream>
#include <cstdint>
#include "Figure.h"

class Square : public Figure {
public:
    Square();
    Square(size_t side);
    Square(std::istream &is);
    
    bool operator==(const Square &obj) const;
    bool operator!=(const Square &obj) const;
    Square &operator=(const Square &obj);
    
    friend std::ostream &operator<<(std::ostream &os, const Square &obj);
    friend std::istream &operator>>(std::istream &is, Square &obj);
    
    double SQUARE() override;
    void Print() override;
    
private:
    size_t side;
};

#endif
//тута думаю все ясно просто и понятно, просто прописываем все функции которые были в сипипи файле ага да
