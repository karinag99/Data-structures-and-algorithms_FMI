#include <iostream>

struct Node {
    int value;
    Node* next;

    Node(int value) {
        this->value;
        next = nullptr;
    }
};

Node* merge(Node*& headA, Node*& headB) {

    Node* mergedHead;
    Node* iter;

    if(headA->value < headB->value) {
        mergedHead = headA;
        headA = headA->next;
    }else {
        mergedHead = headB;
        headB = headB->next;
    }

    iter = mergedHead;

    while(headA != nullptr && headB != nullptr) {

        if(headA->value < headB->value) {
            iter->next = headA;
            iter = iter->next;
        } else {
            iter->next = headB;
            iter = iter->next;
        }
    }

    if(headA == nullptr && headB != nullptr) {
        iter->next = headB;
        headB = nullptr;
    }else if (headA != nullptr && headB == nullptr) {
        iter->next = headA;
        headA = nullptr;
    }

    return mergedHead;
}


int main() {
    
    return 0;
}