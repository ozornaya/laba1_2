#include "dish.h"
using namespace std;

dish::dish(string name, int weight, float fat_content, float protein_content, float carbohydrate_content, float organic_acid_content, float dietary_fibers_content)
{
    this->name = name;

    if (weight > 0)
        this->weight = weight;
    else
        this->weight = 0;

    if (fat_content > 0)
        this->fat_content = fat_content;
    else
        this->fat_content = 0;

    if (protein_content > 0)
        this->protein_content = protein_content;
    else
        this->protein_content = 0;

    if (carbohydrate_content > 0)
        this->carbohydrate_content = carbohydrate_content;
    else
        this->carbohydrate_content = 0;

    if(organic_acid_content > 0)
        this->organic_acid_content = organic_acid_content;
    else
        this->organic_acid_content = 0;

    if(dietary_fibers_content > 0)
        this->dietary_fibers_content = dietary_fibers_content;
    else
        this->dietary_fibers_content = 0;
}

dish::dish(const dish& i)
{
    this->name                   = i.name;
    this->weight                 = i.weight;
    this->fat_content            = i.fat_content;
    this->protein_content        = i.protein_content;
    this->carbohydrate_content   = i.carbohydrate_content;
    this->organic_acid_content   = i.organic_acid_content;
    this->dietary_fibers_content = i.dietary_fibers_content;
}

dish::dish()
{
    this->name                   = "";
    this->weight                 = 0;
    this->fat_content            = 0;
    this->protein_content        = 0;
    this->carbohydrate_content   = 0;
    this->organic_acid_content   = 0;
    this->dietary_fibers_content = 0;
}

//методы класса
string dish::get_name()
{
    return this->name;
}
void dish::set_name(string name)
{
    this->name = name;
}

int dish::get_weight()
{
    return this->weight;
}
void dish::set_weight(int weight)
{
    if (weight > 0)
        this->weight = weight;
    else
        this->weight = 0;
}

float dish::get_fat_content()
{
    return this->fat_content;
}
void dish::set_fat_content(float fat_content)
{
    if (fat_content > 0)
        this->fat_content = fat_content;
    else
        this->fat_content = 0;
}

float dish::get_protein_content()
{
    return this->protein_content;
}
void dish::set_protein_content(float protein_content)
{
    if (protein_content > 0)
        this->protein_content = protein_content;
    else
        this->protein_content = 0;
}

float dish::get_carbohydrate_content()
{
    return this->carbohydrate_content;
}
void dish::set_carbohydrate_content(float carbohydrate_content)
{
    if (carbohydrate_content > 0)
        this->carbohydrate_content = carbohydrate_content;
    else
        this->carbohydrate_content = 0;
}

float dish::get_organic_acid_content()
{
    return this->organic_acid_content;
}
void dish::set_organic_acid_content(float organic_acid_content)
{
    if(organic_acid_content > 0)
        this->organic_acid_content = organic_acid_content;
    else
        this->organic_acid_content = 0;
}

float dish::get_dietary_fibers_content()
{
    return this->dietary_fibers_content;
}
void dish::set_dietary_fibers_content(float dietary_fibers_content)
{
    if(dietary_fibers_content > 0)
        this->dietary_fibers_content = dietary_fibers_content;
    else
        this->dietary_fibers_content = 0;
}

float dish::energy_value()
{
    return this->fat_content*9.29 + this->protein_content*4.1 + this->carbohydrate_content*4.1 + this->organic_acid_content*2.2 + this->dietary_fibers_content*1.9;
}
