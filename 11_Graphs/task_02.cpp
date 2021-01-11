#include <iostream>
#include <vector>
#include <string>

using namespace std;

template<typename T>
struct Node {

	T data;
	Node<T>* left;
	Node<T>* right;

	Node(T data) : data(data), left(nullptr), right(nullptr) {}
};

void getAllStrings(Node<char>* root, vector<string>& allStrings, string currStr = "") {

	if (root == nullptr)
		return;

	if (!root->left && !root->right) {
		allStrings.push_back(currStr + (root->data));
		return;
	}

	getAllStrings(root->left, allStrings, currStr + (root->data));
	getAllStrings(root->right, allStrings, currStr + (root->data));
}

bool existsPath(const string& curr, const vector<vector<char>>& g) {

	bool found = 0;

	for (int i = 0; i < curr.size() - 1; i++) {

		found = 0;
        int index = curr[i]-'a';

		for (int j = 0; j < g[index].size(); j++) {
			if (curr[i + 1] == g[index][j])
				found = true;
		}
		if (!found)
			return false;
	}

	return true;
}

void printPath(const string& word) {

	for (int i = 0; i < word.size(); i++) {
		
		cout << word[i];
		if (i != word.size() - 1)
			cout << "-";
		
	}
	cout << endl;
}

void samePath(Node<char>* t, vector<vector<char>> g) {

	vector<string> allStrings;
	getAllStrings(t, allStrings);
	string current;

	for (int i = 0; i < allStrings.size(); i++) {
		current = allStrings[i];

		if (existsPath(current, g)) {
			printPath(current);
			return;
		}
	}
		cout << "No path" << endl;
}

vector<vector<char>> createGraph(int vertices) {

    vector<vector<char>> g;
    g.resize(vertices);

    return g;
}

void addToGraph(vector<vector<char>>& graph, char from, char to) {
	graph[from - 'a'].push_back(to);
}

template <typename T>
void free(Node<T>* root) {

    if(root == nullptr)
        return;

    free(root->left);
    free(root->right);

    delete root;
}

int main()
{

 //Example 1:
    Node<char>* root = new Node<char>('a');
    root->left = new Node<char>('e');
	root->right = new Node<char>('f');
	root->left->left = new Node<char>('d');
	root->left->left->left = new Node<char>('b');
	root->left->right = new Node<char>('g');
	root->right->right = new Node<char>('c');
	root->right->right->left = new Node<char>('h');
	root->right->right->right = new Node<char>('p');

	vector<vector<char>> graph = createGraph(26);

	addToGraph(graph, 'a', 'd');
	addToGraph(graph, 'a', 'f');
	addToGraph(graph, 'd', 'e');
	addToGraph(graph, 'e', 'h');
	addToGraph(graph, 'g', 'e');
	addToGraph(graph, 'g', 'b');
	addToGraph(graph, 'b', 'h');
	addToGraph(graph, 'f', 'c');
	addToGraph(graph, 'f', 'h');
	addToGraph(graph, 'c', 'h');
    
    samePath(root, graph);

    free(root);

}
