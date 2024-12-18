#include <bits/stdc++.h>
using namespace std;


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int h, n;
	cin >> n;
	stack<int> stack;
	long long sum;
	for(int i = 0; i < n; i++)
	{
		cin >> h;
		while(!stack.empty() && stack.top() <= h)
		{
			stack.pop();
		}
		sum += stack.size();
		stack.push(h);
	}
	cout << sum;
	return 0;
}