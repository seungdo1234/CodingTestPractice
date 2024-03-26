#include <iostream>
// https://codeup.kr/problem.php?id=1524
using namespace std;

int map[10][10] = { 0, }; // 맵

// 8 방향을 나타내는 배열 => x방향, y방향
int dx[8] = { 1,1,1,-1,-1,-1,0,0 };
int dy[8] = { -1,1,0,-1,1,0,1,-1 };

int main() {
	int x, y;
	// 맵 입력
	for (int i = 1; i < 10; i++) {
		for (int j = 1; j < 10; j++) {
			cin >> map[i][j];
		}
	}

	cin >> x >> y; // 좌표 입력

	if (map[x][y] == 1) { // 입력한 좌표에 지뢰가 있다면
		cout << -1 << endl; // -1 출력 
	}
	else { // 지뢰가 없다면 8방향 지뢰 탐색
		int count = 0;
		for (int i = 0; i < 8; i++) {
			// 지뢰가 있을 때 count++
			if (map[x + dx[i]][y + dy[i]] == 1) {
				count++;
			}
		}
		cout << count << endl; // 지뢰 갯수 출력
	}

	return 0;
}
