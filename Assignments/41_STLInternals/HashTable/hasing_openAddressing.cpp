#include <iostream>
#include <list>
using namespace std;

template <typename K, typename V>
class UnorderedMapLinearProbing {
    private:
        static const int defaultCapacity = 10;
        pair<K, V>* table;
        bool* occupied;
        int capacity;
        int count;

        int hash(const K& key) const {
            return key % capacity;
        }

    public:
        UnorderedMapLinearProbing(int cap = defaultCapacity) : capacity(cap), count(0) {
            table = new pair<K, V>[capacity];
            occupied = new bool[capacity]();
        }

        ~UnorderedMapLinearProbing() {
            delete[] table;
            delete[] occupied;
        }
        
        void insert(const K& key, const V& value) {
            int hashedKey = hash(key);
            while(occupied[hashedKey] && table[hashedKey].first != key) {
                hashedKey = (hashedKey + 1) % capacity;
            }
            if(!occupied[hashedKey]) ++count;
            table[hashedKey] = {key, value};
            occupied[hashedKey] = true;
        }

        bool erase(const K& key) {
            int hashedKey = hash(key);
            int startHash = hashedKey;
            while(occupied[hashedKey] && table[hashedKey].first != key) {
                hashedKey = (hashedKey + 1) % capacity;
                if(startHash == hashedKey) return false;
            }
            if(occupied[hashedKey]) {
                occupied[hashedKey] = false;
                --count;
                return true;
            }
            return false;
        }

        bool get(const K& key, V& value) const {
            int hashedKey = hash(key);
            int startHash = hashedKey;
            while(occupied[hashedKey] && table[hashedKey].first != key) {
                hashedKey = (hashedKey + 1) % capacity;
                if(startHash == hashedKey) return false;
            }
            if(occupied[hashedKey]) {
                value = table[hashedKey].second;
                return true;
            }
            return false;
        }

        int size() const {
            return count;
        }
};

int main() {}

