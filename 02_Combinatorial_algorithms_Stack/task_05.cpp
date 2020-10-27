// *Balanced Brackets

#include <iostream>
#include <string>
#include <stack>


// IDEA - opening bracket - push it in the stack
//        closing bracket corresponding to the top of the stack - pop it from the stack
//        valid expressiion = empty stack

const std::string isBalanced(const std::string& s) {

    std::stack<char> brackets;
    int size = s.size();

    for(size_t i = 0; i < size; i++) {

        if (s[i] == '{' || s[i] == '[' || s [i] == '(') {
           brackets.push(s[i]);
           continue;
        }
        //checking of the stack is empty before using the top() funtion
        else if (brackets.empty()) 
            return "NO";
        else if (s[i] == '}' && brackets.top() != '{')
               return "NO";
        else if (s[i] == ']' && brackets.top() != '[') 
               return "NO";
        else if (s[i] == ')' && brackets.top() != '(')
               return "NO";
        brackets.pop();
    }

    if(brackets.empty())
        return "YES";
    return "NO";
}

int main() {

    return 0;
}