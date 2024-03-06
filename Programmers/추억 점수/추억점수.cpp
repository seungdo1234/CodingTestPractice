#include <string>
#include <vector>
#include <map>
using namespace std;
// https://school.programmers.co.kr/learn/courses/30/lessons/176963

// 인물 별 그리움 점수를 저장하는 맵
map <string, int> scoreMaps;
vector<int> solution(vector<string> name, vector<int> yearning, vector<vector<string>> photo) {
    vector<int> answer;
    
    // 인물 별 그리움 점수를 맵에 저장
    for(int i = 0; i < name.size(); i++){
        scoreMaps[name[i]] = yearning[i];
    }        
    
    // 사진 별 추억 점수 산출
    for(int i =0; i<photo.size(); i++){
        int score = 0;
        for(int j = 0; j < photo[i].size(); j++){
            score += scoreMaps[photo[i][j]];
        }
        answer.push_back(score);
    }
    
    return answer;
}
