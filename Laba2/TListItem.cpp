#include "TListItem.h"
#include <iostream>

//если файл TList отвечал за построение нашего списка, то этот файл отвечает за взаимосвязь списка и его элементов, то есть идет работа с фигурами
//у кармы тут двусвязный список иси чо это заебись

TListItem::TListItem(const Square &obj)//создание 1 элемента списка
{
    this->item = obj;//говорим что взятое значение это объект списка то есть фигура
    this->next = nullptr;//следующий пустой
    this->prev = nullptr;//предыдущий пустой
}

Square TListItem::GetFigure() const//взятие фигуры из списка, просто берем значение
{
    return this->item;
}

TListItem* TListItem::GetNext()//взятие следующего элемента списка
{
    return this->next;
}

TListItem* TListItem::GetPrev()//взятие предыдущего элемента списка
{
    return this->prev;
}

void TListItem::SetNext(TListItem *item)//задаем значение следующего элемента списка
{
    this->next = item;
}

void TListItem::SetPrev(TListItem *item)//задаем значение предыдущего элемента списка
{
    this->prev = item;
}

std::ostream& operator<<(std::ostream &os, const TListItem &obj)//оператор вывода переопределенный для данной функции
{
    os << "(" << obj.item << ")" << std::endl;//obj.item смотри в square 
    return os;
}