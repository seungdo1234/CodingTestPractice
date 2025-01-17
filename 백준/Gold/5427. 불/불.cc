#include <bits/stdc++.h>

using namespace std;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int n, h, w;

vector<vector<int>> BFS(vector<vector<int>> map, queue<pair<int, int>> q)
{
	while(!q.empty())
	{
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		for(int i = 0; i < 4; i++)
		{
			int moveX = x + dx[i];
			int moveY = y + dy[i];

			if(moveX < 0 || moveX >= w || moveY < 0 || moveY >= h) continue;

			if(map[moveY][moveX] == 0 || map[y][x] + 1 < map[moveY][moveX])
			{
				map[moveY][moveX] = map[y][x] + 1;

				q.push({moveY, moveX});
			}
		}
	}

	return map;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for(int i = 0; i < n; i++)
	{
		cin >> w >> h;
		vector<vector<int>>    map(h, vector<int>(w));
		queue<pair<int, int>>  fireQ;
		queue<pair<int, int>>  playerQ;
		vector<pair<int, int>> exit;
		for(int j = 0; j < h; j++)
		{
			for(int k = 0; k < w; k++)
			{
				char c;
				cin >> c;
				if(c == '.')
				{
					map[j][k] = 0;
					if(j == 0 || j == h - 1 || k == 0 || k == w - 1)
					{
						exit.push_back({j, k});
					}
				}
				else if(c == '#') map[j][k] = -2;
				else if(c == '@')
				{
					if(!(j == 0 || j == h - 1 || k == 0 || k == w - 1))
						playerQ.push({j, k});
				}
				else
				{
					fireQ.push({j, k});
					map[j][k] = - 1;
				}
			}
		}

		if(playerQ.empty())
		{
			cout << 1 <<"\n";
			continue;
		}
		vector<vector<int>> playerMap = BFS(map, playerQ);
		vector<vector<int>> fireMap = BFS(map, fireQ);
		// cout << endl;
		// for(int j = 0; j < h; j++)
		// {
		// 	for(int k = 0; k < w; k++)
		// 	{
		// 		cout << playerMap[j][k] << " ";
		// 	}
		// 	cout << endl;
		// }
		// cout << endl;
		//
		// cout << endl;
		// for(int j = 0; j < h; j++)
		// {
		// 	for(int k = 0; k < w; k++)
		// 	{
		// 		cout << fireMap[j][k] << " ";
		// 	}
		// 	cout << endl;
		// }
		// cout << endl;
		// cout << endl;
		
		int minCount = 987654321;
		for(int j = 0; j < exit.size(); j++)
		{
			int y = exit[j].first;
			int x = exit[j].second;
			if(playerMap[y][x] > 0 && (playerMap[y][x] < fireMap[y][x] + 1 || fireMap[y][x] == 0) )
			{
				minCount = min(minCount, playerMap[y][x]);
			}
		}

		if(minCount == 987654321)
			cout << "IMPOSSIBLE\n";
		else
			cout << minCount + 1<< "\n";
	}
	return 0;
}
