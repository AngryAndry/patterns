#pragma once
#include <iostream>
#include "Case.h"
//http://cpp-reference.ru/patterns/creational-patterns/builder/
//https://www.bestprog.net/ru/2020/10/12/patterns-builder-pattern-review-and-research-implementation-in-c-ru/
using namespace std;
class Builder
{
public:
    virtual void CreateProduct() { }
    virtual void BuildName(const string& name) { }
    virtual void BuildTag(const string& tag) { }
    virtual void BuildDate(const string& date) { }
    virtual void BuildPiorite(int priorite) { }
    virtual void BuildClarification(const string& clarification){}
    virtual Case* GetResult() { return nullptr; }
};


class ConcreteBuilder : public Builder
{
private:
    Case* product;

public:
    ConcreteBuilder()
    {
        product = nullptr;
    }

    void CreateProduct()
    {
        product = new Case();
    }

    void BuildName(const string& name)override    {

        product->setName(name);
    }

    virtual void BuildTag(const string& tag)override {
        product->setTag(tag);
    }  
    void BuildPiorite(int priorite)override {
        product->setPriorite(priorite);
    }
     void BuildDate(const string& date)override {
         product->setDate(date);
    } 
    void BuildClarification(const string& clarification)override {
        product->setClarification(clarification);
    }

    // Метод, возвращающий продукт для клиента
    virtual Case* GetResult()override
    {
        return product;
    }

    // Деструктор
   /* ~ConcreteBuilder()
    {
        if (product != nullptr)
            delete product;
    }*/
};



