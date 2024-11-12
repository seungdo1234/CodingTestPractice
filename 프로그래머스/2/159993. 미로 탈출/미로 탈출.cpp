#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

int map[101][101];
int copyMap[101][101];

int dx[4] = {1 ,-1, 0,0};
int dy[4] = {0,0,1,-1};

int n, m;
pair<int, int> leverPair;
pair<int, int> exitPair;
pair<int, int> startPair;

void ResetMap(){
for(int i = 0; i <n; i++){
        for(int j = 0;j < m; j++){
            copyMap[i][j] = map[i][j];
            
        }}
}
int BFS(pair<int,int> startPos, pair<int,int> endPos){
    
    ResetMap();
    
    queue<pair<int,int>> q;
    
    q.push(startPos);
    
    while(!q.empty()){
        int yPos = q.front().first;
        int xPos = q.front().second;
      //  cout <<  "\n현재 좌표 "<<yPos << " | " << xPos<<endl;
        q.pop();
        
        for(int i =0 ; i < 4; i++){
            int moveY = yPos + dy[i];
            int moveX = xPos + dx[i];
            
            if(moveX < 0 || moveY < 0 || moveX >= m || moveY >= n)
                continue;
            
          //  cout << moveY <<  " + " << dy[i]<< " | " << moveX << " + " << dx[i] << " => " << copyMap[moveY][moveX]<<endl;
            if(copyMap[moveY][moveX] == 0){
                copyMap[moveY][moveX] = copyMap[yPos][xPos] + 1;
                if(moveY == endPos.first && moveX == endPos.second){
                    return copyMap[moveY][moveX];
                }
                q.push({moveY, moveX});
            }
        }
    }
    
    return -1;
}
int solution(vector<string> maps) {
    int answer = 0;
    n = maps.size(), m = maps[0].size();
    
    for(int i = 0; i <n; i++){
        for(int j = 0;j < m; j++){
            if(maps[i][j] == 'X')
                map[i][j] = -1;
            else{
                if(maps[i][j] == 'S')
                    startPair = {i,j};
                else if (maps[i][j] == 'L')
                    leverPair = {i,j};
                else if(maps[i][j] == 'E')
                    exitPair = {i,j};
                
                map[i][j] = 0;
            }
        }
    }
    
    int leverTime = BFS(startPair, leverPair);
    if(leverTime == -1)
        return -1;
    
     int exitTime = BFS(leverPair, exitPair);
    if(exitTime == -1)
        return -1;

    return leverTime + exitTime ;
}