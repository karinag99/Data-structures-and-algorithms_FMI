#include <iostream>
#include <string>

template <typename T>
struct Node {

    T data;
    Node *left, *right;

    Node(T data) {
        this->data = data;
        left = right = nullptr;
    }

    Node() {
        left = right = nullptr;
    }
};


//taks_01
template <typename T>
void inOrder(Node<T>* root) {

    if  (root == nullptr)
           return;

    inOrder(root->left);
    std::cout << root->data << " ";
    inOrder(root->right);
}

//task_02
template <typename T>
void printLevel(Node<T>* root, int level ) {

    if(root == nullptr) 
        return;

    if(level == 0) {
        std::cout << root->data << " ";
        return; 
    }

    printLevel(root->left, level - 1);
    printLevel(root->right, level - 1);
}

//task_03
int getSumLevels(Node<int>* root, int level) {

    if(root == nullptr) 
        return 0;

    if(level == 0) 
        return root->data;

   return getSumLevels(root->left, level - 1) + getSumLevels(root->right, level - 1);
}

//task_03 - with additional variable

void getSumLevelsHelper(Node<int>* root, int level, int& sum) {

    if(root == nullptr) 
        return;

    if(level == 0) {
        sum+= root->data;
        return;
    }

    getSumLevelsHelper(root->left, level - 1, sum);
    getSumLevelsHelper(root->right, level - 1, sum);
}

int getSumByLevels_(Node<int>* root, int level) {

    int result = 0;
    getSumLevelsHelper(root, level, result);

    return result;
}

//task_04
template <typename T>
T findElementByClue(const std::string& clue, Node<T>* root, int pos = 0) {

    if(root == nullptr) 
        return T();

    if(pos == clue.size()) 
        return root->data;

   return (clue[pos] == 'l') ? findElementByClue(clue, root->left, pos + 1) :
                         findElementByClue(clue, root->left, pos + 1);
}

//task_05
template <typename T>
void createClueHelper(Node<T>* root, T elem, std::string clue, std::string curr = "") {

    if(root == nullptr) 
        return;

    if(root->data == elem) {
        clue = curr;
        return;
    }

    createClueHelper(root->left, elem, clue, curr + 'l');
    createClueHelper(root->right, elem, clue, curr + 'r');
}

template <typename T>
std::string createClue(Node<T>* root, T elem) {

    std::string clue;
    creteClueHelper(root, elem, clue);
    return clue;
}

//task_06
template <typename T>
void getMirrorVersion(Node<T>* root) {

    if(root == nullptr) 
        return;

    swap(root->left, root->right);
    getMirrorVersion(root->left);
    getMirrorVersion(root->right);
}

//task_07
bool areNodesBiggerThenVal(Node<int>* root, int val) {

    if(root == nullptr) 
        return true;

    return val >= root->data && 
           areNodesBiggerThenVal (root->left, val) &&
           areNodesBiggerThenVal(root->right, val);

}

bool areNodesSmallerThenVal(Node<int>* root, int val) {

    if(root == nullptr) 
        return true;

    return val <= root->data && 
           areNodesSmallerThenVal (root->left, val) &&
           areNodesSmallerThenVal(root->right, val);

}

bool isBST(Node<int>* root) {

    if(root == nullptr)
        return true;

    return areNodesBiggerThenVal(root->right, root->data) &&
           areNodesSmallerThenVal(root->left, root->data) &&
           isBST(root->left) && isBST(root->right);
}


int main() {

    return 0;
}