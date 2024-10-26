#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int dp[1000001] = { 0, };
int main() {
    int n;

    cin >> n;

    for (int i = n; i >= 1; i--) {
        if (dp[i - 1] == 0) {
            dp[i - 1] = dp[i] + 1;
        }
        else {
            dp[i - 1] = min(dp[i - 1], dp[i] + 1);
        }

        if (i % 2 == 0) {
            if (dp[i / 2] != 0) {
                dp[i / 2] = min(dp[i / 2], dp[i] + 1);
            }
            else
            {
                dp[i / 2] = dp[i] + 1;
            }
        }

        if (i % 3 == 0) {
            if (dp[i / 3] != 0) {
                dp[i / 3] = min(dp[i / 3], dp[i] + 1);
            }
            else
            {
                dp[i / 3] = dp[i] + 1;
            }
        }
    }

    cout << dp[1];

    return 0;
}