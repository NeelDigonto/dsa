#include <core/Common.hpp>
#include <iostream>
using namespace std;

class Solution {
public:
  vector<string> topKFrequent(const vector<string> &words, int k) {
    unordered_map<std::string, int8_t> registry;
    priority_queue<pair<int8_t, string>, vector<pair<int8_t, string>>, less<pair<int8_t, string>>> min_heap;
    vector<string> result_set(k, string{});

    for (auto &word : words)
      registry[word]++;

    for (auto &el : registry) {
      min_heap.emplace(pair<int8_t, string>{-el.second, el.first});

      if (min_heap.size() > k)
        min_heap.pop();
    }

    for (size_t i = k - 1; i != -1; --i)
      result_set[i] = min_heap.top().second, min_heap.pop();

    return result_set;
  }
};

int main() {
  cout << Solution{}.topKFrequent({"i", "love", "leetcode", "i", "love", "coding"}, 2) << endl; // ["i","love"]
  cout << Solution{}.topKFrequent({"the", "day", "is", "sunny", "the", "the", "the", "sunny", "is", "is"}, 4)
       << endl; // ["the","is","sunny","day"]
}