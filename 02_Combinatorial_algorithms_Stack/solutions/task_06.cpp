// *Maximum Element

#include <iostream>
#include <vector>
#include <stack>

const int QUERY_1 = 1;
const int QUERY_2 = 2;
const int QUERY_3 = 3;

//IDEA - keeping max elements in an additonal stack
//       (deleting the current max element from the stack means that we need to keep all of the previous)

int main() {

 
    int n;
    std::cin >> n;
    int query;
    int number;
    std::stack<int> numbers;
    std::stack<int> maxElements;

    for(size_t i = 0; i < n; i++) {

       std:: cin >> query;

        if(query == QUERY_1) {
            std::cin >> number;
            numbers.push(number);

            if(maxElements.empty() || maxElements.top() <= number)
                maxElements.push(number);
        }  
        else if(query == QUERY_2) {

            if(!numbers.empty() && !maxElements.empty() && numbers.top() == maxElements.top())
                maxElements.pop();

            numbers.pop();
        } else if(query == QUERY_3) {

            if(!maxElements.empty())
                std:: cout << maxElements.top() << std::endl;
        }
        
    }


    return 0;
}