#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

#include <iostream>
#include <cstdlib>
#include <ctime>

Base * generate(void){
	std::srand(static_cast<unsigned int>(std::time(0)));
	int i = rand() % 3;
	switch(i){
		case 0:
			std::cout << "Class A generated" << std::endl;
			return (new A);
		case 1:
			std::cout << "Class B generated" << std::endl;
			return (new B);
		case 2:
			std::cout << "Class C generated" << std::endl;
			return (new C);
	}
	return (NULL);
}

void identify(Base* p){
	if (dynamic_cast<A*>(p) != NULL)
		std::cout << "Class type A" << std::endl;
	if (dynamic_cast<B*>(p) != NULL)
		std::cout << "Class type B" << std::endl;
	if (dynamic_cast<C*>(p) != NULL)
		std::cout << "Class type C" << std::endl;
}

void identify(Base& p){
	try{
		A&	temp = dynamic_cast<A&>(p);
		std::cout << "Class type A" << std::endl;
	}
	catch (...) {}
	try{
		B&	temp = dynamic_cast<B&>(p);
		std::cout << "Class type B" << std::endl;
	}
	catch (...) {}
	try{
		C&	temp = dynamic_cast<C&>(p);
		std::cout << "Class type C" << std::endl;
	}
	catch (...) {}
}

int	main(){
	Base *p = generate();
	identify(p);
	identify(*p);
	delete p;
	return (0);
}