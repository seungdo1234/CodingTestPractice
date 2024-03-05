#include <string>
#include <vector>
#include <map>
// https://school.programmers.co.kr/learn/courses/30/lessons/150370# 개인정보 수집 유효기간
using namespace std;

map <string,int> maps;
vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    
    // 현재 총 일수 구하기
    int t_Year = stoi(today.substr(0,4));
    int t_Month = stoi(today.substr(5,7));
    int t_Date = stoi(today.substr(8,today.length()));
    int t_Days = (t_Year * 12 * 28) + (t_Month * 28) + t_Date;
       
    // 약관 종류마다 유효기간 맵에 저장
    for(int i = 0; i<terms.size(); i++){               \
        string info = terms[i].substr(0,1);
        maps[info] = stoi(terms[i].substr(2,terms[i].length()));
    }
       
    // 각각의 개인 정보 총 만료일수 구하고 날짜가 지났는지 비교
    for(int i = 0; i<privacies.size(); i++){
        string info = privacies[i].substr(11,1); // 약관 종류
        int year = stoi(privacies[i].substr(0,4)); // 년도
        int month = stoi(privacies[i].substr(5,2)) + maps[ privacies[i].substr(11,1)]; // 월 + 약관 유효기간
        int date = stoi(privacies[i].substr(8,2)); // 일
        
        // 개인 정보 만료일 구하기
        int days = (year * 12 * 28) + (month * 28) + date;
        
        // 현재와 비교
        if(t_Days >= days){
            answer.push_back(i+ 1);
        }       
    }    
    return answer;
}
