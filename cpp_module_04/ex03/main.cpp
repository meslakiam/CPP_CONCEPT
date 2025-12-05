#include "MateriaSource.hpp"
#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"


void test1()
{
    IMateriaSource* src = new MateriaSource();

    src->learnMateria(new Ice());
    src->learnMateria(new Cure());

    ICharacter* me = new Character("me");

    AMateria* tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);

    ICharacter* bob = new Character("bob");

    me->use(0, *bob);
    me->use(1, *bob);

    delete bob;
    delete me;
    delete src;
}

void test2()
{
    ICharacter * c = new Character("ilyas");

    Cure *cure = new Cure;
    Ice *ice = new Ice;
    AMateria *me = new Ice;
    c->equip(cure);
    c->equip(ice);
    c->equip(new Ice);
    c->equip(new Cure);
    c->equip(me);
    c->use(0,*c);
    c->use(1,*c);
    c->use(2,*c);
    c->use(3,*c);
    c->use(4,*c);
    c->use(-1,*c);
    c->use(406664569,*c);
    delete me;
    delete c;

}

void test3()
{
    IMateriaSource  *src = new MateriaSource;

    AMateria *cure = new Cure;
    src->learnMateria(new Ice);
    src->learnMateria(new Cure);
    src->learnMateria(new Cure);
    src->learnMateria(new Ice);
    src->learnMateria(cure);
    delete cure;

    AMateria *c = src->createMateria("Ice");
    c = src->createMateria("cure");
    std::cout << c->getType() << std::endl;
    delete c;
    c = src->createMateria("ice");
    std::cout << c->getType() << std::endl;
    delete c;
    c = src->createMateria("fhd");
    if(!c)
        std::cout << "c is 0" << std::endl;
    delete src;
}

void test4()
{
    ICharacter *me = new Character("ilyas");

    Cure *cure = new Cure;
    Ice *ice = new Ice;
    AMateria *materia = new Ice;

    me->unequip(0);
    me->use(0, *me);
    std::cout << "----------" << std::endl;
    me->equip(cure);
    me->equip(ice);
    me->equip(materia);

    me->use(0,*me);
    me->use(1,*me);
    me->use(2,*me);
    std::cout << "----------" << std::endl;

    me->unequip(0);
    me->unequip(1);
    me->unequip(2);
    me->unequip(3);
    me->unequip(46785);
    me->unequip(-46);

    me->use(0,*me);
    me->use(1,*me);
    me->use(2,*me);
    ice->use(*me);
    cure->use(*me);

    delete materia;
    delete cure;
    delete ice;
    delete me;
}


int main()
{
    test1();
    // test2();
    // test3();
    // test4();

    return 0;
}