#include<iostream>
#include<queue>
// https://www.acmicpc.net/problem/1260 DFS와 BFS
using namespace std;

int map[1001][1001] = {0, }; // 맵
bool visited[1001] = {false, }; // 방문 한 노드 체크하는 배열

void DFS(int N,int V) { // DFS
	visited[V] = true; // 방문 표시
	cout << V << " ";
	for (int i = 1; i <= N; i++) {
		// 방문하지 않은 인접한 노드라면 해당 노드 호출
		if (visited[i] == false && map[V][i] == 1) {
			DFS(N,i);
		}
	}
}

void BFS(int N, int V) {
	queue<int> q; // 큐 생성

	visited[V] = true; // 방문 표시
	q.push(V); // 첫번째 노드 푸쉬
	cout << V << " ";

	while (!q.empty()) {
		int front = q.front(); // 맨 앞 노드 값 저장
		q.pop(); // 팝

		for (int i = 1; i <= N; i++) {
			// 방문하지 않은 인접한 노드라면 해당 노드 푸쉬 및 방문 표시
			if (visited[i] == false && map[front][i] == 1) { 
				q.push(i);
				visited[i] = true;
				cout << i << " ";
			}
		}
	}
}

void Reset(int N) { // 초기화
	cout << "\n";
	for (int i = 1; i <= N; i++) {
		visited[i] = false;
	}
}

int main() {
	int N, M, V, x, y; // 변수 선언

	cin >> N >> M >> V; // 입력

	for (int i = 0; i < M; i++) {  // 노드 입력 및 매핑
		cin >> x >> y;
		map[x][y] = map[y][x] = 1; 
	}

	DFS(N, V); // DFS
	Reset(N); // Visited 배열 초기화
	BFS(N, V); // BFS
}
