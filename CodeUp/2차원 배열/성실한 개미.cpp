#include <iostream>

// https://codeup.kr/problem.php?id=1099&rid=0
using namespace std;

int main() {
	int map[11][11], x = 2, y = 2;

	// 맵 입력
	for (int i = 1; i < 11; i++) {
		for (int j= 1; j < 11;j++) {
			cin >> map[i][j];
		}
	}
	
	// 개미 이동
	while (true) {
		// 먹이를 찾았거나 더 이상 움직일 수 없을 때
		if (map[x][y] == 2 || (x == 9 && y == 9)) {
			map[x][y] = 9;
			break;
		}
		map[x][y] = 9;

		// 오른쪽이 막혀있다면 아래로
		if (map[x][y + 1] == 1) {
			x++;
		}
		else { // 오른쪽으로
			y++;
		}
	}

	// 출력
	for (int i = 1; i < 11; i++) {
		for (int j = 1; j < 11; j++) {
			cout << map[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}
