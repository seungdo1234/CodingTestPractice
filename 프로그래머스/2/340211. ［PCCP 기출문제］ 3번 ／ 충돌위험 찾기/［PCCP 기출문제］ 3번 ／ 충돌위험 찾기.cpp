#include <string>
#include <vector>
#include<queue>
#include<map>
#include<iostream>
using namespace std;


int GetDir(int cur, int goal){
    return cur < goal ? 1 : -1;  
}
int solution(vector<vector<int>> points, vector<vector<int>> routes) {
    int answer = 0;
    
    vector<vector<pair<int,int>>> move;
    queue<pair<pair<int,int>,pair<int,int>>> q;
    
    for(int i = 0; i < routes.size(); i++){
        vector<pair<int,int>> temp;
        for(int j = 0; j < routes[i].size(); j++){
            if(j == 0){
                q.push({{i , 1}, {points[routes[i][j] - 1][0],  points[routes[i][j] - 1][1]}});
            }
            temp.push_back({points[routes[i][j] - 1][0], points[routes[i][j] - 1][1]});
        }
        move.push_back(temp);
    }
    
    map<pair<int,int>, int> curRobotPos;
    for(int i = 0; i < move.size(); i++){
        curRobotPos[{move[i][0].first, move[i][0].second}]++;
    }
    for(auto it = curRobotPos.begin(); it != curRobotPos.end(); it++){
        if(it->second > 1){
            answer++;
        }
        }
    
    
    while(!q.empty()){
        map<pair<int,int>, int> curRobotMap;
        int size = q.size();
        for(int i = 0; i <size; i++){
            int robotNum = q.front().first.first;
            int curArriveNum = q.front().first.second;
            pair<int, int> curPos=  q.front().second;
            pair<int,int> goal = move[robotNum][curArriveNum];
            
            q.pop();
            
            if(curPos.first != goal.first){
                curPos.first += GetDir(curPos.first, goal.first);
            }
            else{
                curPos.second += GetDir(curPos.second, goal.second);
            }

            
            curRobotMap[curPos] ++;
            
            if(curPos.first == goal.first && curPos.second == goal.second){
   
                 if(curArriveNum < move[robotNum].size() - 1){
                    curArriveNum++;
                    q.push({{robotNum, curArriveNum},{curPos}});         
                }
            }
            else{
                q.push({{robotNum, curArriveNum},{curPos}});
            }
        }
        
        for(auto it = curRobotMap.begin(); it != curRobotMap.end(); it++){
            if(it->second > 1){
                answer++;
            }
        }

    }
    
    
    return answer;
}