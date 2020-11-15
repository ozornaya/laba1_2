#ifndef DISH_H
#define DISH_H
#include <iostream>
using namespace std;

class dish
{
public: //модификатор доступа

    //заголовки конструкторов
    dish(string name, int weight, float fat_content, float protein_content, float carbohydrate_content, float organic_acid_content, float dietary_fibers_content);
    dish(const dish& i);
    dish();

    string get_name();
    void set_name(string name);

    int get_weight();
    void set_weight(int weight);

    float get_fat_content();
    void set_fat_content(float fat_content);

    float get_protein_content();
    void set_protein_content(float protein_content);

    float get_carbohydrate_content();
    void set_carbohydrate_content(float carbohydrate_content);

    float get_organic_acid_content();
    void set_organic_acid_content(float organic_acid_content);

    float get_dietary_fibers_content();
    void set_dietary_fibers_content(float dietary_fibers_content);

    float energy_value(); //функция рассчёта энергетической функции на 100 грамм блюда

private:                          //модификатор доступа

    string name;                  //название блюда
    int weight;                   //вес блюда
    float fat_content;            //содержание жиров на 100 грамм блюда
    float protein_content;        //содержание белков на 100 грамм блюда
    float carbohydrate_content;   //содержание углеводов на 100 грамм блюда
    float organic_acid_content;   //содержание органических кислот на 100 грамм блюда
    float dietary_fibers_content; //содержание пищевых волокон на 100 грамм блюда
};

#endif // DISH_H
