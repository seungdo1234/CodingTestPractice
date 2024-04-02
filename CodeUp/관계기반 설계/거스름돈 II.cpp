#include <iostream>
#include <vector>
// https://codeup.kr/problem.php?id=2634&rid=0
using namespace std;

int main() {
    int change, n;
    cin >> change >> n; // 거스름돈 액수, 종류의 갯수 입력

    vector<int> changeTypes(n); // 거스름돈 종류
    for (int i = 0; i < n; ++i) { // 거스름돈 종류 입력 
        cin >> changeTypes[i];
    }

    // 거스름돈의 갯수를 저장하는 벡터
    vector<int> dp(change + 1, 10001); // 동전의 최댓값이 10000원이기 때문에 10001개로 초기화
    dp[0] = 0; // 거스름돈이 딱 맞아 떨어졌을 때 == 0

    for (int i = 1; i <= change; ++i) { // 금액 별 거스름돈 갯수 저장
        for (int j = 0; j < n; ++j) {
            if (i - changeTypes[j] >= 0) { // 거슬러 줄 수 있을 때
                dp[i] = min(dp[i], dp[i - changeTypes[j]] + 1);  // 금액 별 최소 갯수 저장
            }
        }
    }

    cout << dp[change] << endl; // 입력 금액의 거스름돈 갯수 출력

    return 0;
}
