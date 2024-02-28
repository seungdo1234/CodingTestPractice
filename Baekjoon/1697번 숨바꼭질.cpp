#include<iostream>
#include<queue>

// https://www.acmicpc.net/problem/1697 1697번 숨바꼭질
using namespace std;

bool visited[100001] = { false , };
int result[100001] = { 0 , }; // 횟수를 저장하는 배열
int N, K;


void BFS() {
	queue<int> Q;

	Q.push(N); // 시작 지점 푸쉬
	visited[N] = true;

	while (!Q.empty()) {
		int front = Q.front();
		Q.pop();

		if (front == K) { // 현재 위치가 동생의 위치일 때 break
			cout << result[K] << endl;
			break;
		}

		if (front - 1 >= 0 && !visited[front - 1]) { // 뒤로가기
			result[front - 1] = result[front] + 1; // 해당 위치까지의 이동 횟수 저장
			visited[front - 1] = true; // 방문 표시
			Q.push(front - 1); // 이동 위치 큐에 저장
		}

		if (front + 1 <= 100000 && !visited[front + 1]) { // 앞으로 가기
			result[front + 1] = result[front] + 1; // 해당 위치까지의 이동 횟수 저장
			visited[front + 1] = true;  // 방문 표시
			Q.push(front + 1);  // 이동 위치 큐에 저장
		}

		if (front * 2 <= 100000 && !visited[front * 2]) { // 순간 이동
			result[front * 2] = result[front] + 1; // 해당 위치까지의 이동 횟수 저장
			visited[front * 2] = true;  // 방문 표시
			Q.push(front * 2);  // 이동 위치 큐에 저장
		}
	}
}
int main() {
	cin >> N >> K;

	BFS();

	return 0;
}
