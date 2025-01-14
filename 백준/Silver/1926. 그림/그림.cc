#include <bits/stdc++.h>

using namespace std;

int n, m, pictureCount = 0 ,maxWidth = 0;
int arr[500][500] = {0 ,};
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
bool visited[500][500] = {false, };

void BFS(pair<int, int> startPoint)
{
	queue<pair<int, int>> q;
	q.push(startPoint);
	visited[startPoint.first][startPoint.second] = true;

	int count = 1;
	while (!q.empty())
	{
		pair<int, int> point = q.front();
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int moveY = point.first + dy[i];
			int moveX = point.second + dx[i];

			if(moveX < 0 || moveX >= m || moveY < 0 || moveY >= n)
				continue;;

			if(arr[moveY][moveX] == 1 && !visited[moveY][moveX])
			{
				q.push({moveY, moveX});
				visited[moveY][moveX] = true;
				count++;
			}
		}
	}
	
	pictureCount++;
	maxWidth = max(count, maxWidth);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			cin >> arr[i][j];

	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			if(arr[i][j] == 1 && !visited[i][j])
				BFS({i, j});

	cout << pictureCount << "\n" << maxWidth;
	return 0;
}
