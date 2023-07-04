#include <core/Common.hpp>
#include <iostream>
using namespace std;

class Solution {
private:
  struct RegistryHasher {
    std::size_t operator()(const std::array<uint16_t, 26> &_registry) const {
      std::size_t hash_value = 0;

      hash_value = reduce(begin(_registry), end(_registry), 0llu);
      return hash_value;
    }
  };

  array<uint16_t, 26> getRegistry(const string &_str) {
    array<uint16_t, 26> registry;
    registry.fill(0);

    for (auto ch : _str)
      registry[ch - 'a']++;

    return registry;
  }

public:
  vector<vector<string>> groupAnagrams(const vector<string> &strs) {
    unordered_map<array<uint16_t, 26>, vector<string>, RegistryHasher> anagrams_map;

    for (auto &str : strs) {
      const auto registry = getRegistry(str);
      anagrams_map[registry].push_back(str);
    }

    vector<vector<string>> grouped_anagrams;

    for (auto &[_, anamgram] : anagrams_map)
      grouped_anagrams.emplace_back(move(anamgram));

    return grouped_anagrams;
  }
};

/*
class Solution {
 public:
  vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string>> registry;

    for (auto& s : strs) {
      auto identity = s;
      sort(identity.begin(), identity.end());

      registry[identity].push_back(s);
    }

    vector<vector<string>> groupedAnagrams;
    groupedAnagrams.reserve(registry.size());
    for (auto& group : registry) groupedAnagrams.push_back(move(group.second));

    return groupedAnagrams;
  }
};
*/

int main() {
  cout << Solution{}.groupAnagrams({"eat", "tea", "tan", "ate", "nat", "bat"}) << endl;
  cout << Solution{}.groupAnagrams({""}) << endl;
  cout << Solution{}.groupAnagrams({"a"}) << endl;
}
