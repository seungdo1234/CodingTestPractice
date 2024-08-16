#include <string>
#include <vector>
#include <queue>

// https://school.programmers.co.kr/learn/courses/30/lessons/43162?language=cpp

using namespace std;

bool visited[200] = {false,};

void BFS(vector<vector<int>> computers , int startNode){
    
    queue<int> q;
    
    q.push(startNode);
    visited[startNode] = true;
    
    while(!q.empty()){
        int node = q.front();
        
        q.pop();
        
        for(int i = 0 ; i< computers[node].size(); i++){
            if(!visited[i] && computers[node][i] == 1){
                visited[i] = true;
                q.push(i);
            }
        }
        
    }
}

int solution(int n, vector<vector<int>> computers) {

    int answer = 0;
    for(int i = 0; i< n; i++){
        if(!visited[i]){
            BFS(computers , i);
            answer++;
       }
    }
    

    return answer;
}
