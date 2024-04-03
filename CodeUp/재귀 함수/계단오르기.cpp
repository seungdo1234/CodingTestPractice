// 반복문으로 풀이
#include <iostream>
#include <cmath>
// https://codeup.kr/problem.php?id=4564
using namespace std;

int dp[301] = { 0, };
int stairs[301] = { 0, };
int n;

int main() {

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> stairs[i];
    }
    
    dp[0] = stairs[0];
    dp[1] = stairs[0] + stairs[1];
    dp[2] = max(stairs[0] + stairs[2], stairs[1] + stairs[2]);

    for (int i = 3; i < n; i++) {
	// 한번에 2칸 올라갔을 때, 연속적으로 2칸 올라갔을 때 중 최댓 값 dp 테이블에 저장
        dp[i] = max(stairs[i] + dp[i - 2], stairs[i] + stairs[i - 1] + dp[i - 3]);
    }

    cout << dp[n - 1] << endl;

    return 0;
}


-----------------------------------------------------------------------------------------------------------
// 재귀함수로 풀이
#include <iostream>
#include <cmath>

using namespace std;

int dp[301] = { 0, };
int stairs[301] = { 0, };
int n;

int MaxScore(int idx) {
    // 0번 ~ 2번 계단의 최대 점수
    if (idx == 0) return stairs[0];
    if (idx == 1) return stairs[0] + stairs[1];
    if (idx == 2) return max(stairs[0] + stairs[2], stairs[1] + stairs[2]);

    // 이미 구한 dp 테이블 값일 때 중복 계산을 방지
    if (dp[idx] != 0) return dp[idx];

    // 한번에 2칸 올라갔을 때, 연속적으로 2칸 올라갔을 때 중 최댓 값 dp 테이블에 저장
    dp[idx] = max(stairs[idx] + MaxScore(idx - 2), stairs[idx] + stairs[idx - 1] + MaxScore(idx - 3));
    return dp[idx];
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> stairs[i];
    }

    cout << MaxScore(n - 1) << endl;

    return 0;
}
