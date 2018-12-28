#ifndef TLISTITEM_H
#define TLISTITEM_H

#include "square.h"

class TListItem//класс элемента списка
{
public:
    TListItem(const Square &obj);

    Square GetFigure() const;
    TListItem* GetNext();
    TListItem* GetPrev();
    void SetNext(TListItem *item);
    void SetPrev(TListItem *item);
    friend std::ostream& operator<<(std::ostream &os, const TListItem &obj);

    virtual ~TListItem(){};

private://в привате для этого класса у нас
    Square item;//фигура
    TListItem *next;//указатель на следующий
    TListItem *prev;//указатель на предыдущий
};

#endif

//тута тоже просто объявления функций