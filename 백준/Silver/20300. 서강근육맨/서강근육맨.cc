#include <bits/stdc++.h>
using namespace std;

bool cmp(long long a, long long b)
{
	return a > b;
}

long long GetStrength(vector<long long > v)
{
	long long left = 0, right = v.size() - 1, maxValue =  0;
	while (left < right)
	{
		maxValue = max(maxValue, v[left]+ v[right]); 
		left++;
		right--;
	}

	return maxValue;
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	vector<long long > vec (n);
	for(int i = 0; i < n; i++)
		cin >> vec[i];

	sort(vec.begin(), vec.end(), cmp);

	if(n % 2 == 1)
	{
		long long  front =  vec[0];
		vec.erase(vec.begin());
		long long  maxValue =  max(GetStrength(vec), front);
		cout << maxValue;
	}
	else
	{
		cout << GetStrength(vec);
	}
	return 0;
}