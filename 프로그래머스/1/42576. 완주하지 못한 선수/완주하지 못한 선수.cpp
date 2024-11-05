#include <string>
#include <vector>
#include <map>
using namespace std;

map<string, int> completionMap;
string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    
    for(int i = 0; i < completion.size(); i++){
        completionMap[completion[i]]++;
    }
    
    for(int i = 0; i< participant.size(); i++){
        if(completionMap[participant[i]] == 0){
            answer = participant[i];
            break;
        }
        
        completionMap[participant[i]]--;
    }
        return answer;
}