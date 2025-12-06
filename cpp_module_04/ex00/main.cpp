#include "Cat.hpp"
#include "Dog.hpp"


void test1()
{
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;

    i->makeSound();
    j->makeSound();
    meta->makeSound();

    delete meta;
    delete j;
    delete i;
}

void test2()
{
    Animal  meta;
    Cat     cat;
    Dog     dog;

    std::cout << "\"" << meta.getType() << "\"" << std::endl;
    std::cout << "\""  << cat.getType() << "\"" << std::endl;
    std::cout << "\""  << dog.getType() << "\"" << std::endl;
}

void test3()
{
    Animal  meta;
    Cat     cat;
    Dog     dog;

    meta.makeSound();
    cat.makeSound();
    dog.makeSound();
}

void test4()
{
    Cat cat1;
    Cat cat2(cat1);
    Dog dog1;
    Dog dog2(dog1);

    std::cout << "\""  << cat2.getType() << "\"" << std::endl;
    std::cout << "\""  << dog2.getType() << "\"" << std::endl;
    cat2.makeSound();
    dog2.makeSound();
}

void test5()
{
    Cat cat1;
    Cat cat2;

    cat1 = cat2;

    std::cout << "\""  << cat1.getType() << "\"" << std::endl;
    std::cout << "\""  << cat2.getType() << "\"" << std::endl;

    cat1.makeSound();
    cat2.makeSound();
}


int main()
{
    test1();
    // test2();
    // test3();
    // test4();
    // test5();
}