#include "PmergeMe.hpp"
#include <iostream>

int main(void) {
	std::vector<int> list = {12, 2, 23, 89, 11, 14};

	std::vector<int> sortedList = mergeSort(list);
	for (unsigned long i = 0; i < sortedList.size(); i++)
		std::cout << sortedList[i] << std::endl;
}
