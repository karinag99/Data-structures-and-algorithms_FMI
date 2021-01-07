#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

template <typename T>
struct Node {

    T data;
    Node *left, *right;

    Node(T data) : data(data), left(nullptr), right(nullptr) {}

    Node() : left(nullptr), right(nullptr) {}
};

//task_01
int countInInterval(Node<int>* root, int start, int end) {

    if(root == nullptr) 
        return 0;

    if(root->data >= start && root->data <= end)
        return 1 + countInInterval(root->left, start, end) +
                   countInInterval(root->right, start, end);

    if(root->data > end) 
        return countInInterval(root->left, start, end);

    if(root->data < start)
        return countInInterval(root->right, start, end);

    return countInInterval(root->left, start, end) + 
           countInInterval(root->right, start, end);
}


int sum(Node<int>* root, int start, int end) {

    if(root == nullptr)
        return 0;

    int countChildren = countInInterval(root->left, start, end) +
                        countInInterval(root->right, start, end);

    if(countChildren % 2 == 1)
        return root->data + sum(root->left, start, end) +
                            sum(root->right, start, end);

    return sum(root->left, start, end) + 
           sum(root->right, start, end);
}


//task_02
void findLevel(Node<int>* root, int level, vector<int>& elems) {

    if(root == nullptr)
        return;

    if(level == 0){
        elems.push_back(root->data);
        return;
    }

    findLevel(root->left, level - 1, elems);
    findLevel(root->right, level - 1, elems);
}

int getMaxLevel(Node<int>* root) {

    if(root == nullptr)
        return 0;

    return 1 + max(getMaxLevel (root->left), getMaxLevel(root->right));
}

bool checkTrees(Node<int>* root1, Node<int>* root2) {

    vector<int> elemsByLevel1;
    vector<int> elemsByLevel2;

    int maxLevel1 = getMaxLevel(root1);
    int maxLevel2 = getMaxLevel(root2);

    if(maxLevel1 != maxLevel2)
        return false;

    for(int i = 0; i <= maxLevel1; i++) {

        findLevel(root1, i, elemsByLevel1);
        findLevel(root2, i, elemsByLevel2);

        sort(elemsByLevel1.begin(), elemsByLevel1.end());
        sort(elemsByLevel2.begin(), elemsByLevel2.end());

        if(elemsByLevel1 != elemsByLevel2)
            return false;
    }
    return true;
}

//task_03
int getSum(Node<int>* root, int level = 0) {

    if(root == nullptr)
        return 0;

    if(level % 2 == 1 && root->right != nullptr && root->left == nullptr)
        return root->data + getSum(root->right, level + 1);

    return getSum(root->left, level + 1) + getSum(root->right, level + 1);
}

//task_04
struct Interval{

    int start;
    int end;

    Interval(int start, int end) : start(start), end(end) {}

    int getAver() {return (start + end) / 2;}
};

struct NodeInt {

    Interval inter;
    NodeInt* left, *right;

    NodeInt(Interval it) :inter(inter), left(nullptr), right(nullptr) {}

};

bool intersection(Interval it1, Interval it2) {

    return !(it1.end < it2.start || it1.start > it2.end);
}

bool noEmptyIntersection(NodeInt* root, Interval it1) {

    if(root == nullptr)
        return true;

    return  intersection(root->inter, it1) && 
            noEmptyIntersection(root->left, it1) &&
            noEmptyIntersection(root->right, it1);
}

void getMaxHelper(NodeInt* currRoot, NodeInt*& currMax, NodeInt* root) {

    if(root == nullptr)
        return;

    if(currMax != nullptr)
        return;

    getMaxHelper(root->right, currMax, root);

    if(currMax == nullptr && noEmptyIntersection(root, currRoot->inter)){
        currMax = currRoot;
        return;
    }

    getMaxHelper(currRoot->left, currMax, root);
}

Interval getMax(NodeInt* root) {

   NodeInt* currMax = nullptr;
   getMaxHelper(root, currMax, root);

   if(currMax == nullptr)
        return Interval(0, 0);

    return currMax->inter; 
}


int main () {

    return 0;
}