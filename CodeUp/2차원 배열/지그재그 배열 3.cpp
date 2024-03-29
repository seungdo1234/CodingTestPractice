#include <iostream>

// https://codeup.kr/problem.php?id=1513

using namespace std;

int map[100][100] = { 0, };
int main() {
	int n; // n 입략
	cin >> n;

	int x = n, y = 1, num = 1; // 시작 x,y 좌표, 숫자
	bool isRight = true; // 오른쪽 위로 가는지
	while (true)
	{

		map[x][y] = num++; // 현재 좌표에 숫자 기입

		if (x == n && y == n) { // 마지막 좌표일 때
			break;
		}


		if (isRight) { // 오른쪽 위로 가면
			if (y == n) { // 오른쪽 끝일 때
				x++;
				isRight = false;
			}
			else { // 오른쪽 위로 이동
				x--;
				y++;
			}
		}
		else { // 왼쪽 아래로 가면
			if (x == n) { // 왼쪽 끝일 때
				y++;
				isRight = true;
			}
			else { // 왼쪽 아래로 이동
				x++;
				y--;
			}
		}

	}

	
	for (int i = 1; i <= n; i++) { // 출력
		for (int j = 1; j <= n; j++) {
			cout << map[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}
