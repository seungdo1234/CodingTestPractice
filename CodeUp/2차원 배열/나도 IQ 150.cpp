#include <iostream>
// https://codeup.kr/problem.php?id=1508
using namespace std;

int map[20][20] = { 0, };

int main() {
    int n;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> map[i][0]; // 입력
        for (int j = 0; j < i; j++) { // 계산
            map[i][j + 1] = map[i][j] - map[i - 1][j] ;
        }
    }

    for (int i = 0; i < n; i++) { // 출력
        for (int j = 0; j <= i; j++) {
            cout << map[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
