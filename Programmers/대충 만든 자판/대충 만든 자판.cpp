#include <string>
#include <vector>
#include<map>
// https://school.programmers.co.kr/learn/courses/30/lessons/160586
using namespace std;

// 문자 별 키보드 입력 횟수 저장 맵
map <char,int> keys;

vector<int> solution(vector<string> keymap, vector<string> targets) {
    vector<int> answer;
    
    // 문자 별 키보드 입력 횟수가 가장 적은 횟수를 맵에 저장
    for(int i = 0; i< keymap.size(); i++){
        for(int j = 0; j<  keymap[i].length(); j++){       
            if(keys[keymap[i][j]] == 0 || keys[keymap[i][j]]  > j + 1){
                keys[keymap[i][j]] = j + 1;
            }
        }
    }
  
    // 타겟 문자 별 키보드 입력 횟수 계산
    for(int i = 0; i<targets.size(); i++){
        int result = 0;
        for(int j = 0;j< targets[i].length(); j++){
            // 맵에 저장된 문자 별 입력 횟수가 0일때는 키보드 자판에 없는 문자이므로 -1
            if(keys[targets[i][j]] == 0){
                result = -1;
                break;
            }
            result += keys[targets[i][j]];
        }
            answer.push_back(result);
    }
    
    return answer;
}
