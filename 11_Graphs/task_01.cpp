#include <iostream>
#include <vector>

using namespace std;
//DFS
bool isCyclic(const vector<vector<int>>& g, vector<bool>& visited, vector<bool> currVisited, int currentNode) {

    if(currVisited[currentNode])
        return true;

    if(visited[currentNode])
        return false;

    visited[currentNode] = currVisited[currentNode] = true;

    for(int i = 0; i < g[currentNode].size(); i++) {

        if(isCyclic(g, visited, currVisited, g[currentNode][i]))
            return true;
    }

    return false;
}


bool isPossible(int numCourses, vector<vector<int>> prerequisites) {

    //create Graph

    vector<vector<int>> g;
    g.resize(numCourses);

    for(int i = 0; i < prerequisites.size(); i++) {
        g[prerequisites[i][0]].push_back(prerequisites[i][1]);
    }

    vector<bool> visited;
    vector<bool> currVisited;

    visited.assign(numCourses, 0);
    currVisited.assign(numCourses, 0);

    for(int i = 0; i < numCourses; i++) {
        
        if(isCyclic(g, visited, currVisited, i)) {
            return false;
        }   
    }

    return true;
}

int main() {

    //Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
    vector<vector<int>> pr;
    pr.resize(2);
    pr[0].push_back(1);
    pr[0].push_back(0);

    pr[1].push_back(0);
    pr[1].push_back(1);


    cout << isPossible(2, pr);

}