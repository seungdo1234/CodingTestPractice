#include<vector>
#include<queue>

using namespace std;

// 방향
int dx [4] = {1,-1,0,0};
int dy[4] = {0,0,-1,1};

// 방문 표시 배열 및 위치 별 이동거리
bool visited[100][100] = {false ,};
int result [100][100] = {0,};

int solution(vector<vector<int> > maps)
{
    // 상대 진영 x,y좌표를 변수에 저장
    int goal_X = maps.size(), goal_Y = maps[maps.size() - 1].size();
    
    queue<pair<int,int>> q; // 큐 생성
    
    q.push({0,0}); // 시작 지점 저장
    visited[0][0] =true;
    result[0][0] = 1; // 시작 지점 부터 출발이므로 +1

    while(!q.empty()){
        pair<int, int> pos = q.front();
        q.pop();
        
        for(int i =0; i< 4; i++){
            // 동서남북 이동
            int moveX = pos.first + dx[i];
            int moveY = pos.second + dy[i];
            
            // 맵을 벗어나면 continue
            if(moveX < 0 || moveX >= goal_X  || moveY >= goal_Y || moveY < 0 )  continue;
                        
            if(!visited[moveX][moveY] && maps[moveX][moveY] == 1){ // 길을 찾았다면 
                // 현재 위치까지 이동거리 + 1 => 찾은 위치까지 이동거리
                result[moveX][moveY] = result[pos.first][pos.second] + 1; 
                q.push({moveX, moveY}); // 해당 위치 큐에 저장
                visited[moveX][moveY] = true; // 방문 표시
            }
        }
    }

    
    if(result[goal_X-1][goal_Y-1] != 0){ // 목적지의 이동거리가 0아니면 도착
          return result[goal_X-1][goal_Y-1];
    }
    else{ // 이동거리가 0이라면 도착 X => -1 리턴
            return -1;
    }
    
}
