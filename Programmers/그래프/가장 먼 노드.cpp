#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;

    // 그래프
    vector<vector<int>> graph(n + 1);
    // 방문 노드 체크
    vector<bool> visited(n + 1, false);
    // 각 노드들의 1번 노드와의 거리
    vector<int> count(n + 1, 0);
    // bfs 큐
    queue<int> queue;


    // 인접 리스트 그래프 생성 
    for (int i = 0; i < edge.size(); i++) {
        graph[edge[i][0]].push_back(edge[i][1]);
        graph[edge[i][1]].push_back(edge[i][0]);
    }


    // 1번에서 시작하기 때문에 1번 방문
    visited[1] = true;
    queue.push(1);

    // bfs
    while (!queue.empty())
    {
        int node = queue.front();
        queue.pop();

        for (int i = 0; i < graph[node].size(); i++) {
            if (!visited[graph[node][i]]) {
                // 1번 노드와의 거리 구함
                int distance = count[node] + 1;
                count[graph[node][i]] = distance;
                // 해당 노드 방문 표시
                visited[graph[node][i]] = true;
                // Push
                queue.push(graph[node][i]);
            }
        }
    }

    // 내림차순 정렬
    sort(count.rbegin(), count.rend());
    
    int max = count[0];
    
    // 가장 먼 노드 갯수 구하기
    for (int i = 0; i < count.size(); i++) {
       if(count[i] == max){ 
           answer++;
       }
        else{
            break;
        }
    }

    return answer;
}
