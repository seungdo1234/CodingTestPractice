#include <iostream>

// https://codeup.kr/problem.php?id=1098
using namespace std;

int map[100][100] = { 0, };

int main() {
	int h, w, n, l,d,x,y;

	cin >> h >> w >> n;

	// 격자판에 막대기 놓기 
	for (int i = 0; i < n; i++) {
		cin >> l >> d >> x >> y;
		
		// 막대기의 길이 만큼 막대기를 놓음
		for (int j = 0; j < l; j++) {
			map[x][y] = 1;
			if (d == 0) {
				y++;
			}
			else {
				x++;
			}
		}

	}

	// 출력
	for (int i = 1; i <= h; i++) {
		for (int j = 1; j <= w; j++) {
			cout << map[i][j] << " ";
		}
		cout << endl;
	}
	
	return 0;
}
