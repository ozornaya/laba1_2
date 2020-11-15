#include <iostream>
#include <stdio.h>
#include "dish.h"
#include "menu.h"
#include <cassert>
using namespace std;

int output(menu m)
{
    for (int s = 1; s < int(m.get_size()+1); s++)
    {
        m.set_iterator_index(s);
        cout << s << " Name: " << m.get_iterator_value().get_name() << " Weight: " << m.get_iterator_value().get_weight() << " Fat content: " << m.get_iterator_value().get_fat_content() << " Protein content: " << m.get_iterator_value().get_protein_content() << " Carbohydrate content: " << m.get_iterator_value().get_carbohydrate_content() << " Organic acid content: " << m.get_iterator_value().get_organic_acid_content() << "Fibers content: " << m.get_iterator_value().get_dietary_fibers_content() << endl;
    }
    cout << '\n' << endl;
    return 0;
}

int main()
{
    //Тесты для 1 части

    dish dish_one("", 0, 0, 0, 0, 0, 0);
    assert(dish_one.get_name() == "");
    assert(dish_one.get_weight() == 0);
    assert(dish_one.get_fat_content() == 0);
    assert(dish_one.get_protein_content() == 0);
    assert(dish_one.get_carbohydrate_content() == 0);
    assert(dish_one.get_organic_acid_content() == 0);
    assert(dish_one.get_dietary_fibers_content() == 0);
    cout<<"Energy value: "<< dish_one.energy_value() << '\n';

    dish dish_two("Bludo1", 400, 20.5, 8.1, 45.2, 2.9, 2.5);
    assert(dish_two.get_name() == "Bludo1");
    assert(dish_two.get_weight() == 400);
    assert(dish_two.get_fat_content() == 20.5f);
    assert(dish_two.get_protein_content() == 8.1f);
    assert(dish_two.get_carbohydrate_content() == 45.2f);
    assert(dish_two.get_organic_acid_content() == 2.9f);
    assert(dish_two.get_dietary_fibers_content() == 2.5f);
    cout<<"Energy value of Bludo1: "<< dish_two.energy_value() << '\n';

    dish dish_three(dish_two);
    assert(dish_three.get_name() == dish_two.get_name());
    assert(dish_three.get_weight() == dish_two.get_weight());
    assert(dish_three.get_fat_content() == dish_two.get_fat_content());
    assert(dish_three.get_protein_content() == dish_two.get_protein_content());
    assert(dish_three.get_carbohydrate_content() == dish_two.get_carbohydrate_content());
    assert(dish_three.get_organic_acid_content() == dish_two.get_organic_acid_content());
    assert(dish_three.get_dietary_fibers_content() == dish_two.get_dietary_fibers_content());
    cout<<"Energy value of Bludo2: "<< dish_three.energy_value() << '\n';


    dish_one.set_name("Bludo3");
    assert(dish_one.get_name() == "Bludo3");

    dish_one.set_weight(200);
    assert(dish_one.get_weight() == 200);

    dish_one.set_fat_content(8.5);
    assert(dish_one.get_fat_content() == 8.5f);

    dish_one.set_protein_content(23.8);
    assert(dish_one.get_protein_content() == 23.8f);

    dish_one.set_carbohydrate_content(14.3);
    assert(dish_one.get_carbohydrate_content() == 14.3f);

    dish_one.set_organic_acid_content(2.4);
    assert(dish_one.get_organic_acid_content() == 2.4f);

    dish_one.set_dietary_fibers_content(1.7);
    assert(dish_one.get_dietary_fibers_content() == 1.7f);

    cout<<"Energy value of Bludo3: "<< dish_one.energy_value() << '\n';


    //Тесты для 2 части

    //тест конструктора по умолчанию
    menu m_default;
    assert(m_default.get_iterator_index() == 0);
    assert(m_default.get_iterator_value().get_name()=="" && m_default.get_iterator_value().get_weight()==0 && m_default.get_iterator_value().get_fat_content()==0 && m_default.get_iterator_value().get_protein_content()==0 && m_default.get_iterator_value().get_carbohydrate_content()==0 && m_default.get_iterator_value().get_organic_acid_content()==0 && m_default.get_iterator_value().get_dietary_fibers_content()==0);
    assert(m_default.get_size() == 0);

    //тест конструктора копирования
    dish dish_four("Bludo4", 350, 10.5, 8.7, 40.2, 2.7, 1.9);
    m_default.add(dish_four, 1);
    menu m_copy(m_default);
    assert(m_copy == m_default);
    assert(m_copy.get_iterator_index() == m_default.get_iterator_index());
    assert(m_copy.get_iterator_value().get_name() == m_default.get_iterator_value().get_name() && m_copy.get_iterator_value().get_weight() == m_default.get_iterator_value().get_weight() &&
           m_copy.get_iterator_value().get_fat_content() == m_default.get_iterator_value().get_fat_content() && m_copy.get_iterator_value().get_protein_content() == m_default.get_iterator_value().get_protein_content() &&
           m_copy.get_iterator_value().get_carbohydrate_content() == m_default.get_iterator_value().get_carbohydrate_content() && m_copy.get_iterator_value().get_organic_acid_content() == m_default.get_iterator_value().get_organic_acid_content()
           && m_copy.get_iterator_value().get_dietary_fibers_content() == m_default.get_iterator_value().get_dietary_fibers_content());
    assert(m_copy.get_size() == m_default.get_size());

    //тест методов добавления и удаления объектов
    dish dish_five("Bludo5", 300, 9.5, 12.7, 37.0, 2.2, 2.1);
    m_default.add(dish_five, 2);
    assert(m_default.get_iterator_value().get_name() == "Bludo5" && m_default.get_iterator_value().get_weight() == 300 && m_default.get_iterator_value().get_fat_content() == 9.5f &&
           m_default.get_iterator_value().get_protein_content() == 12.7f && m_default.get_iterator_value().get_carbohydrate_content() == 37.0f && m_default.get_iterator_value().get_organic_acid_content() == 2.2f &&
           m_default.get_iterator_value().get_dietary_fibers_content() == 2.1f);
    assert(m_default.get_size() == 2);
    m_default.cancel(2);

    m_default.set_iterator_index(1);
    assert(m_default.get_iterator_value().get_name() == "Bludo4" && m_default.get_iterator_value().get_weight() == 350 && m_default.get_iterator_value().get_fat_content() == 10.5f &&
           m_default.get_iterator_value().get_protein_content() == 8.7f && m_default.get_iterator_value().get_carbohydrate_content() == 40.2f && m_default.get_iterator_value().get_organic_acid_content() == 2.7f &&
           m_default.get_iterator_value().get_dietary_fibers_content() == 1.9f);
    assert(m_default.get_size() == 1);

    m_default.add(dish_two, 1);
    assert(m_default.get_iterator_value().get_name() == "Bludo1" && m_default.get_iterator_value().get_weight() == 400 && m_default.get_iterator_value().get_fat_content() == 20.5f &&
           m_default.get_iterator_value().get_protein_content() == 8.1f && m_default.get_iterator_value().get_carbohydrate_content() == 45.2f && m_default.get_iterator_value().get_organic_acid_content() == 2.9f &&
           m_default.get_iterator_value().get_dietary_fibers_content() == 2.5f);
    assert(m_default.get_size() == 2);
    m_default.cancel(1);
    m_default.cancel(1);
    assert(m_default.get_size() == 0);

    //тест метода доступа к элементу, вывод на экран объектов
    m_default.add(dish_two, 1);
    m_default.add(dish_four, 1);
    m_default.add(dish_five, 1);
    assert(output(m_default) == 0);

    //тест метода удаления всех объектов
    m_default.clean();
    assert(m_default.get_size() == 0);

    //тест метода записи в файл и чтения из файла
    dish dish_six("Bludo6", 200, 12.6, 10.4, 34.8, 2.0, 2.4);
    menu m_to_file;
    m_to_file.add(dish_six, 1);
    assert(m_to_file.to_file("/Users/mariaozornina/Desktop/laba/test.txt") == 0);
    menu m_from_file;
    assert(m_from_file.from_file("/Users/mariaozornina/Desktop/laba/test.txt") == 0);
    assert(m_from_file == m_to_file);
}


