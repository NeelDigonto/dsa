#include <core/Common.hpp>
#include <iostream>
using namespace std;

class HitCounter {
private:
  queue<int> hits_;

public:
  HitCounter() {}

  void hit(int timestamp) { hits_.push(timestamp); }

  int getHits(int timestamp) {
    while (!hits_.empty()) {
      const auto time_diff = timestamp - hits_.front();

      if (time_diff >= 300)
        hits_.pop();
      else
        break;
    }

    return hits_.size();
  }
};

int main() {

  {
    HitCounter hit_counter;
    hit_counter.hit(1);                       // hit at timestamp 1.
    hit_counter.hit(2);                       // hit at timestamp 2.
    hit_counter.hit(3);                       // hit at timestamp 3.
    cout << hit_counter.getHits(4) << endl;   // get hits at timestamp 4, return 3.
    hit_counter.hit(300);                     // hit at timestamp 300.
    cout << hit_counter.getHits(300) << endl; // get hits at timestamp 300, return 4.
    cout << hit_counter.getHits(301) << endl; // get hits at timestamp 301, return 3.
  }
}
