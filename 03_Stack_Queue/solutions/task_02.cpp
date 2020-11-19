#include <iostream>
#include <stack>
#include <string>


int extract_from_string(const std::string& str, int index) {
	int number = 0;
    int length = str.length();
	while (length > index && str.at(index) >= '0' && str.at(index) <= '9') {
		number *= 10;
		number += str.at(index) - '0';
		index++;
	}

	return number;
}

int calculate_expression(const std::string& expression) {
    int length = expression.length();

	std::stack<int> arguments;
	for (int i = length - 1; i >= 0; i--) {
		if (expression.at(i) == '*' || expression.at(i) == '/' || expression.at(i) == '+' || expression.at(i) == '-') {
			int leftArgument = arguments.top();
			arguments.pop();

			int rightArgument = arguments.top();
			arguments.pop();

			if (expression.at(i) == '*') {
				arguments.push(leftArgument * rightArgument);
			}
			if (expression.at(i) == '/') {
				arguments.push(leftArgument / rightArgument);
			}
			if (expression.at(i) == '+') {
				arguments.push(leftArgument + rightArgument);
			}
			if (expression.at(i) == '-') {
				arguments.push(leftArgument - rightArgument);
			}
		}
		if (expression.at(i) >= '0' && expression.at(i) <= '9') {
			while (expression.at(i) >= '0' && expression.at(i) <= '9') {
				i--;
			}
			i++;
			int number = extract_from_string(expression, i);
			arguments.push(number);
		}
	}
	return arguments.top();
}

int main() {
    std::string expression = "* + 5 - 15 93 + 4 84";

    std::cout  << calculate_expression(expression);

    return 0;
}