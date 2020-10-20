// task_01_b.cpp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <vector>

void printSubset(const std::vector<int>& set, const std::vector<bool>& subset) {

	std::cout << '{';
	int size = subset.size();

	for (size_t i = 0; i < size; i++) {
		if (subset[i] == 1) {
			std::cout << ' ' << set[i] << ' ';
		}
	}

	std::cout << '}' << std::endl;
}

void getSubsetsRec(const std::vector<int> set, std::vector<bool> subset, int checkedNumbers = 0) {

	if (checkedNumbers == set.size()) {
		printSubset(set, subset);
		return;
	}

	//not including the current element in the subset
	subset.push_back(0);
	getSubsetsRec(set, subset, checkedNumbers + 1);

	//including the current element in the subset
	subset.pop_back();
	subset.push_back(1);
	getSubsetsRec(set, subset, checkedNumbers + 1);

}

//an additional function so that subset is not global
void wrapperGetSubsetsRec(const std::vector<int> set) {

	std::vector<bool> subset;
	//subset.resize(set.size());

	getSubsetsRec(set, subset);

}

int main()
{
	//Creating a set with the following elements : { 3, 6 , 35 , 4 }
	std::vector<int> set;
	set.push_back(3);
	set.push_back(6);
	set.push_back(35);
	set.push_back(4);

	wrapperGetSubsetsRec(set);

	return 0;
}

