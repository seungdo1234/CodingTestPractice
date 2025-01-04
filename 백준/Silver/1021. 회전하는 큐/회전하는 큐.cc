#include <bits/stdc++.h>

using namespace std;


int GetMove(deque<int> q, int target ,int dir )
{
	int count = 0;
	while(q.front() != target)
	{
		if(dir > 0)
		{
			q.push_front(q.back());
			q.pop_back();
		}
		else
		{
			q.push_back(q.front());
			q.pop_front();
		}
		count += dir;
	}
	return count;
}

void MoveDeque(deque<int> &q, int value)
{
	int move = abs(value);
	int dir = value > 0 ? 1 : -1;
	
	for(int i = 0; i < move; i++)
	{
		if(dir > 0)
		{
			q.push_front(q.back());
			q.pop_back();
		}
		else
		{
			q.push_back(q.front());
			q.pop_front();
		}
	}

	q.pop_front();
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	deque<int> q;
	int n, m;

	cin >> n >> m;

	for(int i = 1; i <= n; i++)
	{
		q.push_back(i);
	}

	int count = 0;
	for(int i = 0; i < m; i++)
	{
		int input;
		cin >> input;

		int left = GetMove(q, input, -1); 
		int right = GetMove(q, input, 1); 
		int value = abs(left) < right ? left : right;
		
		count += abs(value);

		MoveDeque(q, value);
	}

	cout << count;
	return 0;
}