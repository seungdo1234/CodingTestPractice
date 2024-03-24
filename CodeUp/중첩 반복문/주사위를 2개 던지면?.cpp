#include <iostream>
// https://codeup.kr/problem.php?id=1081
using namespace std;

int main() {

	int n, m;
	// 주사위 면의 갯수 입력
	cin >> n >> m;
	// 모든 경우의 수 구하기
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cout << i << " " << j << endl;
		}
	}

	return 0;
}
