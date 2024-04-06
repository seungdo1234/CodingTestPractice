// 재귀 함수
#include <iostream>
#include <vector>
// https://codeup.kr/problem.php?id=3704&rid=0
using namespace std;

const int MOD = 1000;

int countWays(int n, vector<int>& memo) {
    // 0 계단에 도달한 경우 1을 반환
    if (n == 0) return 1;
    // 음수인 경우 경우의 수가 없으므로 0을 반환
    if (n < 0) return 0;

    // 이미 계산한 값이 있는 경우 해당 값을 반환
    if (memo[n] != -1) return memo[n];

    // 1계단, 2계단, 3계단을 오르는 경우의 수를 재귀적으로 더함
    memo[n] = (countWays(n - 1, memo) + countWays(n - 2, memo) + countWays(n - 3, memo)) % MOD;

    return memo[n];
}

int main() {
    int n;
    cin >> n;

    // memo 배열 초기화
    vector<int> memo(n + 1, -1);

    cout << countWays(n, memo) << endl;

    return 0;
}
//-----------------------------------------------------------------------------------
// 반복문
#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1000; // 결과를 1000으로 나눈 나머지를 저장하기 위한 상수

int countWays(int n) {
    // dp[i]는 i개의 계단을 오를 때 가능한 경우의 수를 저장하는 배열
    vector<int> dp(n + 1, 0);
    
    // 초기값 설정
    dp[0] = 1; // 0계단을 오르는 경우는 한 가지 방법이 있다.
    dp[1] = 1; // 1계단을 오르는 경우도 한 가지 방법이 있다.
    dp[2] = 2; // 2계단을 오르는 경우는 두 가지 방법이 있다. (1계단씩 오르거나, 2계단을 한 번에 오르거나)

    // 점화식을 이용하여 dp 배열 완성
    for (int i = 3; i <= n; ++i) {
        dp[i] = (dp[i - 1] + dp[i - 2] + dp[i - 3]) % MOD;
    }

    return dp[n];
}

int main() {
    int n;
    cin >> n;

    cout << countWays(n) << endl;

    return 0;
}

