#include <core/Common.hpp>
#include <iostream>
using namespace std;

class RandomizedSet {
  vector<int> container_;
  unordered_map<int, uint32_t> registry_;

public:
  RandomizedSet() {}

  bool insert(int val) {
    if (registry_.find(val) != end(registry_))
      return false;

    container_.push_back(val);
    registry_.emplace(move(pair<int, uint32_t>{val, container_.size() - 1}));
    return true;
  }

  bool remove(int val) {
    const auto registry_value_it = registry_.find(val);
    if (registry_value_it == end(registry_))
      return false;

    const auto last_el = *prev(end(container_));
    const auto container_val_index = registry_.find(val)->second;

    container_[container_val_index] = last_el;
    registry_[last_el] = container_val_index;

    registry_.erase(val);
    container_.pop_back();
    return true;
  }

  int getRandom() {

    const auto rand_index = random() % container_.size();
    return container_[rand_index];
  }
};

int main() {
  {
    RandomizedSet randomizedSet;
    cout << boolalpha << randomizedSet.insert(1)
         << endl; // Inserts 1 to the set. Returns true as 1 was inserted successfully.
    cout << boolalpha << randomizedSet.remove(2) << endl; // Returns false as 2 does not exist in the set.
    cout << boolalpha << randomizedSet.insert(2) << endl; // Inserts 2 to the set, returns true. Set now contains [1,2].
    cout << boolalpha << randomizedSet.getRandom() << endl; // getRandom() should return either 1 or 2 randomly.
    cout << boolalpha << randomizedSet.remove(1) << endl; // Removes 1 from the set, returns true. Set now contains [2].
    cout << boolalpha << randomizedSet.insert(2) << endl; // 2 was already in the set, so return false. std::cout <<
    cout << boolalpha << randomizedSet.getRandom()
         << endl; // Since 2 is the only number in the set, getRandom() will always return 2.
  }
  cout << endl;

  {
    RandomizedSet randomizedSet;
    cout << boolalpha << randomizedSet.remove(0) << endl;
    cout << boolalpha << randomizedSet.remove(0) << endl;
    cout << boolalpha << randomizedSet.insert(0) << endl;
    cout << boolalpha << randomizedSet.getRandom() << endl;
    cout << boolalpha << randomizedSet.remove(0) << endl;
    cout << boolalpha << randomizedSet.insert(0) << endl;
  }
  cout << endl;

  {
    RandomizedSet randomizedSet;
    cout << boolalpha << randomizedSet.insert(0) << endl;
    cout << boolalpha << randomizedSet.insert(1) << endl;
    cout << boolalpha << randomizedSet.remove(0) << endl;
    cout << boolalpha << randomizedSet.insert(2) << endl;
    cout << boolalpha << randomizedSet.remove(1) << endl;
    cout << boolalpha << randomizedSet.getRandom() << endl;
  }
}
