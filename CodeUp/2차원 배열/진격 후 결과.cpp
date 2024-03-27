#include <iostream>
// https://codeup.kr/problem.php?id=1509&rid=0
using namespace std;

int map[12][11] = { 0, };

int main() {
	
	for (int i = 1; i <= 11; i++) { // 맵 입력
		for (int j = 1; j <= 10; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 1; i <= 10; i++) { // 경주 시작
		if (map[11][i] == 1) {
			for (int j = 10; j > 0; j--) {
				if (map[j][i] > 0) { // 장애물에 부딪힘
					cout << i << " " << "crash" << endl;
					break;
				}
				else if  (map[j][i] < 0) { // 장애물에 빠짐
					cout << i << " " << "fall" << endl;
					break;
				}

				if (j == 1) { // 무사 통과
					cout << i << " " << "safe" << endl;
				}
			}
		}
	}

	return 0;
}
