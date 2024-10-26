#include <iostream>
#include <vector>

using namespace std;

int dp[1001] = { 0, };
int main() {
	int n;
	cin >> n;

	vector<int> vec(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> vec[i];
		dp[i] = 1;
	}

	int maxCount = 1;
	for (int i = 2; i <= n; i++) {
		
		for (int j = i - 1; j >= 1; j--) {
			if (vec[j] < vec[i]) {
				dp[i] = max(dp[j] + 1, dp[i]);
			}
		}

		maxCount = max(dp[i], maxCount);
	}

	cout << maxCount;

	return 0;
}