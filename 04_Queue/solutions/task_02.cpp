#include <iostream>
#include <queue>
#include <stack>

// The same idea as merging two normal arrays
std::queue<int> merge_queue(std::queue<int> a, std::queue<int> b) {
	std::queue<int> merged;

    // We must have elements from both queues
	while (!a.empty() && !b.empty()) {
        // We push the smaller element and add it to the merged queue
		if (a.front() < b.front()) {
			merged.push(a.front());
			a.pop();
		}
		else {
			merged.push(b.front());
			b.pop();
		}
	}
	
    // We don't know which queue is empty
    // but it doesn't matter.
    // The remaining one is sorted, and all of its
    // elements are bigger than the biggest element in the merged queue
    // so we just append them to the end.
	while (!a.empty()) 
	{
		merged.push(a.front());
		a.pop();
	}
	while (!b.empty()) {
		merged.push(b.front());
		b.pop();
	}
	return merged;
}

int main() {
    std::queue<int> sorted_queue1;
    sorted_queue1.push(5);
    sorted_queue1.push(10);
    sorted_queue1.push(105);
    sorted_queue1.push(501);

    std::queue<int> sorted_queue2;
    sorted_queue2.push(-40);
    sorted_queue2.push(-5);
    sorted_queue2.push(11);
    sorted_queue2.push(105);
    sorted_queue2.push(5000);

    std::queue<int> reversed = merge_queue(sorted_queue1, sorted_queue2);
	while (!reversed.empty()) {
		std::cout << reversed.front() << ", ";
		reversed.pop();
	}
    return 0;
}