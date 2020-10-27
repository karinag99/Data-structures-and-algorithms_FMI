// *Permutation

#include <iostream>
#include <vector>

void print(const std::vector<int>& permSet) {

	std::cout << '{';

	int size = permSet.size();

	for (size_t i = 0; i < size; i++) {
		std::cout << ' ' << permSet[i] << ' ';
	}

	std::cout << '}' << std::endl;
}

void permute(const std::vector<int>& set, std::vector<int>& permSet, std::vector<bool>& used, int currentPosition = 0) {

	int size = set.size();

	if (currentPosition == size) {
		print(permSet);
		return;
	}

// iterating over the elemenets so that at the currentposition we can put each of the elements
	for (size_t i = 0; i < size; i++) {
		
		// checking if set[i] has not been used yet
		if (used[i] == 0) {
			permSet.push_back(set[i]);
			// adding set[i] in the permuted Set and set it as used
			used[i] = 1;
			// permuting the rest of the array
			permute(set, permSet, used, currentPosition + 1);
			// Returning to the previous state
			used[i] = 0;
			permSet.pop_back();
		}

	}

}

void wrapperPermute(const std::vector<int>& set) {

	std::vector<int> permSet;
	std::vector<bool> used;
	used.resize(set.size());

	permute(set, permSet, used);
}

int main() {
	std::vector<int> test;
	test.push_back(1);
	test.push_back(4);
	test.push_back(2);

	wrapperPermute(test);
	return 0;
}
