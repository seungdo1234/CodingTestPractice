#include <string>
#include <vector>
// https://school.programmers.co.kr/learn/courses/30/lessons/159994
using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    // 카드 1, 2의 순서
    int cardNum[2] = {0,0};
    
    for(int i = 0; i < goal.size(); i++){     
        // goal 문자열에 맞는 카드를 선택, 만약 없다면 No return
        if(cards1[cardNum[0]] == goal[i]) cardNum[0]++;
        else if (cards2[cardNum[1]] == goal[i]) cardNum[1]++;
        else return "No";     
    }
    // 선택이 완료됐다면 Yes return
    return "Yes";
}
