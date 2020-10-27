// * Variation

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

void variation(const std::vector<int>& set, std::vector<int>& permSet, std::vector<bool>& used, int k, int currentPosition = 0) {

	int size = set.size();

	// Only difference between permutation and variation
	if (currentPosition == k) {
		print(permSet);
		return;
	}

	for (size_t i = 0; i < size; i++) {

		if (used[i] == 0) {
			used[i] = 1;
			permSet.push_back(set[i]);
			variation(set, permSet, used, k, currentPosition + 1);
			used[i] = 0;
			permSet.pop_back();
		}

	}

}

void wrapperVariation(const std::vector<int>& set, int k) {

	std::vector<int> permSet;
	std::vector<bool> used;
	used.resize(set.size());

	variation(set, permSet, used, k);
}

int main() {
	std::vector<int> test;
	test.push_back(1);
	test.push_back(4);
	test.push_back(2);

	wrapperVariation(test, 2);
	return 0;
}
