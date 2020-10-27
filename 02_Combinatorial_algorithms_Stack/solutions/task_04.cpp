// *Reverse stack

#include <iostream>
#include <stack>

void reverseStack(std::stack<int>& s) {
   
    // using an additional array to reverse the order of the elements
    std::stack<int> helper;

    while(!s.empty()) {
        helper.push(s.top());
        s.pop();
    }
    
    while(!helper.empty()) {
        s.push(helper.top());
        helper.pop();
    }
}

void printStack(std::stack<int> copy) {
    while(!copy.empty()) {
        std::cout << copy.top() <<' ';
        copy.pop();
    }
}

int main() {

    std::stack<int> s;
    s.push(1);
    s.push(5);
    s.push(7);
    s.push(4);

    reverseStack(s);
    printStack(s);

   return 0;
}