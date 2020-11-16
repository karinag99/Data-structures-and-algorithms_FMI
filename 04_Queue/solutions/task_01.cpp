#include <iostream>
#include <queue>
#include <stack>


// We do not pass by reference, because that would destroy the original queue.
template <typename T>
std::queue<T> reverse_queue(std::queue<T> queue) {
	std::stack<T> temp_stack;
	while (!queue.empty()) {
		temp_stack.push(queue.front());
		queue.pop();
	}
	while (!temp_stack.empty()) {
		queue.push(temp_stack.top());
		temp_stack.pop();
	}
	return queue;
}

int main() {
    std::queue<int> int_queue;
    int_queue.push(1);
    int_queue.push(2);
    int_queue.push(3);

    std::queue<int> reversed_queue = reverse_queue(int_queue);
    while(!reversed_queue.empty()) {
        std::cout << reversed_queue.front() << ' ';
        reversed_queue.pop();
    }


    return 0;
}