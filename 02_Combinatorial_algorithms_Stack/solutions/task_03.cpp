// *Combination

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

void combination(const std::vector<int>& set, std::vector<int>& permSet, std::vector<bool>& used, int k, int currentPosition = 0) {

	int size = set.size();

	if (currentPosition == k) {
		print(permSet);
		return;
	}

	for (size_t i = 0; i < size; i++) {

		if (used[i] == 0) {
			used[i] = 1;
			permSet.push_back(set[i]);
			combination(set, permSet, used, k, currentPosition + 1);
			// only difference between combination and variation - set[i] remains used
			permSet.pop_back();
		}

	}

}

void wrapperCombination(const std::vector<int>& set, int k) {

	std::vector<int> permSet;
	std::vector<bool> used;
	used.resize(set.size());

	combination(set, permSet, used, k);
}

int main() {
	std::vector<int> test;
	test.push_back(1);
	test.push_back(4);
	test.push_back(2);

	wrapperCombination(test, 2);
	return 0;
}
