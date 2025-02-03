#include <bits/stdc++.h>

using namespace std;

long long a, b, c;

long long Solve(long long a, long long b, long long c)
{
	if(b == 0) return 1;

	long long num = Solve(a, b / 2, c);
	num = num * num % c;
	
	if(b % 2 == 0) return num;
	return num * a % c;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> a >> b >> c;

	cout << Solve(a,b,c);
	return 0;
}
