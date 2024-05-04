#include <iostream>
// https://codeup.kr/problem.php?id=2650
using namespace std;

// 유클리드 호제법
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
    int key1, key2, key3;

    // 3개의 내부 보안키 값을 입력 받는다.
    cin >> key1 >> key2 >> key3;

    // 첫 번째와 두 번째 수의 최대공약수를 구한다.
    int gcd1 = gcd(key1, key2);

    // 위에서 구한 최대공약수와 세 번째 수의 최대공약수를 구한다.
    int masterKey = gcd(gcd1, key3);

    // 계산된 값(최대공약수)을 출력한다.
    cout << masterKey << endl;

    return 0;
}
