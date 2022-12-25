#include <core/Common.hpp>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> topStudents(const vector<string>& positive_feedback, const vector<string>& negative_feedback, const vector<string>& report, const vector<int>& student_id, int k) {
        unordered_set<string> pf_cache(begin(positive_feedback), end(positive_feedback));
        unordered_set<string> nf_cache(begin(negative_feedback), end(negative_feedback));
        vector<pair<int, int>> student_scores; // score, id
        student_scores.reserve(student_id.size());

        for (int i = 0; i != report.size(); ++i) {
            const auto& a_report = report[i];
            int student_score = 0;

            istringstream iss(a_report);
            string word;
            while (getline(iss, word, ' ')) {
                if (pf_cache.find(word) != pf_cache.end()) student_score += 3;
                if (nf_cache.find(word) != nf_cache.end()) student_score -= 1;
            }

            student_scores.emplace_back(pair{ student_score, student_id[i] });
        }


        sort(begin(student_scores), end(student_scores), [](const auto& lhs, const auto& rhs) {
            if (lhs.first > rhs.first) return true;
        if (lhs.first == rhs.first && lhs.second < rhs.second) return true;
        return false;
            });

        vector<int> result_set;
        result_set.reserve(k);
        for (size_t i = 0; i != k; ++i) {
            result_set.emplace_back(student_scores[i].second);
        }

        return result_set;
    }
};



int main() {
    cout << Solution{}.topStudents({ "smart","brilliant","studious" }, { "not" }, { "this student is studious","the student is smart" }, { 1,2 }, 2) << endl;
    cout << Solution{}.topStudents({ "smart","brilliant","studious" }, { "not" }, { "this student is not studious","the student is smart" }, { 1,2 }, 2) << endl;
    cout << Solution{}.topStudents({ "fkeofjpc", "qq", "iio" }, { "jdh", "khj", "eget", "rjstbhe", "yzyoatfyx", "wlinrrgcm" }, { "rjstbhe eget kctxcoub urrmkhlmi yniqafy fkeofjpc iio yzyoatfyx khj iio", "gpnhgabl qq qq fkeofjpc dflidshdb qq iio khj qq yzyoatfyx", "tizpzhlbyb eget z rjstbhe iio jdh jdh iptxh qq rjstbhe", "jtlghe wlinrrgcm jnkdbd k iio et rjstbhe iio qq jdh", "yp fkeofjpc lkhypcebox rjstbhe ewwykishv egzhne jdh y qq qq", "fu ql iio fkeofjpc jdh luspuy yzyoatfyx li qq v", "wlinrrgcm iio qq omnc sgkt tzgev iio iio qq qq", "d vhg qlj khj wlinrrgcm qq f jp zsmhkjokmb rjstbhe" }, { 96537918, 589204657, 765963609, 613766496, 43871615, 189209587, 239084671, 908938263 }, 3) << endl;
}