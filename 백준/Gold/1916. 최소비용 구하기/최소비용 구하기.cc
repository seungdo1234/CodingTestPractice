#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

// https://www.acmicpc.net/problem/1916

#define INF 1e9

using namespace std;

int N, M, startPos, endPos;
vector <pair<int, int>> vec[1001];

void Dijk() {
	vector<int> dist(N + 1, INF);
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

	dist[startPos] = 0;
	pq.push({ 0, startPos });

	while (!pq.empty()) {
		int curWei = pq.top().first;
		int curPos = pq.top().second;

		pq.pop();

		if (dist[curPos] < curWei)
			continue;

		for (int i = 0; i < vec[curPos].size(); i++) {
			int wei = vec[curPos][i].second + curWei;
			int nextPos = vec[curPos][i].first;

			if (dist[nextPos] > wei) {
				dist[nextPos] = wei;
				pq.push({ wei , nextPos });
			}
		}
	}

	cout << dist[endPos] << endl;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		int s1, s2, s3;
		cin >> s1 >> s2 >> s3;

		vec[s1].push_back({ s2 , s3 });
	}

	cin >> startPos >> endPos;

	Dijk();

	return 0;
}
