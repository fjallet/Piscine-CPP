#include "PmergeMe.hpp"

std::list<int>	mergeList(std::list<int> & lst){
	if (lst.size() <= 1)
		return lst;

	int	a;
	int b;
	std::list<std::pair<int, int> > twins;
	std::list<int>::iterator it = lst.begin();
	while(it != lst.end()){
		a = *it;
		it++;
		if (it != lst.end())
			b = *it;
		else{
			b = 0;
			break;
		}
		it++;
		twins.push_back(std::make_pair(a,b));
	}

	std::list<int> maxtwins;
	for (std::list<std::pair<int, int> >::iterator twin = twins.begin(); \
	twin != twins.end(); twin++){
		maxtwins.push_back(std::max(twin->first, twin->second));
	}


	std::list<int> S = mergeList(maxtwins);

	/*std::cout << "-------------------" << std::endl;
	std::cout << "maxtwins :";
	for (std::list<int>::iterator itt = maxtwins.begin(); itt != maxtwins.end(); itt++) {
		std::cout << *itt << " ";
	}
	std::cout << std::endl;
	std::cout << "-------------------" << std::endl;
	std::cout << "S :";
	for (std::list<int>::iterator itt = S.begin(); itt != S.end(); itt++) {
		std::cout << *itt << " ";
	}
	std::cout << std::endl;*/


	for (std::list<std::pair<int, int> >::iterator it = twins.begin(); \
	it != twins.end(); ++it){
		int element;
		if (it->first < it->second)
			element = it->first;
		else
			element = it->second;
		std::list<int>::iterator position = std::upper_bound(S.begin(), S.end(), element);
		S.insert(position, element);
	}
	if (b == 0){
		std::list<int>::iterator position = std::upper_bound(S.begin(), S.end(), a);
		S.insert(position, a);
	}
	return S;
}

std::vector<int>	mergeVector(std::vector<int> & lst){
	if (lst.size() <= 1)
		return lst;

	int	a;
	int b;
	std::vector<std::pair<int, int> > twins;
	std::vector<int>::iterator it = lst.begin();
	while(it != lst.end()){
		a = *it;
		it++;
		if (it != lst.end())
			b = *it;
		else{
			b = 0;
			break;
		}
		it++;
		twins.push_back(std::make_pair(a,b));
	}

	std::vector<int> maxtwins;
	for (std::vector<std::pair<int, int> >::iterator twin = twins.begin(); \
	twin != twins.end(); twin++){
		maxtwins.push_back(std::max(twin->first, twin->second));
	}

	std::vector<int> S = mergeVector(maxtwins);

	/*std::cout << "-------------------" << std::endl;
	std::cout << "maxtwins :";
	for (std::vector<int>::iterator itt = maxtwins.begin(); itt != maxtwins.end(); itt++) {
		std::cout << *itt << " ";
	}
	std::cout << std::endl;
	std::cout << "-------------------" << std::endl;
	std::cout << "S :";
	for (std::vector<int>::iterator itt = S.begin(); itt != S.end(); itt++) {
		std::cout << *itt << " ";
	}
	std::cout << std::endl;*/


	for (std::vector<std::pair<int, int> >::iterator it = twins.begin(); \
	it != twins.end(); ++it){
		int element;
		if (it->first < it->second)
			element = it->first;
		else
			element = it->second;
		std::vector<int>::iterator position = std::upper_bound(S.begin(), S.end(), element);
		S.insert(position, element);
	}
	if (b == 0){
		std::vector<int>::iterator position = std::upper_bound(S.begin(), S.end(), a);
		S.insert(position, a);
	}
	return S;
}


