#include <iostream>
#include <queue>

int get_last_remaining_card(int n) {
    std::queue<int> cards;
	for (int i = 1; i <= n; i++)
	{
		cards.push(i);
	}
	std::cout << "Discarded cards: ";
    // When two cards remain, we pop both and put the last one back
	while (cards.size() >= 2) {
		std::cout << cards.front() << ", ";
		cards.pop();
		
		cards.push(cards.front());
		cards.pop();
	}
	std::cout << "\nRemaining card: " << cards.front() << '\n';
	return cards.front();
}

int main() {
	int n;
	std::cin >> n;
	while (n != 0) {
		get_last_remaining_card(n);
		std::cin >> n;
	}
    return 0;
}