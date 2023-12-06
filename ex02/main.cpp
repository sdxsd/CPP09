#include "PmergeMe.hpp"
#include <iostream>

int main(void) {
	std::vector<int> list = {12, 2, 53, 3, 98, 76, 200, 190};

	std::vector<int> sortedList = insertionSort(list);
	for (unsigned long i = 0; i < sortedList.size(); i++)
		std::cout << sortedList[i] << std::endl;
	std::cout << std::endl;
}
