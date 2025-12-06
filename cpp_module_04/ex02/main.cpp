#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"


void test1()
{
    const Dog* j = new Dog();
    const Cat* i = new Cat();

    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;

    i->makeSound(); //will output the cat sound!
    j->makeSound();
}

void test2()
{
    Cat     cat;
    Dog     dog;

    std::cout << "\""  << cat.getType() << "\"" << std::endl;
    std::cout << "\""  << dog.getType() << "\"" << std::endl;
}

void test3()
{
    Cat     cat;
    Dog     dog;

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

void test6()
{
    AAnimal *animals[10];

    for (size_t i = 0; i < 5; i++)
        animals[i] = new Cat();

    for (size_t i = 5; i < 10; i++)
        animals[i] = new Dog();

    for (size_t i = 0; i < 10; i++)
        std::cout << animals[i]->getType() << std::endl;

    for (size_t i = 0; i < 10; i++)
        delete animals[i];

}

int main()
{
    // test1();
    // test2();
    // test3();
    // test4();
    // test5();
    test6();
}