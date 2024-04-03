#include <iostream>
#include <cstdlib>
#include "Array.hpp"
#include "Array.tpp"

int main(){

	Array<int> tab(6);
	Array<int> mirror(6);

	try{
	std::cout << "----------------------------------------------" << std::endl;

	for (unsigned int i = 0; i < tab.size(); i++){
		std::cout << tab[i] << "  ";
	}
	std::cout << std::endl;

	for (unsigned int i = 0; i < mirror.size(); i++){
		std::cout << mirror[i] << "  ";
	}
	std::cout << std::endl;

	std::cout << "----------------------------------------------" << std::endl;

	tab[0] = 1;
	tab[1] = 5;
	tab[2] = 68;
	tab[3] = 777;
	tab[4] = 85;
	tab[5] = 5;

	mirror = tab;

	for (unsigned int i = 0; i < tab.size(); i++){
		std::cout << tab[i] << "  ";
	}
	std::cout << std::endl;

	for (unsigned int i = 0; i < mirror.size(); i++){
		std::cout << mirror[i] << "  ";
	}
	std::cout << std::endl;

	}
	catch (std::exception& e){
		std::cout << e.what() << std::endl;
	}

	Array<char> arr(6);
	Array<char> mirror2(6);

	try{
	std::cout << "----------------------------------------------" << std::endl;

	for (unsigned int i = 0; i < arr.size(); i++){
		std::cout << arr[i] << "  ";
	}
	std::cout << std::endl;

	for (unsigned int i = 0; i < mirror2.size(); i++){
		std::cout << mirror2[i] << "  ";
	}
	std::cout << std::endl;

	std::cout << "----------------------------------------------" << std::endl;

	arr[0] = 'a';
	arr[1] = 'b';
	arr[2] = ' ';
	arr[3] = '5';
	arr[4] = 'G';
	arr[5] = '-';

	mirror2 = arr;

	for (unsigned int i = 0; i < arr.size(); i++){
		std::cout << arr[i] << "  ";
	}
	std::cout << std::endl;

	for (unsigned int i = 0; i < mirror2.size(); i++){
		std::cout << mirror2[i] << "  ";
	}
	std::cout << std::endl;

	}
	catch (std::exception& e){
		std::cout << e.what() << std::endl;
	}

	try{
		tab[9] = 98;
	}
	catch (std::exception& e){
		std::cout << e.what() << std::endl;
	}

	try{
		arr[-6] = 98;
	}
	catch (std::exception& e){
		std::cout << e.what() << std::endl;
	}

	return (0);
}

/*#include <iostream>
#include "Array.hpp"
#include "Array.tpp"

#define MAX_VAL 750
int main(int, char**)
{
	Array<int> numbers(MAX_VAL);
	int* mirror = new int[MAX_VAL];
	srand(time(NULL));
	for (int i = 0; i < MAX_VAL; i++)
	{
		const int value = rand();
		numbers[i] = value;
		mirror[i] = value;
	}
	//SCOPE
	{
		Array<int> tmp = numbers;
		Array<int> test(tmp);
	}

	for (int i = 0; i < MAX_VAL; i++)
	{
		if (mirror[i] != numbers[i])
		{
			std::cerr << "didn't save the same value!!" << std::endl;
			return 1;
		}
	}
	try
	{
		numbers[-2] = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		numbers[MAX_VAL] = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	for (int i = 0; i < MAX_VAL; i++)
	{
		numbers[i] = rand();
	}
	delete [] mirror;//
	return 0;
}*/