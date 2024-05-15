#include <algorithm>
#include <vector>

// https://school.programmers.co.kr/learn/courses/30/lessons/12982#
using namespace std;

int solution(vector<int> d, int budget) {

    sort(d.begin(), d.end()); // 정렬

    for (int i = 0; i < d.size(); i++) {
        if (budget - d[i] >= 0) {
            budget -= d[i];
        }
        else {
            return i;
        }
    }
}
