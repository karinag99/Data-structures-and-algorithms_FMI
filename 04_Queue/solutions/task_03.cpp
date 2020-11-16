#include <iostream>
#include <queue>

int josephus_safe_position(int n, int k) {
	std::queue<int> people;
	for (int i = 1; i <= n; i++)
	{
		people.push(i);
	}
	int current_person = 1;
	while (people.size() > 1) 
	{
		if (current_person == k) {
			std::cout << "Person " << people.front() << " is removed from the circle.\n";
			people.pop();
			current_person = 1;
		}
		else {
			int p = people.front();
			people.pop();
			people.push(p);
			std::cout << "Person " << p << " is safe.\n";
			current_person++;
		}
	}
	return people.front();
}

int main() {
	int n;
	int k;
	std::cin >> n;
	std::cin >> k;

	int safe_position = josephus_safe_position(n, k);
	std::cout << "The safe position is " << safe_position << '\n';

	return 0;
}