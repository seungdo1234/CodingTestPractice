#include <iostream>
using namespace std;
// https://codeup.kr/problem.php?id=1901&rid=0
int n;

void PrintFunc(int nowNum) { // 재귀 함수
    if (nowNum > n) {
        return;
    }
    cout << nowNum << endl;
    PrintFunc(nowNum + 1);
}
int main() {
    
    cin >> n;
    
    PrintFunc(1);

    return 0;
}
