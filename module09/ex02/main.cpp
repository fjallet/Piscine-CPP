#include <list>
#include <algorithm>
#include <iostream>
#include "PmergeMe.hpp"


/*int main() {
	// Exemple d'utilisation
	int s = 5;
	int	vect[] = {5, 2, 8, 1, 6};
	std::list<int> sequence;
	for (int i = 0; i != s; i++){
		sequence.push_back(vect[i]);
	}
	std::list<int> result = mergeList(sequence);
	
	// Affichage du résultat
	std::list<int>::iterator it = result.begin();
	for (; it != result.end(); it++) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
	std::cout << "------------------------------------" << std::endl;

	std::vector<int> sequence2;
	for (int i = 0; i != s; i++){
		sequence2.push_back(vect[i]);
	}
	std::vector<int> result2 = mergeVector(sequence2);

	std::vector<int>::iterator itv = result2.begin();
	for (; itv != result2.end(); itv++) {
		std::cout << *itv << " ";
	}
	std::cout << std::endl;
	return 0;
}*/

void	print_list(std::list<int> & a){
	std::list<int>::iterator it = a.begin();
	for (; it != a.end(); it++) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

void	print_vector(std::vector<int> & a){
	std::vector<int>::iterator itv = a.begin();
	for (; itv != a.end(); itv++) {
		std::cout << *itv << " ";
	}
	std::cout << std::endl;
}

int main(int argc, char *argv[])
{
	if (argc < 2) {
		std::cout << "Error: No arguments provided.\n";
		return 1;
	}

	std::vector<int> v;
	std::list<int> l;

	for (int i = 1; i < argc; ++i) {
		std::stringstream ss(argv[i]);
		int num;
		if (!(ss >> num) || !ss.eof()) {
			std::cout << "Error: Invalid input.\n";
			return 1;
		}
		if (num < 0){
			std::cout << "Error: Negative numbers are not allowed.\n";
			return 1;
		}
		v.push_back(num);
		l.push_back(num);
	}

	std::cout << "Before: ";
	print_list(l);
	//print_vector(v);

	std::clock_t startl = std::clock();
	l = mergeList(l);
	std::clock_t endl = std::clock();
	double elapsedl = 1000000.0 * (endl - startl) / CLOCKS_PER_SEC;
	
	std::clock_t startv = std::clock();
	v = mergeVector(v);
	std::clock_t endv = std::clock();
	double elapsedv = 1000000.0 * (endv - startv) / CLOCKS_PER_SEC;
	
	std::cout << "After: ";
	print_list(l);
	//print_vector(v);

	std::cout << "Time to process a range of " << v.size();
	std::cout << " elements with std::vector : " << elapsedv << " us" << std::endl;

	std::cout << "Time to process a range of " << l.size();
	std::cout << " elements with std::list : " << elapsedl << " us" << std::endl;

	return 0;
}