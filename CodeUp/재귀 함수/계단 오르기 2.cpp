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
