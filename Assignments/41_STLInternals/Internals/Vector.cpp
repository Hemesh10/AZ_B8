#include <iostream>
using namespace std;

template <typename T>
class MyVector {
    T* data;
    size_t capacity;
    size_t size;

    void resize(size_t newCapacity) {
        T* newData = new T[newCapacity];
        for(size_t i=0;i<size;i++) {
            newData[i] = data[i];
        }
        delete[] data;
        data = newData;
        capacity = newCapacity;
    }

    public:
    // Constructor
    MyVector(size_t defaultCapacity = 4) : capacity(defaultCapacity), size(0) {
        data = new T[capacity];
    }

    // Destructor
    ~MyVector() {
        delete[] data;
    }

    // Copy Constructor
    MyVector(const MyVector<T>& other) : size(other.size), capacity(other.capacity) {
        data = new T[capacity];
        for(size_t i=0;i<size;i++) {
            data[i] = other.data[i];
        }
    }

    // Assignment operator (=)
    MyVector<T>& operator=(const MyVector<T>& other) {
        if(this != &other) {
            delete[] data;
            size = other.size;
            capacity = other.capacity;
            data = new T[capacity];
            for(size_t i=0;i<size;i++) {
                data[i] = other.data[i];
            }
        }
        return *this;
    }
    
    // Access the element at an index
    T& operator[](const size_t index) {
        if(index>=size) {
            throw(out_of_range("Index out of range"));
        }
        return data[index];
    }

    // Push an element to the end
    void push_back(const T& value) {
        if(size == capacity) {
            resize(capacity*2);
        }
        data[size++] = value;
    }

    // Remove the last element
    void pop_back() {
        if(size > 0) {
            --size;
        }
    }


    // Get size if the vector
    size_t get_size() const {
        return size;
    }

    // Get capacity of the vector
    size_t get_capacity() const {
        return capacity;
    }

    // Check whether vector is empty or not
    bool empty() {
        return size == 0;
    }

    void clear() {
        size = 0;
    }
};
