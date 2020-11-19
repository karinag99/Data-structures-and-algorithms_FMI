#include <iostream>

struct Node {
    int value;
    Node* next;

    Node(int value) {
        this->value;
        next = nullptr;
    }
};


int lenLList(Node* head) {

    int len = 0;

    while(head != nullptr) {
        len++;
        head = head->next;
    }
}

int getNthElement(Node* head, int n) {

    int len = lenLList(head);

    for(int i = 0; i < len - n; i++) {
        head = head->next;
    }

    return head->value;
}

int getNthElement_(Node* head, int n) {

    Node* iter;
    for(int i = 0; i < n - 1; i++) {
        iter = iter->next;
    }

    while(iter->next == nullptr) {
        iter = iter->next;
        head = head->next;
    }

    return head->value;
}


int main() {
    
    return 0;
}