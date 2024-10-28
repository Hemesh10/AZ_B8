#include <iostream>
#include <list>
using namespace std;

template <typename K, typename V>
class UnorderedMapChaining {
    private:
        static const int defaultCapacity = 10;
        list<pair<K, V>>* table;
        int capacity;
        int count;

        int hash(const K& key) const {
            return key % capacity;
        }

    public:
        UnorderedMapChaining(int cap = defaultCapacity) : capacity(cap), count(0) {
            table = new list<pair<K, V>>[capacity];
        }

        ~UnorderedMapChaining() {
            delete[] table;
        }

        void insert(const K& key, const V& value) {
            int hashedKey = hash(key);
            for(auto& pair:table[hashedKey]) {
                if(pair.first == key) {
                    pair.second = value;
                    return;
                }
            }
            table[hashedKey].emplace_back(key, value);
            ++count;
        }

        bool get(const K& key, V& value) const {
            int hashedKey = hash(key);
            for(auto& pair:table[hashedKey]) {
                if(pair.first == key) {
                    value = pair.second;
                    return true;
                }
            }
            return false;
        }

        bool erase(const K& key) {
            int hashedKey = hash(key);
            for(auto it = table[hashedKey].begin(); it != table[hashedKey].end(); ++it) {
                if(it->first == key) {
                    table[hashedKey].erase(it);
                    --count;
                    return true;
                }
            }
            return false;
        }

        int size() const {
            return count;
        }
};

int main() {}
