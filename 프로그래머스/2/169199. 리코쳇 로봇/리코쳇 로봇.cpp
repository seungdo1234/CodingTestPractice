#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

int map[101][101];
bool visited[101][101];
int n,m;
pair<int,int> startPos;
pair<int, int> endPos;

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

void Init(vector<string> board){
    n = board.size();
    m = board[0].length();
    
     for(int i = 0; i < n; i ++){
        for(int j = 0; j < m; j++){     
            if(board[i][j] !='D')
            {
                  map[i][j] = 0;
                if(board[i][j] =='G'){
                    endPos = {i, j};
                }
                else if(board[i][j] =='R'){
                    startPos = {i, j};
                    visited[i][j] = true;
                }
            }
            else{
                map[i][j] = -1;
            }
        }
    }
}

bool cmp(int moveX, int moveY){
    return moveX < 0 || moveY < 0 || moveX >= m || moveY >= n || map[moveY][moveX] == -1;
}
int BFS(){
    queue<pair<int,int>> q;
    q.push(startPos);
    
    while (!q.empty()){
        int yPos = q.front().first;
        int xPos = q.front().second;
        int moveValue =map[yPos][xPos] + 1;
        
        q.pop();
        
        for(int i = 0; i < 4; i ++){
            int moveY = yPos + dy[i];
            int moveX = xPos + dx[i];
                 
            if(cmp(moveX, moveY))
                continue;
            
            while(true){
                moveY += dy[i];
                moveX += dx[i];
                
                if( cmp(moveX, moveY) ){
                    int stopY =  moveY - dy[i];
                    int stopX =   moveX - dx[i];
                    
                    if(map[stopY][stopX] == 0 ||  map[stopY][stopX] > moveValue){
                        q.push({stopY, stopX});
                        map[stopY][stopX] = moveValue;   
                    }
                     break;
                }
            }
        }
    }
    
    int goal = map[endPos.first][endPos.second];
    return goal == 0 ? -1 : goal;
}

int solution(vector<string> board) {
    Init(board);
    return BFS();
}