#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

#define INF 1e9

// https://www.acmicpc.net/problem/11724

using namespace std;

int N, M;
vector<int> vec[1001];

bool visited[1001] = { false, };

void BFS(int startPos) {
	queue <int>q;

	q.push(startPos);
	visited[startPos] = true;

	while (!q.empty()) {
		int target = q.front();
		q.pop();


		for (int i = 0; i < vec[target].size(); i++) {
			if (!visited[vec[target][i]]) {
				visited[vec[target][i]] = true;
				q.push(vec[target][i]);
			}
		}
	}
}

int main() {
	cin >> N >> M;

	int s1, s2;
	for (int i = 0; i < M; i++) {
		cin >> s1 >> s2;
		vec[s1].push_back( s2 );
		vec[s2].push_back( s1 );
	}

	int count = 0;
	for (int i = 1; i <= N; i++) {
		if (!visited[i]) {
			BFS(i);
			count++;
		}
	}

	cout << count;
	return 0;
}
