#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main()
{
const Animal* meta = new Animal();
const Animal* j = new Dog();
const Animal* i = new Cat();
std::cout << j->getType() << " " << std::endl;
std::cout << i->getType() << " " << std::endl;
i->makeSound(); //will output the cat sound!
j->makeSound();
meta->makeSound();
const WrongAnimal* Wmeta = new WrongAnimal();
const WrongAnimal* Wi = new WrongCat();
std::cout << Wmeta->getType() << " " << std::endl;
std::cout << Wi->getType() << " " << std::endl;
Wmeta->makeSound();
Wi->makeSound();
delete(meta);
delete(j);
delete(i);
delete(Wmeta);
delete(Wi);
return (0);
}