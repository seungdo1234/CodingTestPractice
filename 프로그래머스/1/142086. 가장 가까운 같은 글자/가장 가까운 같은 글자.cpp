#include <string>
#include <vector>
#include <map>
#include<iostream>
using namespace std;
map <char, int> word;

vector<int> solution(string s) {
    vector<int> answer;
    
    for(int i = 0; i < s.length(); i++){
        if(word[s[i]] == 0){
            answer.push_back(-1);
        }
        else{
            answer.push_back(i + 1 - word[s[i] ]);
        }
         word[s[i]] = i + 1;     
    }
    return answer;
}