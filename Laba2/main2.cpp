
#include <cstdlib>
#include <iostream>
#include "TListItem.h"
#include "TList.h"
#include "square.h"

void option(Figure *figure) {//функция вызывающая переопределенную функцию поиска площади, на вход которой подается фигура(СМОТРИ НИЖЕ ГДЕ И КАК ОНА ВЫЗЫВАЕТСЯ)
    figure->Print();//печать введенных сторон фигур, то есть по сути саму фигуру
    std::cout << "SQUARE: " << figure->SQUARE() << std::endl;//подсчет площади и тут же ее печать
    delete figure;//освобождение памяти выделенной под фигуру
}

void print_help() {//функция меню
        std::cout << "Меню действий:" << std::endl;
        std::cout << "1. Добавить фигуру в список" << std::endl;
        std::cout << "2. Удалить фигуру из списка" << std::endl;
        std::cout << "3. Распечатать список" << std::endl;
        std::cout << "4. Меню" << std::endl;
        std::cout << "5. Выход" << std::endl;
}        

int main(int argc, const char * argv[]) {
    print_help();
    size_t d;//переменная отвечающая за действие
    TList list;//объявление списка
    while (true) {
        std::cin >> d;
        if (d == 5) break;// если параметр действия 4, то выходим
        if (d > 5) {// если параметров больше 4 то ошибка
            std::cout << "Введите другие параметры" << std::endl;
            continue;
        }
        switch (d) {
            case 1: {
                std::cout << "Введите сторону квадрата: " << std::endl;
                Square obj(std::cin);//создаем список
                list.Push(obj);//добавляем квадрат
                break;
            }
            case 2: {
                list.Pop();//удаляем верхний элемент(квадрат) из списка
                break;
            }
            case 3: {
                std::cout << list << std::endl;// вывод списка на печать
                break;
            }
            case 4: {
                print_help();
                break;
            }
            default: {
                break;
            }
        }
    }
    return 0;
}






