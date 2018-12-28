#include "TList.h"
#include <iostream>
#include <cstdint>

TList::TList()//создание списка(объявление)
{
    head = nullptr;
    length = 0;
}

void TList::Push(Square &obj) {//вставка элементов в список
    int32_t index = 0;//по умолчанию список равен 0
    std::cout << "Enter index = ";
    std::cin >> index;//вводим индекс
    if (index > this->GetLength() - 1 || index < 0) {//если индекс больше чем максимальный индекс списка или индекс меньше нуля то ошибка
        std::cerr << "This index doesn't exist\n";
        return;
    }
    if (index == 0) {//если индекс равен 0
        this->PushFirst(obj);// то этот элемент первый, значит используем функцию вставки 1 элемента
    } else if (index == this->GetLength() - 1) {//если последний, то соответственно последнего
        this->PushLast(obj);
    } else {
        this->PushAtIndex(obj, index);// если не первый и не последний то функция вставки по месту индекса работает
    }
    ++length;//после вставки увеличиваем длину
}

void TList::PushAtIndex(Square &obj, int32_t ind)//вставка по месту индекса
{
    TListItem *newItem = new TListItem(obj);//тут начинается пиздец который писать долго, потом объясню если сам не разберешься
    TListItem *tmp = this->head;
    for(int32_t i = 1; i < ind; ++i){
        tmp = tmp->GetNext();
    }
    newItem->SetNext(tmp->GetNext());
    newItem->SetPrev(tmp);
    tmp->SetNext(newItem);
    tmp->GetNext()->SetPrev(newItem);
}

void TList::PushLast(Square &obj)//позже
{
    TListItem *newItem = new TListItem(obj);
    TListItem *tmp = this->head;

    while (tmp->GetNext() != nullptr) {
        tmp = tmp->GetNext();
    }
    tmp->SetNext(newItem);
    newItem->SetPrev(tmp);
    newItem->SetNext(nullptr);
}

void TList::PushFirst(Square &obj)//позже
{
    TListItem *newItem = new TListItem(obj);
    TListItem *oldHead = this->head;
    this->head = newItem;
    if(oldHead != nullptr) {
        newItem->SetNext(oldHead);
        oldHead->SetPrev(newItem);
    }
}

uint32_t TList::GetLength()//тупо функция возвращаяющая длину списка
{
    return this->length;
}

const bool TList::IsEmpty() const//возвращает пустой список
{
    return head == nullptr;
}

Square TList::Pop()
{
    int32_t ind = 0;
    std::cout << "Enter index = ";
    std::cin >> ind;
    Square res;
    if (ind > this->GetLength() - 1 || ind < 0 || this->IsEmpty()) {
        std::cout << "Change index" << std::endl;
        return res;
    }

    if (ind == 0) {
        res = this->PopFirst();
    } else if (ind == this->GetLength() - 1) {
        res = this->PopLast();
    } else {
        res = this->PopAtIndex(ind);
    }
    --length;
    return res;
}

Square TList::PopAtIndex(int32_t ind)
{
    TListItem *tmp = this->head;
    for(int32_t i = 0; i < ind - 1; ++i) {
        tmp = tmp->GetNext();
    }
    TListItem *removed = tmp->GetNext();
    Square res = removed->GetFigure();
    TListItem *nextItem = removed->GetNext();
    tmp->SetNext(nextItem);
    nextItem->SetPrev(tmp);
    delete removed;
    return res;
}


Square TList::PopFirst()
{
    if (this->GetLength() == 1) {
        Square res = this->head->GetFigure();
        delete this->head;
        this->head = nullptr;
        return res;
    }
    TListItem *tmp = this->head;
    Square res = tmp->GetFigure();
    this->head = this->head->GetNext();
    this->head->SetPrev(nullptr);
    delete tmp;
    return res;
}

Square TList::PopLast()
{
    if (this->GetLength() == 1) {
        Square res = this->head->GetFigure();
        delete this->head;
        this->head = nullptr;
        return res;
    }
    TListItem *tmp = this->head;
    while(tmp->GetNext()->GetNext()) {
        tmp = tmp->GetNext();
    }
    TListItem *removed = tmp->GetNext();
    Square res = removed->GetFigure();
    tmp->SetNext(removed->GetNext());
    delete removed;
    return res;
}


std::ostream& operator<<(std::ostream &os, const TList &list)
{
    if (list.IsEmpty()) {
        os << "The list is empty." << std::endl;
        return os;
    }

    TListItem *tmp = list.head;
    for(int32_t i = 0; tmp; ++i) {
        os << "idx: " << i << " " << *tmp << std::endl;
        tmp = tmp->GetNext();
    }

    return os;
}

TList::~TList()
{
    TListItem *tmp;
    while (head) {
        tmp = head;
        head = head->GetNext();
        delete tmp;
    }
}