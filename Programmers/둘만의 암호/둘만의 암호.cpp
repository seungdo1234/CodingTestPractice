#include <string>
#include <vector>
// https://school.programmers.co.kr/learn/courses/30/lessons/155652
using namespace std;

string solution(string s, string skip, int index) {
    string answer = "";
    
    for(int i =0; i<s.length(); i++){
        int ascii = s[i]; // 알파벳 별 아스키코드를 변수에 저장
        // 알파벳을 index 만큼 변환
        for(int j = 0; j< index; j++){
            // z == 122, z일 때 a로 변환
            if(ascii == 122) ascii = 97;
            else ascii++;
            
            // 스킵문자열에 해당 알파벳이 있다면 스킵
            if(skip.find(ascii) != string::npos) j--;           
        }      
        // 최종 알파벳을 문자열에 저장
        answer += ascii;       
    }    
    return answer;
}
