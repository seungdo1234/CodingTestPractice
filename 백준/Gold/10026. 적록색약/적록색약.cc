#include <bits/stdc++.h>

using namespace std;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int n ;

void BFS(pair<int, int> startPoint,vector<vector<int>> &arr,bool visited[101][101])
{
	queue<pair<int, int> > q;
	q.push(startPoint);
	visited[startPoint.first][startPoint.second] = true;

	int target = arr[startPoint.first][startPoint.second], count = 1;
	while(!q.empty())
	{
		pair<int, int> p = q.front();
		q.pop();

		for(int i = 0; i < 4; i++)
		{
			int moveY = p.first + dy[i];
			int moveX = p.second + dx[i];

			if(moveY < 0 || moveX < 0 || moveY >= n || moveX >= n)
				continue;

			if(!visited[moveY][moveX] && arr[moveY][moveX] == target)
			{
				q.push({moveY, moveX});
				visited[moveY][moveX] = true;
			}
		}
	}
}

void Search(vector<vector<int>> &arr)
{
	bool visited[101][101] = {false, };

	int count = 0 ;
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			if(!visited[i][j])
			{
				BFS({i,j}, arr,visited);
				count++;
			}
		}
	}
	cout << count << " ";
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	vector<vector<int> > arr01(n, vector<int>(n));
	vector<vector<int> > arr02(n, vector<int>(n));
	for(int i = 0; i < n; i++)
	{
		string input;
		cin >> input;
		for(int j = 0; j < input.length(); j++)
		{
			if(input[j] == 'R')
			{
				arr01[i][j] = arr02[i][j] = 1;
			}
			else if(input[j] == 'G')
			{
				arr02[i][j] = 1;
				arr01[i][j] = 2;
			}
			else
			{
				arr01[i][j] = arr02[i][j] = 3;
			}
		}
	}

	Search(arr01);
	Search(arr02);
	return 0;
}
