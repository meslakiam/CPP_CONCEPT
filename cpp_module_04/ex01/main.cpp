#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"


void test1()
{
    Animal A;

    const Dog* j = new Dog();
    const Cat* i = new Cat();

    std::cout << "------------------" << std::endl;
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    std::cout << "------------------" << std::endl;

    A.makeSound();
    i->makeSound();
    j->makeSound();
    std::cout << "------------------" << std::endl;

    delete j;
    delete i;
}

void test2()
{
    Cat     cat;
    Dog     dog;

    std::cout << "------------------" << std::endl;
    std::cout << "\""  << cat.getType() << "\"" << std::endl;
    std::cout << "\""  << dog.getType() << "\"" << std::endl;
    std::cout << "------------------" << std::endl;
}

void test3()
{
    Cat     cat;
    Dog     dog;

    std::cout << "------------------" << std::endl;
    cat.makeSound();
    dog.makeSound();
    std::cout << "------------------" << std::endl;
}

void test4()
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

void test5()
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

void test6()
{
    Animal *animals[10];

    for (size_t i = 0; i < 5; i++)
        animals[i] = new Cat();

    for (size_t i = 5; i < 10; i++)
        animals[i] = new Dog();

    std::cout << "------------------" << std::endl;
    for (size_t i = 0; i < 10; i++)
        std::cout << animals[i]->getType() << std::endl;
    std::cout << "------------------" << std::endl;

    for (size_t i = 0; i < 10; i++)
        delete animals[i];

}

void HelperTest7(Dog& dog1)
{
    Dog dog2;

    dog2 = dog1;
}
void    test7()
{
    Dog dog1;

    HelperTest7(dog1);
    dog1.makeSound();
}

int main()
{
    test1();
    // test2();
    // test3();
    // test4();
    // test5();
    // test6();
    // test7();
}