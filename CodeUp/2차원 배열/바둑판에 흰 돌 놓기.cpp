#include <iostream>
using namespace std;
//https://codeup.kr/problem.php?id=1096&rid=0

int main() {
    int map[20][20] = { 0, }; // 바둑판 배열 0으로 초기화
    int n,x ,y;

    cin >> n;
    
    for (int i = 0; i < n; i++) { // 흰 돌 좌표 입력 및 배치
        cin >> x >> y;
        map[x][y] = 1;
    }
   
    for (int i = 1; i < 20; i++) { // 출력
        for (int j = 1; j < 20; j++) {
            cout << map[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
