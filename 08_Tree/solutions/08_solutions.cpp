#include <iostream>
#include <string>
#include <algorithm>

template <typename T>
struct Node {

    T data;
    Node<T>* right, *left;

    Node() : right(nullptr), left(nullptr){}

    Node(T data) : data(data), right(nullptr), left(nullptr) {}
};

//task_01 - with additional variable
void maxLeaf(Node<int>* root, int& result){

    if(root == nullptr) {
        return;
    }

    if(root->left == nullptr && root->right == nullptr){
        if(root->data > result) {
            result = root->data;
        }
        return;
    }

    maxLeaf(root->left, result);
    maxLeaf(root->right, result);
}

int maxLeafWrapper(Node<int>* root) {

    int result = INT_MIN;
    maxLeaf(root, result);

    return result;
}

//task_01
int maxLeaf_(Node<int>* root) {

    if(root == nullptr) {
        return INT_MIN;
    }

    if(root->left == nullptr && root->right == nullptr) {
        return root->data;
    }

    return std::max(maxLeaf_(root->left), maxLeaf_(root->right));
}

//task_02
void insertNode(Node<int>* root, int x) {

    if(x <= root->data && root->left == nullptr) {
        root->left = new Node<int>(x);
        return;
    } else if(x > root->data && root->right == nullptr) {
        root->right = new Node<int>(x);
        return;
    }

     (x > root->data) ? insertNode(root->right, x) : insertNode(root->left, x);
}

//task_03
int findLcaBST(Node<int>* root, int x, int y) {

    if(root->data >= std::min(x, y) && root->data <= std::max(x, y)) {
        return root->data;
    }

    return (root->data >= x && root->data >= y) ? findLcaBST(root->left, x, y) :
                                                  findLcaBST(root->right, x, y);
}

//task_03
bool path(Node<int>* root, int x) {

    if(root == nullptr) 
        return false;

    if(root->data == x)
        return true;

    return (path(root->left, x) || path(root->right, x));
}

void findLCAHelper(Node<int>* root, int x, int y, Node<int>*& result) {

    if(root == nullptr) 
        return;

    if(path(root, x) && path(root, y)) {
        result = root;
        return;
    }

    findLCAHelper(root->left, x, y, result);
    findLCAHelper(root->right, x, y, result);
}

int findLCA(Node<int>* root, int x, int y) {
    Node<int>* result;
    findLCAHelper(root, x, y, result);
    return result->data;
}

//task_04
char findNode(Node<char>* root, std::string& s, int& index) {

    if(root->left == nullptr && root->right == nullptr) {
        return root->data;
    }

   return (s[index] == '0') ? findNode(root->left, s, ++index) :
                              findNode(root->right, s, ++index);
}

std::string decode (Node<char>* root, std::string s) {

    std::string result = "";
    int index = 0;

    while(index < s.size()) {
        result.push_back(findNode(root, s, index));
    }

    return result;
}

//task_05
template <typename T>
int getHeight(Node<T>* root) {

    if (root == nullptr) 
        return -1;

    return 1 + max(getHeight(root->left), getHeight(root->right));

}

template <typename T>
bool isBalanced(Node<T>* root) {

    if(root == nullptr) 
        return true;

    return (abs(getHeight(root->left) - getHeight(root->right)) <= 1) &&
            isBalanced(root->left) &&
            isBalanced(root->right);
}

int main() {

    return 0;
}