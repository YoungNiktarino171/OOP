#ifndef TLIST_H
#define TLIST_H

#include <cstdint>
#include "square.h"
#include "TListItem.h"

class TList //непосредственно класс списка
{
public://публичные функции, которые мы используем в других классах фсе ясна
    TList();
    void Push(Square &obj);
    const bool IsEmpty() const;
    uint32_t GetLength();
    Square Pop();
    friend std::ostream& operator<<(std::ostream &os, const TList &list);
    virtual ~TList();

private:// тута у нас в привате
    uint32_t length;//длина списка
    TListItem *head;//указатель на голову списка

    //ииии функции которые мы НАПРЯМУЮ НЕ ИСПОЛЬЗУЕМ в нашем коде программы, они доступны только функциям класса и за пределы класса выходить не могут
    void PushFirst(Square &obj);
    void PushLast(Square &obj);
    void PushAtIndex(Square &obj, int32_t ind);
    Square PopFirst();
    Square PopLast();
    Square PopAtIndex(int32_t ind);
};

#endif