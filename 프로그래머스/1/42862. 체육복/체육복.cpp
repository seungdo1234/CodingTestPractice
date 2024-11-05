#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

unordered_map <int, int> m;
int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = n;
    
    for(int i = 0; i < reserve.size(); i++){
        m[reserve[i]]++;
    }
    
    for(int i = 0; i < lost.size(); i++){
        m[lost[i]]--;
    }
    
    sort(lost.begin(), lost.end());
    
     for(int i = 0; i < lost.size(); i++){  
         if(m[lost[i]] == 0)
             continue;
         
         if(m[lost[i] - 1] == 1){
             m[lost[i] - 1]--;
         }
        else if(m[lost[i] + 1]== 1){
             m[lost[i] + 1] --;
         }
         else{
             answer--;
         }
    }
    return answer;
}