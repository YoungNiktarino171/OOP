#include <cstdlib>
#include "Trapeze.h"
#include "Square.h"
#include "Rectangle.h"

void option(Figure *figure) {
    figure->Print();
    std::cout << "Площадь: " << figure->SQUARE() << std::endl;
    delete figure;
}

int print_help(){
    std::cout << "Меню\n" << std::endl;
    std::cout << "1. Трапеция\n"
              << "2. Квадрат\n"
              << "3. Прямоугольник\n"
              << "4. Помощь\n"
              << "5. Выход\n" << std::endl;
}


int main(int argc, char* argv[])
{
    print_help();
    int variant;
    while(true){
    std::cin >> variant;
        switch(variant) {
            case 1:
            std::cout << "Трапеция" << std::endl;
                option(new Trapeze(std::cin));
                break;
            case 2:
            std::cout << "Квадрат" << std::endl;
                option(new Square(std::cin));
                break;
            case 3:
            std::cout << "Прямоугольник" << std::endl;
                option(new Rectangle(std::cin));
                break;
            case 4:
                print_help();
                break;  
            case 5:
                std::cout << "Выход" << std::endl;
                exit(EXIT_SUCCESS);
                break;
            default:
                std::cerr << "Ошибка" << std::endl;
                exit(EXIT_FAILURE);
        }
    }
}




