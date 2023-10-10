#include <core/Common.hpp>
#include <core/Graph.hpp>
#include <iostream>
using namespace std;

class Solution {
public:
  vector<vector<string>> accountsMerge(const vector<vector<string>> &_accounts) {
    DSU<uint16_t> dsu(_accounts.size());
    unordered_map<string, uint16_t> registry;

    for (size_t aid = 0; aid != _accounts.size(); ++aid) {
      for (size_t eid = 1; eid != _accounts[aid].size(); ++eid) {
        const auto &email = _accounts[aid][eid];
        auto find_res = registry.find(email);

        if (find_res == end(registry)) {
          registry[email] = aid;
        }

        else {
          dsu.connect(aid, find_res->second);
        }
      }
    }

    unordered_map<uint16_t, vector<string>> aid_accounts_map;

    for (auto &[email, aid] : registry) {
      aid_accounts_map[dsu.find(aid)].push_back(email);
    }

    vector<vector<string>> merged_accounts(aid_accounts_map.size());
    size_t idx = 0;

    for (auto it = begin(aid_accounts_map); it != end(aid_accounts_map); ++it, ++idx) {
      merged_accounts[idx] = std::move(it->second);

      auto &name = _accounts[it->first][0];
      merged_accounts[idx].push_back(name);
      iter_swap(begin(merged_accounts[idx]), rbegin(merged_accounts[idx]));

      sort(next(begin(merged_accounts[idx])), end(merged_accounts[idx]));
    }

    return merged_accounts;
  }
};

int main() {
  cout << Solution{}.accountsMerge({{"John", "johnsmith@mail.com", "john_newyork@mail.com"},
                                    {"John", "johnsmith@mail.com", "john00@mail.com"},
                                    {"Mary", "mary@mail.com"},
                                    {"John", "johnnybravo@mail.com"}})
       << endl;
  // [["John","john00@mail.com","john_newyork@mail.com","johnsmith@mail.com"],
  //  ["Mary","mary@mail.com"],
  //  ["John","johnnybravo@mail.com"]]
  cout << Solution{}.accountsMerge({{"Gabe", "Gabe0@m.co", "Gabe3@m.co", "Gabe1@m.co"},
                                    {"Kevin", "Kevin3@m.co", "Kevin5@m.co", "Kevin0@m.co"},
                                    {"Ethan", "Ethan5@m.co", "Ethan4@m.co", "Ethan0@m.co"},
                                    {"Hanzo", "Hanzo3@m.co", "Hanzo1@m.co", "Hanzo0@m.co"},
                                    {"Fern", "Fern5@m.co", "Fern1@m.co", "Fern0@m.co"}})
       << endl;
  // [["Ethan","Ethan0@m.co","Ethan4@m.co","Ethan5@m.co"],
  //  ["Gabe","Gabe0@m.co","Gabe1@m.co","Gabe3@m.co"],
  //  ["Hanzo","Hanzo0@m.co","Hanzo1@m.co","Hanzo3@m.co"],
  //  ["Kevin","Kevin0@m.co","Kevin3@m.co","Kevin5@m.co"],
  //  ["Fern","Fern0@m.co","Fern1@m.co","Fern5@m.co"]]
}
