#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

void bfs(vector<vector<int>> &graph, vector<bool> &visited, int start)
{
	queue<int> to_visit;

	to_visit.push(start);
	visited[start] = true;

	while (!to_visit.empty())
	{
		int currentNode = to_visit.front();
		to_visit.pop();
		cout << "Visited " << currentNode << '\n';
		vector<int>::iterator it = graph[currentNode].begin();
		for (vector<int>::iterator i = it; i != graph[currentNode].end(); ++i)
		{
			int neighbour = *i;
			if (!visited[neighbour])
			{		
				visited[currentNode] = true;
				to_visit.push(neighbour);
			}
		}
	}
}


void dfs(vector<vector<int>> &graph, vector<bool> &visited, int start)
{
	stack<int> to_visit;

	to_visit.push(start);

	while (!to_visit.empty())
	{
		int currentNode = to_visit.top();
		to_visit.pop();

		if (visited[currentNode]) {
			continue;			
		}
		visited[currentNode] = true;
		
		cout << "Visited " << currentNode << '\n';
		// reverse_iterator - итератор итериращ в обратен ред (да е точно в същият ред като рекурсивния)
		// като минаваме в обратен ред, на върха на стека остава най-левият съсед. 
		// Така извикването ще е с най-левият както е в рекурсивната версия
		vector<int>::reverse_iterator it = graph[currentNode].rbegin();
		for (vector<int>::reverse_iterator i = it; i != graph[currentNode].rend(); ++i)
		{
			int neighbour = *i;
			if (!visited[neighbour])
			{		
				to_visit.push(neighbour);
			}
		}
	}
}

void dfs_recursive(vector<vector<int>> &graph, vector<bool> &visited, int start)
{
	visited[start] = true;
	cout << "Visited " << start << '\n';
	vector<int>::iterator it = graph[start].begin();
	for (vector<int>::iterator i = it; i != graph[start].end(); ++i)
	{
		int neighbour = *i;
		if (!visited[neighbour])
		{
			dfs_recursive(graph, visited, neighbour);
		}
	}
}

int main()
{
	int n;
	cin >> n;
	vector<vector<int>> graph(n);
	vector<bool> visited(n);
	vector<bool> delivered(n);
	int m;
	cin >> m;

	for (int i = 0; i < m; ++i)
	{
		int from;
		int to;
		cin >> from >> to;

		graph[from].push_back(to);
		graph[to].push_back(from);
	}
	int startPosition;
	cin >> startPosition;
	cout << "BFS:\n";
	bfs(graph, visited, startPosition);
	cout << "DFS Recursive:\n";
	visited.assign(visited.size(), 0);

	dfs_recursive(graph, visited, startPosition);
	cout << "DFS Stack:\n";
	visited.assign(visited.size(), 0);

	dfs(graph, visited, startPosition);
}