#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool visited[10001];
vector <string> answer;

bool dfs(int l,string start,vector<vector<string>> tickets){
    //모든 경로를 탐색했을 경우
    if(l==tickets.size()){
        return true; 
    }

    for(int i=0;i<tickets.size();i++){
        if(start==tickets[i][0]&&!visited[i]){ //start가 갈 수 있는 곳 중 방문하지 않은 경로
            visited[i]= true;
            answer.push_back(tickets[i][1]);
            bool check = dfs(l + 1, tickets[i][1], tickets);
            if(check) return true; // 하나라도 탐색을 더 이상 탐색 안 함 return
            visited[i]= false;
            answer.pop_back();
        }
    }
    
    return false;
}

vector<string> solution(vector<vector<string>> tickets) {
    sort(tickets.begin(),tickets.end()); // 알파벳 순서가 앞서는 경로로     
    
    answer.push_back("ICN");
    dfs(0,"ICN", tickets);
    
    return answer;
}
