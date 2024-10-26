#include <iostream>
#include <vector>

using namespace std;

int dp[301] = { 0, };
int main() {
	int n;
	cin >> n;

	vector<int> vec(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> vec[i];
	}
	
	dp[1] = vec[1];
	dp[2] = dp[1] + vec[2];
	dp[3] = max(vec[1] + vec[3], vec[2] + vec[3]);

	for (int i = 4; i <= n; i++) {
		dp[i] = vec[i] + max(dp[i - 2], dp[i - 3] + vec[i - 1]);
	}

	cout << dp[n];

	return 0;
}