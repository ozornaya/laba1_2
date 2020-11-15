#include "menu.h"
#include <fstream>

menu::menu()
{
    this->list_ = new list;
    this->head = NULL;
    this->tail = NULL;
    this->size = 0;

    this->iterator.first = 0;
    this->iterator.second = this->list_->field;
}

menu::menu(const menu& m)
{
    this->head = NULL;
    this->tail = NULL;
    this->size = m.size;
    list *temp = m.head;

    while(temp != 0) //пока не конец списка перебираем все значения
    {
        add_tail(temp->field);
        temp = temp->next;
    }

    this->iterator = m.iterator;
    this->size = m.size;
}

int menu::add_head(dish i)
{
    list *temp = new list; //добавление нового элемента
    temp->prev = 0;        //предыдущего нет
    temp->field = i;       //вводим наши данные
    temp->next = head;     //следующий-бывшая голова

    if (head != 0)
        head->prev = temp;
    if (this->size == 0)   //если элемент первый, то он-голова и хвост
        head = tail = temp;
    else
        head = temp;       //иначе новый элемент-голова

    iterator.first++;
    this->iterator.second = i;
    this->size++;
    return 0;
}

int menu::add_tail(dish i)
{
    list *temp = new list;
    temp->next = 0;
    temp->field = i;
    temp->prev = tail;

    if(tail != 0)
        tail->next = temp;
    if(this->size == 0)    //если элемент первый, то он-голова и хвост
        head = tail = temp;
    else
        tail = temp;       //иначе новый элемент-хвост

    iterator.first++;
    this->iterator.second = i;
    this->size++;
    return 0;
}

int menu::add(dish i, int pos)
{
    if (pos == this->size+1)
    {
        add_tail(i); //добавление в конец списка
        return 0;
    }
    else if (pos == 1)
    {
        add_head(i); //добавление в начало списка
        return 0;
    }
    int s = 1; //счётчик
    list *insert = head; //отсчитываем от головы n-1 элементов

    while (s < pos)
    {
        insert = insert->next; //доходим до элемента перед которым вставляемся
        s++;
    }

    list *prev_insert = insert->prev; //доходим до элемента который предшествует
    list *temp = new list;            //добавляем новый элемент
    temp->field = i;

    if (prev_insert != 0 && this->size != 1)
        prev_insert = temp;

    temp->next = insert;
    temp->prev = prev_insert;
    insert->prev = temp;

    iterator.first++;
    this->iterator.second = i;
    this->size++;
    return 0;
}

int menu::cancel(int index)
{
    if ((index == 1) and (this->head->next)) //Если удаляем первый и он не единственный
    {
        list *temp = this->head;
        this->head = this->head->next;
        this->head->prev = NULL;
        delete temp;
        this->size--;
        return 0;
    }
    else if ((index == 1) and (this->head == this->tail)) //Если удаляем первый и он единственный
    {
        this->head->next = NULL;
        this->head = NULL;
        delete this->head;
        this->size = 0;
        return 0;
    }
    if (index == this->size) //Если удаляемый последний элемент и он не единственный
    {
        list *temp = this->tail;
        this->tail = this->tail->prev;
        this->tail->next = NULL;
        delete temp;
        this->size--;
        return 0;
    }
    //Если удаляемый элемент в середине списка
    list *temp = this->head, *tempx; //temp-Удаляемый элемент, tempx-переменная для данных, чтоб они не потерялись
    for (int s=0; s<index-1; s++)
        temp = temp->next;
    tempx = temp;
    tempx->prev->next = temp->next;
    tempx->next->prev = temp->prev;
    delete temp;

    if (this->iterator.first >= this->size)
                    this->iterator.first = this->size - 1;
    for (int i=0; i<this->iterator.first-1; i++) this->list_ = this->list_->next;
    this->iterator.second = this->list_->field;
    this->size--;

    return 0;
}

int menu::clean()
{
    while (this->head)
    {
        this->tail = this->head->next;
        delete this->head;
        this->head = this->tail;
    }
    this->list_ = new list;
    this->head = NULL;
    this->tail = NULL;
    this->size = 0;
    return 0;
}

int menu::get_size()
{
    return this->size;
}

void menu::set_iterator_index(int index)
{
    if (this->iterator.first != index && index < this->size+1 && index >= 0){
            this->iterator.first = index;

            int i=0;
            list *temp = head;
            while(i != index-1) { temp = temp->next; i++;}

            this->iterator.second = temp->field;
        }
}

void menu::set_iterator_value(dish i)
{
    int s = 0;
    list *temp = head;
    while (s != get_iterator_index()-1)
    {
        temp = temp->next;
        s++;
    }
    temp->field = i;
    this->iterator.second = i;
}

int menu::get_iterator_index()
{
    return this->iterator.first;
}

dish menu::get_iterator_value()
{
    return this->iterator.second;
}

int menu::from_file(const string &fname)
{
    string name;                  //название блюда
    int weight;                   //вес блюда
    float fat_content;            //содержание жиров на 100 грамм блюда
    float protein_content;        //содержание белков на 100 грамм блюда
    float carbohydrate_content;   //содержание углеводов на 100 грамм блюда
    float organic_acid_content;   //содержание органических кислот на 100 грамм блюда
    float dietary_fibers_content; //содержание пищевых волокон на 100 грамм блюда
    //float energy_value();         //функция рассчёта энергетической функции на 100 грамм блюда

    ifstream file(fname);

    if (this->size > 0)
    {
        this->clean();
        this->iterator.first = 0;
    }
    if (file.is_open())
    {
        while (file >> name >> weight >> fat_content >> protein_content >> carbohydrate_content >> organic_acid_content >> dietary_fibers_content)
        {
            dish i(name, weight, fat_content, protein_content, carbohydrate_content, organic_acid_content, dietary_fibers_content);
            //условие if пропустил
        }
        file.close();
    }
    return 0;
}

int menu::to_file(const string &fname)
{
    ofstream fout(fname);

    for (int s = 1; s < int(this->size+1); s++)
    {
        this->set_iterator_index(s);
        fout << this->get_iterator_value().get_name() << " " << this->get_iterator_value().get_weight() << endl <<this->get_iterator_value().get_fat_content() << endl << this->get_iterator_value().get_protein_content() << endl << this->get_iterator_value().get_carbohydrate_content() << endl << this->get_iterator_value().get_organic_acid_content() << endl << this->get_iterator_value().get_dietary_fibers_content() << endl;
    }
    fout.close();
    return 0;
}

bool menu::operator == (const menu& m) //проверка двух коллекций на равенство
{
    if (this->size != m.size) //сравнение по количеству
        return false;
    list *t1, *t2;
    t1 = head;
    t2 = m.head;

    while(t1 != 0)            //сравнение по содержанию
    {
        if (t1->field.get_name() != t2->field.get_name() && t1->field.get_weight() != t2->field.get_weight() && t1->field.get_fat_content() != t2->field.get_fat_content() && t1->field.get_protein_content() != t2->field.get_protein_content() && t1->field.get_carbohydrate_content() != t2->field.get_carbohydrate_content() && t1->field.get_organic_acid_content() != t2->field.get_organic_acid_content() && t1->field.get_dietary_fibers_content() != t2->field.get_dietary_fibers_content())
            return false;
        t1 = t1->next;
        t2 = t2->next;
    }
    return true;
}
