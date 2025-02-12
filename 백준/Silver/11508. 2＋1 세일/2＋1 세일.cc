#include <bits/stdc++.h>

using namespace std;

bool cmp (int a, int b)
{
	return a > b;
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	vector<int> v(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}

	sort(v.begin(), v.end(), cmp);
	int count = 0, sum = 0;
	for(int i = 0; i < n; i++)
	{
		if(count < 2)
		{
			sum += v[i];
			count++;
		}
		else
		{
			count = 0;
		}
	}

	cout << sum;
	return 0;
}
