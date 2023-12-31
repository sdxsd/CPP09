#include "PmergeMe.hpp"
#include <iostream>
#include <algorithm>

std::vector<int> insertionSort(const std::vector<int>& numList) {
	if (numList.size() <= 1)
		return (numList);
	std::vector<int> resultList = numList;
	for (unsigned long i = 0; i < resultList.size(); i++) {
		while ((i < resultList.size() - 1) && resultList[i] > resultList[i + 1]) {
			std::swap(resultList[i], resultList[i + 1]);
			i--;
		}
	}
	return (resultList);
}

std::vector<int> mergeSort(const std::vector<int>& numList) {
	if (numList.size() <= 1)
		return (numList);
	int					divide = numList.size() / 2;
	std::vector<int>	resultList;
	std::vector<int>	leftList = mergeSort(std::vector<int>(numList.begin(), numList.begin() + divide));
	std::vector<int>	rightList = mergeSort(std::vector<int>(numList.begin() + divide, numList.end()));

	for (unsigned long x = 0, y = 0; (x < leftList.size() || y < rightList.size());) {
		if (x != leftList.size() && (y == rightList.size() || leftList[x] < rightList[y]))
			resultList.push_back(leftList[x++]);
		else
			resultList.push_back(rightList[y++]);
	}
	return (resultList);
}
