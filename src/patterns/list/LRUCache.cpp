#include <core/Common.hpp>
#include <core/List.hpp>
#include <iostream>
using namespace std;

class LRUCache {
private:
  size_t capacity_;
  list<pair<int, int>> list_;
  unordered_map<int, decltype(list_)::iterator> index_;

public:
  LRUCache(int capacity) {
    capacity_ = capacity;
    index_.reserve(capacity + 1);
  }

  int get(int key) {
    const auto it = index_.find(key);

    if (it == end(index_))
      return -1;

    if (it != end(index_)) {
      int value = it->second->second;

      if (it->second == begin(list_))
        return value;

      list_.erase(it->second);
      list_.push_front({key, value});

      index_.erase(key);
      index_.insert({key, begin(list_)});

      return value;
    }
  }

  void put(int key, int value) {
    const auto it = index_.find(key);

    const auto present = it != end(index_);

    if (present) {
      if (it->second != begin(list_))
        return;

      list_.erase(it->second);
      index_.erase(key);
    }

    list_.push_front({key, value});
    index_.insert({key, begin(list_)});

    if (index_.size() > capacity_) {
      index_.erase(list_.rbegin()->first);
      list_.pop_back();
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