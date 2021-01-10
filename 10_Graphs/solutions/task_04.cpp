#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

void printPath(vector<int> &found_by, int node, int day)
{
    cout << "Delivered to house " << node << " at day " << day << '\n';
    cout << "Path: [";
    stack<int> path;
    while (node != found_by[node])
    {
        path.push(node);
        node = found_by[node];
    }
    while (!path.empty())
    {
        cout << path.top() << ' ';
        path.pop();
    }
    cout << "]\n";
}

void deliver(vector<vector<int>>& graph, vector<bool>& visited, int start, vector<bool>& delivered, int day, int k) {
	queue<int> to_explore;
	vector<int> found_by(graph.size());
	int deliveredCount = 0;
	to_explore.push(start);
	found_by[start] = start;
	
	while (!to_explore.empty()) {
		int current = to_explore.front();
		to_explore.pop();
		if (!delivered[current]) {
			printPath(found_by, current, day);
			delivered[current] = true;
			deliveredCount++;
			if (deliveredCount == k) {
				return;
			}
		}
		vector<int>::iterator it = graph[current].begin();
		for (vector<int>::iterator i = it; i != graph[current].end(); ++i) {
			int neighbour = *i;
			if (!visited[neighbour]) {
				visited[current] = true;
				found_by[neighbour] = current;
				to_explore.push(neighbour);
			}
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

    int k;
    cin >> k;

    // Няма смисъл да доставяме до собствената си къща
    delivered[startPosition] = true;

    for (int i = 0; i < n - 1; ++i)
    {
        deliver(graph, visited, startPosition, delivered, i + 1, k);
        visited.assign(graph.size(), false);
    }
}