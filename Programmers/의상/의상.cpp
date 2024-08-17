#include <string>
#include <vector>
#include <map>

// https://school.programmers.co.kr/learn/courses/30/lessons/42578#

using namespace std;

map <string, int> maps;
int solution(vector<vector<string>> clothes) {
    int answer = 1;
    
    for(int i = 0; i< clothes.size(); i++){
        maps[clothes[i][1]]++;
    }
    
     for(auto it = maps.begin(); it != maps.end(); it++){
            answer *= it -> second + 1; // 입지 않는 경우 + 1
    }
    
    return answer - 1; // 아무것도 입지 않은 경우는 존재하지 않으니 -1
}
