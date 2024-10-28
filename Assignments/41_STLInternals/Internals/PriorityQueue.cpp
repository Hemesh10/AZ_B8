#include <iostream>
#include <vector>
using namespace std;

template <typename T>
class MyPriorityQueue {
    vector<T> data;

    // Shift up the element at index i
    void shiftUp(size_t i) {
        while(i > 0) {
            size_t parentIndex = (i-1)/2;
            if(data[i] > data[parentIndex]) {
                swap(data[i], data[parentIndex]);
                i = parentIndex;
            } else break;
        }
    }

    // Shift down the element at index i
    void shiftDown(size_t i) {
        size_t n = data.size();
        while(2*i+1 < n) {
            size_t leftChild = 2*i+1;
            size_t rightChild = 2*i+2;
            size_t largest = i;
            if(leftChild < n && data[leftChild] > data[i]) largest = leftChild;
            if(rightChild < n && data[rightChild] > data[i]) largest = rightChild;
            if(largest != i) {
                swap(data[i], data[largest]);
                i = largest;
            } else break;
        }
    }

    public:
        // Constructor
        MyPriorityQueue() {}

        // Push an element into the priority queue
        void push(const T &value) {
            data.push_back(value);
            shiftUp(data.size() - 1);
        }

        // Pop the highest-priority element from the priority queue
        void pop() {
            if (empty()) {
                throw out_of_range("Priority queue is empty");
            }
            swap(data.front(), data.back());
            data.pop_back();
            shiftDown(0);
        }

        // Get the highest-priority element without removing it
        const T &top() const {
            if (empty()) {
                throw out_of_range("Priority queue is empty");
            }
            return data.front();
        }

        // Check if the priority queue is empty
        bool empty() const {
            return data.empty();
        }

        // Get the number of elements in the priority queue
        size_t size() const {
            return data.size();
        }
};
