// task_01.cpp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <vector>

void printSubset(int i, const std::vector<int>& set) {

	//creating a mask to iterate over the bits
	int mask = 1;
	//creating a variable to iterate over the set
	int pos = set.size() - 1;

	std::cout << "{";
	for (size_t j = 0; j < set.size(); j++) {

		//checking if the current bit is 1 or 0
		if (i & mask) {
			std::cout << ' ' << set[pos] << ' ';
		}

		mask <<= 1;
		pos--;
	}

	std::cout << "}" << std::endl;
}


void getSubsets(const std::vector<int>& set) {

	// calculating 2^(set.size())
	int countSubsets = 1 << set.size();

	//generating numbers between 0 and countSubsets -1
	//in binary system every number is representing a boolean sequence 
	// where 0 - the element of this position is not included in the subset
	// 1 - the element of this position is included in the subset
	for (size_t i = 0; i <= countSubsets - 1; i++) {

		printSubset(i, set);

	}

}


int main()
{
    //a set with the following elements : { 3, 6 , 35 , 4 }
	std::vector<int> set;
	set.push_back(3);
	set.push_back(6);
	set.push_back(35);
	set.push_back(4);

	getSubsets(set);

	return 0;
}
