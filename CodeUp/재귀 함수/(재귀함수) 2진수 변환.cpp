#include <iostream>
#include <string>
// https://codeup.kr/problem.php?id=1920&rid=0
using namespace std;

string binaryNumber(int num) {
    if (num == 0) { 
        return "0";
    }
    else if (num == 1) {
        return "1";
    }
    else {
        return binaryNumber(num / 2) + to_string(num % 2);
    }
}

int main() {
    int num;
    cin >> num;
    cout << binaryNumber(num) << endl;
    return 0;
}
