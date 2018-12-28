#include "TList.h"
#include <iostream>
#include "trapeze.h"
#include "pentagon.h"
#include "rhomb.h"
#include "TStack.h"

void menu(void)
{
    std::cout << "Введите операцию:" << std::endl;
    std::cout << "1) Добавить трапецию" << std::endl;
    std::cout << "2) Добавить прямоугольник" << std::endl;
    std::cout << "3) Добавить квадрат" << std::endl;
    std::cout << "4) Удалить по критерию" << std::endl;
    std::cout << "5) Вывести фигуры"  << std::endl;
    std::cout << "0) Выйти" << std::endl;
}

int main(void)
{
    TStack<TList<Figure>, std::shared_ptr<Figure> > stack;
    int act, index;
    Trapeze tmp1;
    Rhomb tmp2;
    Pentagon tmp3;

    do {
        menu();
        std::cin >> act;
        switch(act) {
            case 1:
                std::cin >> tmp1;
                stack.push(std::make_shared<Trapeze>(tmp1));
                std::cout << "Добавлен элемент" << std::endl;
                break;
            case 2:
                tmp2.setParams(std::cin);
                stack.push(std::make_shared<Rhomb>(tmp2));
                std::cout << "Добавлен элемент" << std::endl;
                break;
            case 3:
                tmp3.setParams(std::cin);
                stack.push(std::make_shared<Pentagon>(tmp3));
                std::cout << "Добавлен элемент" << std::endl;
                break;
            case 4:{
                std::cout << "Введите критерий" << std::endl;
                std::cout << "1) По типу\n2) По площади\n";
                std::cin >> index;
                if (index == 1) {
                    std::cout << "1) Трапеция\n2) Прямоугольник\n3) Квадрат\n";
                    std::cout << "Введите тип" << std::endl;
                    std::cin >> index;
                    stack.removeByType(index);
                } else if (index == 2) {
                    double sqr = 0.0;
                    std::cout << "Введите площадь" << std::endl;
                    std::cin >> sqr;
                    stack.removeLesser(sqr);
                } else {
                    break;
                }
                break;
            }
            case 5:
                stack.print();
                break;
            case 0:
                break;
            default:
                std::cout << "Неверная команда" << std::endl;;
                break;
        }

    } while(act);

    return 0;
}