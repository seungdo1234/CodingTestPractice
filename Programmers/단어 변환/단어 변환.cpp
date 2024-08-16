#include <string>
#include <vector>
#include <queue>

// https://school.programmers.co.kr/learn/courses/30/lessons/43163

using namespace std;

pair<bool,int> visited [50];

bool IsTransitionWord(string curWord, string target){
    int match = 0;
    for(int i = 0; i< curWord.length(); i++){
        if(curWord[i] == target[i])
            match++;
    }
    
    return match == curWord.length() - 1; 
}

int BFS(string begin, string target, vector<string> words){
    int n =words.size() ,m = words[0].size(), count = 1;
    queue<int> q;
    
    for(int i = 0; i < n; i++){
        if(IsTransitionWord(begin, words[i]))
        {
            visited[i].first = true;
            visited[i].second = 1;
            q.push(i);
        }
    }
    
    while(!q.empty()){
        int wordNum = q.front();
        
        if(words[wordNum] == target){
            
            return visited[wordNum].second;
        }
        q.pop();
        
        for(int i = 0; i< n; i++){
            
            if(!visited[i].first && IsTransitionWord(words[wordNum], words[i])){
                visited[i].first = true;
                visited[i].second = visited[wordNum].second + 1;
                q.push(i);
            }
        }
    }
}

int solution(string begin, string target, vector<string> words) {

    for(int i = 0; i < words.size(); i++){
        if(target == words[i])
            break;
        
        if(i == words.size() - 1)
            return 0;
    }
    
    return  BFS(begin, target, words);
}
