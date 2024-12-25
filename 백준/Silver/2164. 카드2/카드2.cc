#include <iostream>
#include <queue>

using namespace std;

queue<int> q;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	for(int i = 1;i <= n;i++)
	{
		q.push(i);
	}

	while(true)
	{
		if(q.size() == 1)
		{
			cout << q.front();
			break;
		}
		q.pop();
		int front = q.front();
		q.pop();
		q.push(front);
	}
	
	return 0;
}
