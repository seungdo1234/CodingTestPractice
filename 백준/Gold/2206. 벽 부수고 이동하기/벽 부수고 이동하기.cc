#include <bits/stdc++.h>

using namespace std;

int arr[1000][1000][2];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int n, m;

int BFS()
{
	queue<pair<pair<int, int>, int>> q;
	q.push({{0, 0}, 0});
	arr[0][0][0] = arr[0][0][1] = 1;
	
	while(!q.empty())
	{
		int  curX = q.front().first.second;
		int  curY = q.front().first.first;
		bool broken = q.front().second;
		if(curY == n- 1 && curX == m -1)
			return arr[curY][curX][broken];
		q.pop();

		for(int i = 0; i < 4; i++)
		{
			int moveX = curX + dx[i];
			int moveY = curY + dy[i];
			if(moveX < 0 || moveX >= m || moveY < 0 || moveY >= n) continue;
			
			if(!broken && arr[moveY][moveX][broken] == -1) // 벽을 부술 때
			{
				arr[moveY][moveX][!broken] = arr[curY][curX][broken] + 1;
				q.push({{moveY, moveX}, !broken});
				continue;
			}

			// 부수지 않고 갈 때
			if(arr[moveY][moveX][broken] == 0 || arr[curY][curX][broken] + 1 < arr[moveY][moveX][broken]) 
			{
				arr[moveY][moveX][broken] = arr[curY][curX][broken] + 1;
				q.push({{moveY, moveX}, broken});
			}
		}
	}
	
	return -1;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			char input;
			cin >> input;
			arr[i][j][0] = input - '0';
			if(arr[i][j][0] == 1)
				arr[i][j][0] = arr[i][j][1] = -1;
		}
	}

	cout << BFS();

	return 0;
}
