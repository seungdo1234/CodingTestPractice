#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

// 조합을 구하는 함수
void combination(string order, string comb, int idx, int length, map<string, int>& combCount) {
    if (comb.size() == length) {
        sort(comb.begin(), comb.end()); // 알파벳 순서로 정렬
        combCount[comb]++; // 조합의 출현 횟수를 증가시킴
        return;
    }
    for (int i = idx; i < order.size(); i++) {
        combination(order, comb + order[i], i + 1, length, combCount);
    }
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;

    // 코스 요리 길이별로 가장 많이 주문된 조합을 찾기 위한 반복문
    for (int cLength : course) {
        map<string, int> combCount; // 각 조합의 출현 횟수를 저장하는 맵
        int maxCount = 0; // 가장 많이 주문된 횟수

        // 각 주문마다 조합을 만들어서 카운트
        for (string order : orders) {
            if (order.size() >= cLength) {
                combination(order, "", 0, cLength, combCount);
            }
        }

        // 가장 많이 주문된 조합을 찾음
        for (auto& comb : combCount) {
            if (comb.second > 1) { // 최소 2명 이상의 손님이 선택한 경우
                maxCount = max(maxCount, comb.second);
            }
        }

        // 가장 많이 주문된 조합들을 answer에 추가
        for (auto& comb : combCount) {
            if (comb.second == maxCount && comb.second > 1) {
                answer.push_back(comb.first);
            }
        }
    }

    // 정답을 사전순으로 정렬
    sort(answer.begin(), answer.end());

    return answer;
}
