#include <iostream>
#include <stack>


void text() {
	std::stack<std::string> redactor;

	redactor.push("");

	int Q;
	std::cin >> Q;
	for (int i = 0; i < Q; i++)
	{
		int command;
		std::cin >> command;

		std::string& currentState = redactor.top();

		if (command == 1) {
			std::cin.ignore();
			std::string appended;

			std::getline(std::cin, appended);

			redactor.push(currentState + appended);
		}
		if (command == 2) {
			int k;
			std::cin >> k;

			redactor.push(currentState.substr(0, currentState.length() - k));
		}
		if (command == 4) {
			redactor.pop();
		}
		if (command == 3) {
			int k;
			std::cin >> k;
			std::cout << currentState.at(k - 1) << std::endl;
		}
	}
}


int main() {
	text();
    return 0;
}

