#include <iostream>
using namespace std;

template <typename T1, typename T2>
class Pair {
    public:
        T1 first;
        T2 second;

        // Pair() {
        //     first = T1();
        //     second = T2();
        // }
        Pair() : first(T1()), second(T2()) {}

        // Parameterized Constructor
        // Pair(const T1& t1, const T2& t2) {
        //     first = t1;
        //     second = t2;
        // }
        Pair(const T1& f, const T2& s) : first(f), second(s) {}

        // Copy constructor
        // Pair(const Pair& other) {
        //     first = other.first;
        //     second = other.second;
        // }
        Pair(const Pair& other) : first(other.first), second(other.second) {}

        // Assignment operator
        Pair& operator=(const Pair& other) {
            if(this != &other) {
                first = other.first;
                second = other.second;
            }
            return *this;
        }

        // Equality operator
        bool operator==(const Pair& other) const {
            return ((first == other.first) && (second == other.second));
        }

        // Not equal operator
        bool operator!=(const Pair& other) const {
            return !(*this == other);
        }

        // Greater than (>) operator
        bool operator>(const Pair& other) const {
            if(first > other.first) return true;
            if(first == other.first && second > other.second) return true;
            return false;
        }

        // Less than (<) operator
        bool operator<(const Pair& other) const {
            if(first < other.first) return true;
            if(first == other.first && second < other.second) return true;
            return false;
        }
};
