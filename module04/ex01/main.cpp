#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main()
{
const Animal* j = new Dog();
const Animal* i = new Cat();
delete j;//should not create a leak
delete i;
std::cout << "-------------------------------------" << std::endl;
const Animal* animals[4] = { new Dog(), new Dog(), new Cat(), new Cat() };
	for ( int i = 0; i < 4; i++ ) {
		delete animals[i];
	}
std::cout << "-------------------------------------" << std::endl;
const Dog a;
const Dog b(a);
std::cout << "-------------------------------------" << std::endl;
const Cat c;
const Cat d(c);
}