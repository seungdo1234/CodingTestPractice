#include<iostream>
#include<queue>
#include<utility>
#include<string>
using namespace std;

// https://iingang.github.io/posts/BOJ-2178/ 2178번 미로탐색
// DFS로 풀이하다 문제가 안풀려 해당 블로그 풀이를 참조해 BFS로 풀이했습니다.
bool visited[100][100] = { false , }; // 방문 표시 배열
string map[100] = { "\0" }; // 맵
int result[100][100] = {0,}; // 지난 칸 수
int N, M;

// 방향 동서남북
int dx[4] = { 1, -1, 0, 0 }; 
int dy[4] = { 0, 0, -1, 1 };

void BFS(int x, int y) {
	queue<pair<int, int>> Q; // 좌표 값을 넣어야 하기 때문에 Pair<int, int> 큐 선언
	
	Q.push({ x,y }); // 시작 좌표 푸쉬
	visited[x][y] = true;
	result[x][y] = 1; // (1,1) 에서 출발하니깐 지난 칸 수 ++

	while (!Q.empty())
	{
		pair<int, int> front = Q.front(); // Pair형 Struct를 선언 후 front에 있는 값 저장
		Q.pop();

		for (int i = 0; i < 4; i++) { // 동서남북으로 이동
			int moveX = front.first + dx[i];
			int moveY = front.second + dy[i];

			// 미로를 넘어가지 않게 조건을 검
			if (moveX < 0 || moveY < 0 || moveX >= N || moveY >= M) continue;

			if (!visited[moveX][moveY] && map[moveX][moveY] == '1') { // 한번도 가지않은 길을 찾았다면
				Q.push({ moveX, moveY }); // 다음 칸 좌표 큐에 저장
				result[moveX][moveY] = result[front.first][front.second] + 1; // 지금까지 지나온 칸 수 + 1한 후 저장
				visited[moveX][moveY] = true; // 방문표시
			}
		}
	}
	cout << result[N - 1][M - 1] << endl; // 목적지에 저장된 지나온 칸 수 출력
}

int main() {
	string str;
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		cin >> str;
		map[i] = str;
	}

	BFS(0, 0);

	return 0;
}
