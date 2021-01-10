#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

int dfs_recursive(vector<vector<int>> &graph, vector<bool> &visited, int start)
{
    visited[start] = true;
    int visitedCount = 1;
    vector<int>::iterator it = graph[start].begin();
    for (vector<int>::iterator i = it; i != graph[start].end(); ++i)
    {
        int neighbour = *i;
        if (!visited[neighbour])
        {
            visitedCount += dfs_recursive(graph, visited, neighbour);
        }
    }
    return visitedCount;
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

    int componentCount = 0;
    int visitedCount = 0;

    // Броене по време на DFS
    while (visitedCount < n)
    {
        visitedCount = 0;
        for (int i = 0; i < n; ++i)
        {
            if (!visited[i])
            {
                visitedCount += dfs_recursive(graph, visited, i);
                componentCount++;
            }
        }
    }
    cout << componentCount << '\n'; 
    visitedCount = 0;
    componentCount = 0;
    visited.assign(visited.size(), false);
    // Броене при итерация
    while (visitedCount < n)
    {
        visitedCount = 0;
        for (int i = 0; i < n; ++i)
        {
            if (!visited[i])
            {
                dfs_recursive(graph, visited, i);
                componentCount++;
            }
            else
            {
                visitedCount++;
            }
        }
    }
    cout << componentCount;
}