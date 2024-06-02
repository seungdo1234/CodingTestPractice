#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
// https://www.acmicpc.net/problem/2667
using namespace std;

int n;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

void BFS(vector<string> map, vector<vector<bool>> visited)
{
    vector<int> answer;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!visited[i][j] && map[i][j] == '1') { 
                int count = 1;
                queue<pair<int,int>> q;
                q.push({ i,j });
                visited[i][j] = true;

                while (!q.empty()) {  // bfs
                    pair<int,int> p = q.front();
                    q.pop();

                    for (int k = 0; k < 4; k++) {
                        int x_Pos = p.first + dx[k];
                        int y_Pos = p.second + dy[k];

                        if (x_Pos >= 0 && x_Pos <= n -1 && y_Pos >= 0 && y_Pos <= n - 1 
                            && map[x_Pos][y_Pos] == '1' && !visited[x_Pos][y_Pos]) {
                            visited[x_Pos][y_Pos] = true;
                            q.push({ x_Pos, y_Pos });
                            count++;
                        }
                    }
                }
                answer.push_back(count);
            }
        }
    }

    // 결과 출력
    cout << answer.size() << endl;
    sort(answer.begin(), answer.end());
    for (int i = 0; i < answer.size(); i++) {
        cout << answer[i] << endl;
    }
}
int main() {
    int x;

    cin >> n;

    // n 만큼 벡터 크기 정의
    vector<string> map(n);
    vector<vector<bool>> visited(n , vector<bool>(n,false));

    string str;
    for (int i = 0; i < n; i++) {
        cin >> str;
        map[i] = str;
    }

    BFS(map, visited);

    return 0;
}
