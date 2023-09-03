#include <core/Common.hpp>
#include <iostream>
using namespace std;

class MedianFinder {
private:
  priority_queue<int, vector<int>, less<int>> lower_half;
  priority_queue<int, vector<int>, greater<int>> upper_half;

public:
  MedianFinder() {}

  void addNum(int num) {
    if (!lower_half.size() || num <= lower_half.top())
      lower_half.push(num);
    else
      upper_half.push(num);

    if (upper_half.size() > lower_half.size())
      lower_half.push(upper_half.top()), upper_half.pop();

    if (lower_half.size() - upper_half.size() == 2)
      upper_half.push(lower_half.top()), lower_half.pop();
  }

  double findMedian() {
    if (lower_half.size() == upper_half.size())
      return (lower_half.top() + upper_half.top()) / 2.0;

    else
      return static_cast<double>(lower_half.top());
  }
};

int main() {
  {
    MedianFinder medianFinder;
    medianFinder.addNum(1);                    // arr = [1]
    medianFinder.addNum(2);                    // arr = [1, 2]
    cout << medianFinder.findMedian() << endl; // return 1.5 (i.e., (1 + 2) / 2)
    medianFinder.addNum(3);                    // arr[1, 2, 3]
    cout << medianFinder.findMedian() << endl; // return 2.0 }
  }
}