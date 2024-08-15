#include <iostream>
#include <vector>
#include <queue>

// https://www.acmicpc.net/problem/1012

using namespace std;

int m, n, k;

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

void BFS(int map [50][50], bool visited [50][50], vector <pair<int, int>> vec) {

	int count = 0;

	for (int i = 0; i < vec.size(); i++) {
		if (!visited[vec[i].first][vec[i].second]) {
			queue <pair<int, int>> q;
			q.push({ vec[i].first ,vec[i].second });
			visited[vec[i].first][vec[i].second] = true;

			while (!q.empty())
			{
				pair<int, int> front = q.front();
				q.pop();

				for (int j = 0; j < 4; j++) {
					int moveX = front.first + dx[j];
					int moveY = front.second + dy[j];

					if (moveX < 0 || moveX >= m || moveY < 0 || moveY >= n)
						continue;

					if ( !visited[moveX][moveY] && map[moveX][moveY] == 1) {
						q.push({ moveX, moveY });
						visited[moveX][moveY] = true;
					}
				}
			}
			count++;
		}
	}
	cout << count << "\n";

}
int main() {
	
	int t;

	cin >> t;

	for (int i = 0; i < t; i++) {
		int x, y;
		int map[50][50] = { 0, };
		vector <pair<int, int>> vec;
		bool visited[50][50] = { false, };

		cin >> m >> n >> k;

		for (int j = 0; j < k; j++) {
			cin >> x >> y;

			map[x][y] = 1;
			vec.push_back({ x,y });
		}
		BFS(map, visited, vec);
	}

	return 0;
}
