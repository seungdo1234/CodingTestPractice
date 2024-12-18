
#include <bits/stdc++.h>
using namespace std;

#define ll long long

stack<int> s;
int n;
long long ans;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	int h;
	for(int i = 0; i < n; i++)
	{
		cin >> h;
		while(!s.empty() && s.top() <= h)
		{
			s.pop();
		}
		ans += s.size();
		s.push(h);
	}
	cout << ans;
	return 0;
}