#include <string>
#include <vector>
// https://school.programmers.co.kr/learn/courses/30/lessons/147355
using namespace std;

int solution(string t, string p) {
    int answer = 0;
    
    for(int i =0; i <= t.length() - p.length(); i++ ){
        // 문자열 파싱 후 p와 비교
        string str = t.substr(i, p.length());
        if(str <= p) answer ++;
    }
    return answer;
}
