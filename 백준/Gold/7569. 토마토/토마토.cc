#include <bits/stdc++.h>

using namespace std;

int dx[6] = {0, 0, 1, -1,0,0 };
int dz[6] = {1, -1, 0, 0,0,0};
int dy[6] = {0, 0 , 0 , 0 , 1, -1};
int n, m, h;
int arr[100][100][100];
queue<pair<pair<int,int>, int>> q;

void BFS()
{
	int count = 0;
	while (!q.empty())
	{

		int size = q.size();
		for(int k = 0; k < size; k++)
		{
			int x = q.front().first.second, z = q.front().first.first,  y = q.front().second;
			q.pop();

			for(int i = 0; i < 6; i++)
			{
				int moveX = x + dx[i], moveZ = z + dz[i], moveY = y + dy[i];
				if(moveX < 0 || moveX >= m || moveZ < 0 || moveZ >= n || moveY < 0 || moveY >= h) continue;

				if(arr[moveZ][moveX][moveY] == 0)
				{
					arr[moveZ][moveX][moveY] = 1;
					q.push({{moveZ, moveX}, moveY});
				}
			}
		}

		
		count ++;
	}

	for(int k = 0; k < h; k++)
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
			{
				if(arr[i][j][k] == 0)
				{
					cout << -1;
					return;
				}
			}

	cout << count - 1;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> m >> n >> h;

	for(int k = 0; k < h; k++)
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
			{
				cin >> arr[i][j][k];

				if(arr[i][j][k] == 1)
					q.push({{i, j}, k});
			}

	BFS();
		
	return 0;
}
