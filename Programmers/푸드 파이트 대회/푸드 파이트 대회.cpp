#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// https://school.programmers.co.kr/learn/courses/30/lessons/134240
bool cmp (char a, char b){
    return a > b;
}
string solution(vector<int> food) {
    string answer = "", person01 = "",person02 = "";
    
    // 한 선수가 먹는 음식의 순서를 구한다.
    for(int i = 1; i< food.size(); i++){        
        for(int j = 0; j < food[i] / 2 ; j++){
            person01 += to_string(i);
        }
    }
    // 내림차순 정렬하여 다른 선수의 음식 순서를 구한다.
    person02 = person01;   
    sort(person02.begin(), person02.end(), cmp);    
    // 두 선수의 음식 순서를 가운데 물(0) 기준으로 양 옆에 배치한다.
    answer += person01 + "0" + person02;
 
    return answer;
}
