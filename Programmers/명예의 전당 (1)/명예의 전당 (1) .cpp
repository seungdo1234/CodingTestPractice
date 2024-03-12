#include <string>
#include <vector>
#include <algorithm>
// https://school.programmers.co.kr/learn/courses/30/lessons/138477
using namespace std;

vector<int> solution(int k, vector<int> score) {
    vector<int> answer;
    vector<int> hallOfFame; // 명예의 전당
    
    for(int i = 0; i < score.size(); i++){
       // 명예의 전당 점수의 갯수가 k 이하 일때, 명예의 전당의 최소 점수가 score[i] 보다 작을 때 
       if(hallOfFame.size() == k && hallOfFame[0] < score[i]){
            hallOfFame[0] = score[i]; // 명예의 전당 점수 교체
        }
        else if(hallOfFame.size() < k){
            hallOfFame.push_back(score[i]); // 명예의 전당 점수 추가
        }

        // 오름차순 정렬
        sort(hallOfFame.begin(), hallOfFame.end());
        
        // 최소 점수 추가
        answer.push_back(hallOfFame[0]);
    }    
    return answer;
}
