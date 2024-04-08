#include <iostream>
// https://codeup.kr/problem.php?id=1912&rid=0
using namespace std;

int Func(int n) {
    if (n == 1) {
        return 1;
    }
    return Func(n - 1) * n;
}
int main() {
    int n;

    cin >> n;

    cout << Func(n);

    return 0;
}
