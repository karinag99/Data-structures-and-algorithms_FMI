#include <iostream>

struct Node {
    int value;
    Node* next;

    Node(int value) {
        this->value;
        next = nullptr;
    }
};

bool detectCycle(Node* head) {

    if(head == nullptr) 
    return false;

    Node* slow = head;
    Node* fast = head->next;

    if(fast == nullptr) 
        return false;
    else if(fast == slow) 
        return true;

    while(true) {
        
        fast = fast->next;

        if(fast == nullptr)
            return false;
        else if(fast == slow)
            return true;

        fast = fast->next;

        if(fast == nullptr)
            return false;
        else if(fast == slow)
            return true;

        slow = slow->next;

        if(slow == fast)
            return true; 
    }

}


int main() {
    
    return 0;
}