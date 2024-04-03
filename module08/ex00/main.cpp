#include "easyfind.tpp"

#include <vector>
#include <list>

int main() {
	std::vector<int> vec = {1, 2, 3, 4, 5};
	std::list<int> myList = {10, 20, 30, 40, 50};

	int searchValue = 3;

	auto vecIt = easyfind(vec, searchValue);
	if (vecIt != vec.end()) {
		std::cout << "Value " << searchValue << " found in vector at position: " << std::distance(vec.begin(), vecIt) << std::endl;
	} else {
		std::cout << "Value " << searchValue << " not found in vector." << std::endl;
	}

	auto listIt = easyfind(myList, searchValue);
	if (listIt != myList.end()) {
		std::cout << "Value " << searchValue << " found in list at position: " << std::distance(myList.begin(), listIt) << std::endl;
	} else {
		std::cout << "Value " << searchValue << " not found in list." << std::endl;
	}

	return 0;
}