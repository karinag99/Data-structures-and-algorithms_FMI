#include <iostream>
#include <string>
#include <stack>

bool isOperation(char c) {
return (c == '+' || c == '-' || c == '*');
}

bool isValid(const std::string& expr) {

    int len = expr.length();
    int operations = 0, brackets = 0;

    for(int i = 0; i < len; i++) {

        if(expr[i] == '(' || expr[i] == ')') 
            brackets++;

        else if(isOperation(expr[i]))
            operations++; 
    }

    return (operations == brackets / 2);
}

void getBrackets(const std::string& expr) {

    if(isValid(expr))
        return;

    int len = expr.length();

    std::stack<char> brackets;
    std::stack<int> brackets_positions;

    for(int i = 0; i < len; i++) {

        if(expr[i] == '(') {
            brackets.push('(');
            brackets_positions.push(i);

        }else if(isOperation(expr[i])) {
            brackets.push(expr[i]);

        }else if(expr[i] == ')') {
            int top = brackets.top();

            if(isOperation(top)) {
                brackets.pop();
                brackets.pop();
                brackets_positions.pop();

            }else {
                std::cout << brackets_positions.top() << " "
                          << i << std::endl;
                brackets.pop();
                brackets_positions.pop();
            }
        }
    }
}

int main() {
    
    return 0;
}