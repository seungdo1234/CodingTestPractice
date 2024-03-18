#include <string>
#include <vector>
#include <map>
#include <algorithm>
// https://school.programmers.co.kr/learn/courses/30/lessons/131128#
using namespace std;

map <char, int> maps; // 찾아본 숫자의 순서를 저장하는 맵

bool cmp (char a, char b){ // 내림차순 정렬
    return a > b;
}
string solution(string X, string Y) {
    vector <char> vec; // 짝꿍 벡터
    string answer = "";
    
    for(int i = 0; i< X.length(); i++){
        // 처음 찾아보는 숫자는 0
        // 문자열 Y에 있는 숫자라면 해당 숫자 순서 + 1
        // 문자열 Y에 없는 숫자라면 -1
        int num = maps[X[i]]; 
        
        // 이미 숫자를 찾아봤을 때 없는 숫자라면 continue
        if(num == -1) continue;
        
        // 문자열 Y를 찾아봐야 할 때 num부터 탐색
        for(int j = num; j< Y.length(); j++){
            if(X[i] == Y[j]){ // 같은 숫자가 있을 경우
                maps[X[i]] = j + 1; // 맵에 순서 + 1 저장
                vec.push_back(X[i]); // 짝꿍 벡터에 저장
                break;
            }
            
            // 해당 숫자를 마지막까지 못 찾았을 때 맵에 -1 저장
            if(j == Y.length() - 1){ maps[X[i]] = -1; }
        }
    }

    // 짝꿍이 없을 때 -1 반환
    if(vec.size() == 0){return "-1";}
    
    // 내림차순 정렬
    sort(vec.begin(), vec.end(), cmp);
    
    // 0이 가장 큰수라면 0반환
    if(vec[0] == '0'){return "0";}
    
    for(int i = 0; i < vec.size(); i++){
        answer+=vec[i];
    }

    return answer; // 가장 큰수 반환    
}
