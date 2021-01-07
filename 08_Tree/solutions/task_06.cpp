#include <iostream>
#include <forward_list>
#include <algorithm>

//task_06
struct Node {

  int data;
  std::forward_list<Node*> childs;

};

int extractRoot(const std::string t, int& leftStart) {

    int result = 0;
    int index = 1;

    while(t[index] >= '0' && t[index] <= '9') {
        result*= 10;
        result+= t[index] - '0';
        index++;
    }

    leftStart = index;
    return result;
}

std::string findChild(std::string t, int start, int& end) {

    end = start;
    if(t[end] >= '0' && t[end] <= '9') {
        end++;

        while(t[end] >= '0' && t[end] <= '9') {
            end++;
        }

        return t.substr(start, end - start);
        
    }else {
        end = start + 1;
        int brackets = 1;

        while(brackets != 0) {

            if(t[end] == '{')
                brackets++;
                
            else if (t[end] == '}')
                brackets--;

            end++;
        }

        return t.substr(start, end - start);
    }

}

int extractNum(std::string t){

    int result = 0;
    int index = 0;

    while(t[index] >= '0' && t[index] <= '9') {
        result*= 10;
        result+= t[index] - '0';
        index++;
    }

    return result;
}

Node* generateTree(std::string t) {

    //влизаме в дървото - взимаме корен, ляв и десен
    if(t[0] == '{'){
        int index = 0;
        int start;
        int end;
        int rightEnd;
        Node* root = new Node();
        root->data = extractRoot(t, start);

        while(t[index] != '}') {
        root->childs.push_front(generateTree (findChild (t, ++start, end)));
        index = end;
        start = end;
        }

        return root;

    }else {
        Node* root = new Node();
        root->data = extractNum(t);
        return root;
    }

}

int getLen(std::forward_list<Node*> lst) {

    int len = 0;
    std::forward_list<Node*>::iterator it;

    for(it = lst.begin(); it != lst.end(); ++it) {
        len++;
    }

    return len;
}

int max_branching(Node* root) {

    int rootChildren = getLen(root->childs);
    int result = rootChildren;
    std::forward_list<Node*> :: iterator it;

    for(it = root->childs.begin(); it != root->childs.end(); it++) {
        result = std::max(result, max_branching(*it));
    }

    return result;
}

int main() {

    std::cout << max_branching( generateTree("{1 {1 2 3 4 {2 3 4 5 6 5}} {17 15 20 3 0} 4}"));

    return 0;
}