
#include <cstdlib>
#include <iostream>
#include <memory>
 
#include "Trapeze.h"
#include "Rectangle.h"
#include "square.h"
#include "TListItem.h"
#include "TList.h"


void help(){
    std::cout << "Меню:\n";
    std::cout << "1) Добавить фигуру в список\n";
    std::cout << "2) Удалить фигуру из списка\n";
    std::cout << "3) Печать списка\n";
    std::cout << "4) Помощь\n";
    std::cout << "0) Выход\n";
}

int main(int argc, const char * argv[]) {
    size_t act;
    TList<Figure> list;
    std::shared_ptr<Figure> ptr;
    help();
    while (true) {
        std::cin >> act;
        if (act == 0) break;
        if (act > 4) {
            std::cout << "Введите другие параметры!\n";
            continue;
        }
        switch (act) {
            case 1: {
                size_t type;
                std::cout << "Выберите фигуру: \n";
                std::cout << "1) Трапеция\n";
                std::cout << "2) Квадрат\n";
                std::cout << "3) Прямоугольник\n";
                std::cin >> type;
                
                if (type > 0) {
                    if (type > 3)  {
                        std::cout << "Неверные параметры!\n";
                        continue;
                    }
                    switch(type) {
                        case 1:
                            ptr = std::make_shared<Trapeze>(std::cin);
                            list.Push(ptr);
                            break;
                        case 2:
                            ptr = std::make_shared<Square>(std::cin);
                            list.Push(ptr);
                            break;
                        case 3:
                            ptr = std::make_shared<Rectangle>(std::cin);
                            list.Push(ptr);
                            break;
                        }
                    }
                break;
            }
            case 2: {
                list.Pop();
                break;
            }
            case 3: {
                if(!list.IsEmpty()) {
                    for(auto i : list) {
                        i->Print();
                    } 
                } else {
                    std::cout << "List is empty." << std::endl;
                }
                break;
            }
            case 4: {
                help();
                break;
            }
            default: {
                std::cerr << "Некорректная команда\n";
                break;
            }
        }
    }
    return 0;
}
