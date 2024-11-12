#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    
    int half = s.length() / 2;
    if(s.length() % 2 == 0){
        answer += s[half -1];
    }
    answer += s[half];
    
    return answer;
}