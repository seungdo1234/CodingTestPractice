#include <string>
#include <vector>
#include<map>
// https://school.programmers.co.kr/learn/courses/30/lessons/178871
using namespace std;

map<string,int> playerMap; // 플레이어 개별 등수 저장 맵

vector<string> solution(vector<string> players, vector<string> callings) {
    vector<string> answer;
    
    // 플레이어 개별 등수 저장 및 answer에 Player 저장
    for(int i =0; i<players.size(); i++){ 
        playerMap[players[i]] = i;
        answer.push_back(players[i]);
    }
    
    string tmp;
    for(int i =0; i<callings.size(); i++){
        // 순서를 변경할 Player의 현재 등수 저장
        int rank =  playerMap[callings[i]]; 
        
        // 앞 순서인 플레이어와 등수 교체
        tmp = answer[rank];
        answer[rank] = answer[rank - 1];
        answer[rank - 1] = tmp;
        
        // 현재 순위 최신화
        playerMap[callings[i]]--;
        playerMap[answer[rank]] ++;      
    }
    
    return answer;
}
