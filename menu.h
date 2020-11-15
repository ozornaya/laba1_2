#ifndef MENU_H
#define MENU_H
#include "dish.h"
#include <string>

struct list
{
    dish field;        //поле данных
    list *next, *prev; //предыдущий и следующий
};

class menu //класс коллекции
{
public:
    menu();              //конструктор по умолчанию
    menu(const menu& m); //конструктор копирования

    int add_head(dish i);
    int add_tail(dish i);
    int add(dish i, int number); //метод добавления

    int cancel(int index);       //метод удаления
    int clean();                 //метод удаляющий всё
    int get_size();              //метод возвращающий число

    void set_iterator_index(int index);
    void set_iterator_value(dish i);
    int get_iterator_index();
    dish get_iterator_value();

    int from_file(const string &name);
    int to_file(const string &name);

    bool operator == (const menu&);

private:
    pair<int,dish> iterator;
    list *list_;
    list *head, *tail; //начало и конец списка
    int size;
};

#endif // MENU_H
