#include <core/Common.hpp>
#include <iostream>
using namespace std;

// Definition for a Node.
class Node {
public:
  int val;
  vector<Node *> neighbors;
  Node() {
    val = 0;
    neighbors = vector<Node *>();
  }
  Node(int _val) {
    val = _val;
    neighbors = vector<Node *>();
  }
  Node(int _val, vector<Node *> _neighbors) {
    val = _val;
    neighbors = _neighbors;
  }
};

class Solution {
public:
  Node *cloneGraph(Node *_node) {
    if (_node == nullptr)
      return nullptr;

    unordered_map<Node *, Node *> seen;
    queue<Node *> q;

    q.push(_node);
    seen.insert({_node, new Node(_node->val)});

    while (!q.empty()) {
      auto cnode = q.front();
      q.pop();
      auto pit = seen.find(cnode);

      for (auto child : cnode->neighbors) {
        auto it = seen.find(child);

        if (it == std::end(seen)) {
          q.push(child);
          it = seen.insert({child, new Node(child->val)}).first;
        }

        pit->second->neighbors.push_back(it->second);
      }
    }

    return seen.find(_node)->second;
  }
};

int main() {
  {
    Node *n1 = new Node(1);
    Node *n2 = new Node(2);
    Node *n3 = new Node(3);
    Node *n4 = new Node(4);

    n1->neighbors.push_back(n2);
    n1->neighbors.push_back(n4);

    n2->neighbors.push_back(n1);
    n2->neighbors.push_back(n3);

    n3->neighbors.push_back(n2);
    n3->neighbors.push_back(n4);

    n4->neighbors.push_back(n1);
    n4->neighbors.push_back(n3);

    cout << hex << Solution{}.cloneGraph(n1) << std::endl;
  }

  {
    Node *n1 = new Node(1);

    cout << hex << Solution{}.cloneGraph(n1) << std::endl;
  }

  { cout << hex << Solution{}.cloneGraph(nullptr) << std::endl; }
}
