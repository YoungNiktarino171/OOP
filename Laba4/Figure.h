#ifndef FIGURE_H
#define FIGURE_H
class Figure {//общий класс фсех фигур
public:// публичные функции, используемые и переопределенные для всех фигур

    virtual double SQUARE() = 0;//дабловская виртуальная функция подсчета лощади, точнее ее объявление, по умолчанию результат равен 0
    virtual void Print() = 0;//функция печати
    virtual ~Figure() {};
};

#endif /* FIGURE_H */