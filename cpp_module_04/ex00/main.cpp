#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"


void test1()
{
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    std::cout << "------------------" << std::endl;
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    std::cout << "------------------" << std::endl;

    i->makeSound();
    j->makeSound();
    meta->makeSound();
    std::cout << "------------------" << std::endl;

    delete meta;
    delete j;
    delete i;
}

void test2()
{
    const WrongAnimal* i = new WrongCat();

    std::cout << "------------------" << std::endl;
    i->makeSound();
    std::cout << "------------------" << std::endl;

    delete i;
}

void test3()
{
    Animal  meta;
    Cat     cat;
    Dog     dog;

    std::cout << "------------------" << std::endl;
    std::cout << "\"" << meta.getType() << "\"" << std::endl;
    std::cout << "\""  << cat.getType() << "\"" << std::endl;
    std::cout << "\""  << dog.getType() << "\"" << std::endl;
    std::cout << "------------------" << std::endl;
}

void test4()
{
    Animal  meta;
    Cat     cat;
    Dog     dog;

    std::cout << "------------------" << std::endl;
    meta.makeSound();
    cat.makeSound();
    dog.makeSound();
    std::cout << "------------------" << std::endl;
}

void test5()
{
    Cat cat1;
    Cat cat2(cat1);
    Dog dog1;
    Dog dog2(dog1);

    std::cout << "------------------" << std::endl;
    std::cout << "\""  << cat2.getType() << "\"" << std::endl;
    std::cout << "\""  << dog2.getType() << "\"" << std::endl;
    std::cout << "------------------" << std::endl;

    cat2.makeSound();
    dog2.makeSound();
    std::cout << "------------------" << std::endl;
}

void test6()
{
    Cat cat1;
    Cat cat2;

    cat1 = cat2;

    std::cout << "------------------" << std::endl;
    std::cout << "\""  << cat1.getType() << "\"" << std::endl;
    std::cout << "\""  << cat2.getType() << "\"" << std::endl;
    std::cout << "------------------" << std::endl;

    cat1.makeSound();
    cat2.makeSound();
    std::cout << "------------------" << std::endl;
}


int main()
{
    test1();
    // test2();
    // test3();
    // test4();
    // test5();
    // test6();
}