#include <iostream>
#include <vector>
#include <queue>

struct Node {
	int x;
	int y;
	int depth;
};

bool is_in_array_bounds(int n, int m, int x, int y) {
	return x >= 0 && y >= 0 && x < n && y < m;
}


int explore_maze(int maze[][11], int n, int m, int start_x, int start_y, int destination_x, int destination_y, std::vector<std::pair<int, int>>& path) {

	std::queue<Node> to_be_explored_queue;

	Node start;
	start.x = start_x;
	start.y = start_y;
	start.depth = 0;
	to_be_explored_queue.push(start);

	bool** used = new bool* [n];
	std::pair<int, int>** discovered_from = new std::pair<int, int> * [n];
	for (int i = 0; i < n; i++)
	{
		used[i] = new bool[m];
		discovered_from[i] = new std::pair<int, int>[m];
		for (int j = 0; j < m; j++)
		{
			used[i][j] = false;
			discovered_from[i][j] = std::make_pair(-1, -1);
		}
	}

	used[start.x][start.y] = true;

	while (!to_be_explored_queue.empty()) {
		Node current = to_be_explored_queue.front();
		to_be_explored_queue.pop();

		// We have reached the destination cell, therefore we get the path and depth
		if (current.x == destination_x && current.y == destination_y) {
			std::pair<int, int> temp = std::make_pair(destination_x, destination_y);
			while (temp.first != start.x || temp.second != start.y) {
				path.push_back(temp);
				temp = discovered_from[temp.first][temp.second];
			}

			for (int i = 0; i < n; ++i) {
				delete[] discovered_from[i];
				delete[] used[i];
			}
			delete[] used;
			delete[] discovered_from;
			
			// The depth is just the count of steps we took 
			// to get to the current point which we know is the destination
			return current.depth;
		}

		// In order to "move" to a cell, it need to be
		// 1. In the bounds of the matrix
		// 2. If we have been to a cell before, we have discovered everything there is to discover.
		// 3. The cell must be a walkable path. (a 1 value in our case)
		if (is_in_array_bounds(n, m, current.x - 1, current.y) && !used[current.x - 1][current.y] && maze[current.x - 1][current.y] == 1) {
			// This is the first time we discovered this node, and the shortest path is the shortest path to the node we found it from, plus 1
			Node top;
			top.x = current.x - 1;
			top.y = current.y;
			top.depth = current.depth + 1;
			to_be_explored_queue.push(top);
			// We remember where we discovered it from, in order to recreate the path
			// we took to reach the destination cell.
			discovered_from[current.x - 1][current.y] = std::make_pair(current.x, current.y);
			// We mark it as used so we don't go back to this path and cause an infinite cycle.
			used[current.x - 1][current.y] = true;
		}
		if (is_in_array_bounds(n, m, current.x + 1, current.y) && !used[current.x + 1][current.y] && maze[current.x + 1][current.y] == 1) {
			Node bottom;
			bottom.x = current.x + 1;
			bottom.y = current.y;
			bottom.depth = current.depth + 1;
			to_be_explored_queue.push(bottom);
			discovered_from[bottom.x][bottom.y] = std::make_pair(current.x, current.y);
			used[current.x + 1][current.y] = true;
		}
		if (is_in_array_bounds(n, m, current.x, current.y - 1) && !used[current.x][current.y - 1] && maze[current.x][current.y - 1] == 1) {
			Node left;
			left.x = current.x;
			left.y = current.y - 1;
			left.depth = current.depth + 1;
			to_be_explored_queue.push(left);

			discovered_from[left.x][left.y] = std::make_pair(current.x, current.y);
			used[current.x][current.y - 1] = true;
		}
		if (is_in_array_bounds(n, m, current.x, current.y + 1) && !used[current.x][current.y + 1] && maze[current.x][current.y + 1] == 1) {
			Node right;
			right.x = current.x;
			right.y = current.y + 1;
			right.depth = current.depth + 1;
			to_be_explored_queue.push(right);
			used[current.x][current.y + 1] = true;
			discovered_from[right.x][right.y] = std::make_pair(current.x, current.y);
		}
	}
	
	for (int i = 0; i < n; ++i) {
		delete[] discovered_from[i];
		delete[] used[i];
	}
	delete[] used;
	delete[] discovered_from;
	
	return -1;
}

int main() {
	//int maze[][5] = {
	//		 {1, 1, 0, 1, 1},
	//		 {0, 1, 1, 1, 0},
	//		 {0, 1, 0, 1, 1}
	//};

	int maze[][11] = {
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1},
		{1, 0, 1, 0, 1, 0, 1, 0 ,1, 0, 1},
		{1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
	};
	std::vector<std::pair<int, int>> path;
	std::cout << "Shortest path length: " << explore_maze(maze, 7, 11, 3, 0, 3, 10, path) << '\n';
	int length = path.size();

	for (int i = length - 1; i >= 0; --i) {
		std::cout << '(' << path[i].first << ',' << path[i].second << ')' << ' ';
	}
}