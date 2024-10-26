#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dp[17] = { 0, };

int main() {
    int n;
    cin >> n;

    vector<int> t(n + 1);
    vector<int> v(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> t[i] >> v[i];
    }

    for (int i = n; i >= 1; i--) {
        int next = t[i] + i;
        if (next <= n + 1) {
            dp[i] = max(dp[i + 1], dp[next] + v[i]);
        }
        else {
            dp[i] = dp[i + 1];
        }
    }

    cout << dp[1];
    return 0;
}