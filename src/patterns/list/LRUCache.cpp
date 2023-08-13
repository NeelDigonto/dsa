#include <core/Common.hpp>
#include <core/List.hpp>
#include <iostream>
using namespace std;

class LRUCache {
private:
  list<pair<int, int>> registry_;
  unordered_map<int, decltype(registry_)::iterator> index_;

public:
  LRUCache(int capacity) { index_.reserve(capacity); }

  int get(int key) {
    const auto it = index_.find(key);

    if (it != end(index_))
      return it->second->second;
  }

  void put(int key, int value) {
    const auto it = index_.find(key);

    if (it == end(index_)) {
      registry_.push_back({key, value});
      index_.insert({key, prev(registry_.end())});
    } else {
      it->second->second = 0;
    }
  }
};

int main() {
  {
    LRUCache *lRUCache = new LRUCache(2);
    lRUCache->put(1, 1);              // cache is {1=1}
    lRUCache->put(2, 2);              // cache is {1=1, 2=2}
    cout << lRUCache->get(1) << endl; // return 1
    lRUCache->put(3, 3);              // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
    cout << lRUCache->get(2) << endl; // returns -1 (not found)
    lRUCache->put(4, 4);              // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
    cout << lRUCache->get(1) << endl; // return -1 (not found)
    cout << lRUCache->get(3) << endl; // return 3
    cout << lRUCache->get(4) << endl; // return 4
  }
  cout << endl;
}