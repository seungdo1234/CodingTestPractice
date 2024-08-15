// 수정 후 코드
#include <iostream>
#include <vector>
#include <queue>

// https://www.acmicpc.net/problem/7576

using namespace std;

int m, n;

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

vector<vector<int>> map;
queue <pair<int, int>> q;

void BFS()
{
	while (!q.empty()) {
		pair<int,int > front = q.front();

		q.pop();

		for (int i = 0; i < 4; i++) {
			int moveY = front.first + dy[i];
			int moveX = front.second + dx[i];

			if (moveY < 0 || moveY >= n || moveX < 0 || moveX >= m)
				continue;

			if (map[moveY][moveX] == 0) {
				map[moveY][moveX] = map[front.first][front.second] + 1;
				q.push({ moveY,moveX });
			}
		}
	}
}
void StartSearch() {
	int result = 1;
	BFS();

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 0) {
				cout << "-1\n";
				return;
			}

			if (result < map[i][j]) {
				result = map[i][j];
			}
		}
	}
	
	cout << result - 1 << "\n";

}
int main() {
	vector<pair<int, int>> initVec;

	cin >> m >> n;

	for (int i = 0; i < n; i++) {
		int sel;
		vector<int> vec;
		for (int j = 0; j < m; j++) {
			cin >> sel;
			vec.push_back(sel);

			if (sel == 1)
			{
				q.push({ i,j });
			}
		}
		map.push_back(vec);
	}

	StartSearch();

	return 0;
}





------------------------------------------------------------------------------------------------------------------------------------------
// 수정 전 코드
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int m, n;

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

vector<vector<int>> map;
vector<vector<bool>> visited;

int BFS(vector<pair<int, int>> initVec)
{
	int count = 0;
	queue <vector<pair<int, int>>> q;

	q.push(initVec);

	while (!q.empty()) {
		vector<pair<int, int>> searchVec;
		vector<pair<int, int>> saveVec;

		searchVec = q.front();
		q.pop();

		for (int i = 0; i < searchVec.size(); i++) {
			for (int j = 0; j < 4; j++) {
				int moveX = searchVec[i].second + dx[j];
				int moveY = searchVec[i].first + dy[j];

				if (moveY < 0 || moveY >= n || moveX < 0 || moveX >= m)
					continue;

				if (!visited[moveY][moveX] && map[moveY][moveX] != -1) {
					visited[moveY][moveX] = true;
					map[moveY][moveX] = 1;
					saveVec.push_back({ moveY, moveX });
				}
			}
		}

		if (saveVec.size() > 0) {
			q.push(saveVec);
			count++;
		}


	}

	return count;
}
void StartSearch(vector<pair<int, int>> initVec) {
	int totalCount = 0;


	totalCount = BFS(initVec);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 0) {
				cout << "-1\n";
				return;
			}
		}
	}

	cout << totalCount << "\n";
}
int main() {
	vector<pair<int, int>> initVec;

	cin >> m >> n;

	for (int i = 0; i < n; i++) {
		int sel;
		vector<int> vec;
		vector<bool> visit;
		for (int j = 0; j < m; j++) {
			cin >> sel;
			vec.push_back(sel);

			if (sel == 1)
			{
				initVec.push_back({ i,j });
				visit.push_back(true);
			}
			else {
				visit.push_back(false);
			}
		}
		map.push_back(vec);
		visited.push_back(visit);
	}

	StartSearch(initVec);

	return 0;
}
