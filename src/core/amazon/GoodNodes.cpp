#include <iostream>

#include <core/Common.hpp>
using namespace std;

int main() {
  vector<uint16_t> nodes(20, 0);

  int count = 0;
  for (const auto &node : nodes)
    if (node >= 5 * 2)
      count++;
}
