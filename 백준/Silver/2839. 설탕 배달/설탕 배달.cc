#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int dp[5001] = { 0, };
int main() {
    int n;

    cin >> n;

    dp[3] = dp[5] = 1;

    for (int i = 6; i <= n; i++) {
        if (dp[i - 3] != 0) {
            dp[i] = dp[i - 3] + 1;
        }

        if (dp[i - 5] != 0) {
            if (dp[i] == 0) {
                dp[i] = dp[i - 5] + 1;
            }
            else {
                dp[i] = min(dp[i], dp[i - 5] + 1);
            }
        }
    }

    cout << (dp[n] == 0 ? -1 : dp[n]);
    return 0;
}