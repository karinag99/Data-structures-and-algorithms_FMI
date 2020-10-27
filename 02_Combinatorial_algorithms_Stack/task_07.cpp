// *Christmas presents

#include <iostream>
#include <vector>
#include <stack>

void getInitialOrder(std::stack<int>& gutter1, int N) {

    for(size_t i = 1; i <= N; i++) {
        gutter1.push(i);
    }
}

//IDEA - moving the elements from gutter1 to gutter2 and vice versa
//       until the current element of the final order is the top elements of glutter2
void getCommands(const std::vector<int>& finalOrder) {
    
    std::stack<int> gutter1;
    std::stack<int> gutter2;

    //an additional variables - to track if the next element is in gutter1 or gutter2 
    bool currentElemIsInGutter2 = false;
    bool nextElemIsInGutter2 = false;
    getInitialOrder(gutter1, finalOrder.size());

    for(size_t i = 0; i < finalOrder.size() - 1; i++) {

        if(currentElemIsInGutter2) {
            int num = gutter2.top();

            //Tracking the next element
            if(num == finalOrder[i+1])
                nextElemIsInGutter2 = false;

            while(num != finalOrder[i]) {
                gutter1.push(num);
                gutter2.pop();
                std::cout << '3' << ' ';

                num = gutter2.top();

                //Tracking the next element
                if(num == finalOrder[i+1])
                nextElemIsInGutter2 = false;
            }

            gutter2.pop();
            std::cout << '2' << ' ';
            
        }else {
             int num = gutter1.top();

            if(num == finalOrder[i+1])
               nextElemIsInGutter2 = true;

            while(num != finalOrder[i]) {
                gutter2.push(num);
                gutter1.pop();
                std::cout << '1' << ' ';

                num = gutter1.top();

                if(num == finalOrder[i+1])
                    nextElemIsInGutter2 = true;
            }

            gutter2.push(num);
            gutter1.pop();
            std::cout << '1' << ' ';

            gutter2.pop();
            std::cout << '2' << ' ';
        }

        currentElemIsInGutter2 = nextElemIsInGutter2;

    }

    // Taking care of the last element
    if(currentElemIsInGutter2) {
        gutter2.pop();
        std::cout << '2' << ' ';
    }else {
        gutter2.push(gutter1.top());
        gutter1.pop();
        std::cout << '1' << ' ';

        gutter2.pop();
        std::cout << '2' << ' ';
    }
}

int main() {

    int n;
    int present;
    std::cin >> n;

    std::vector<int> finalOrder;

    for(size_t i = 0; i < n; i++) {
        std::cin >> present;
        finalOrder.push_back(present);
    }

    getCommands(finalOrder);
    
    return 0;
}