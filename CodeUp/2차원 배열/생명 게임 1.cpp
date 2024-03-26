#include <iostream>
// https://codeup.kr/problem.php?id=1515
using namespace std;

int map[26][26] = { 0, }; // 맵
int printMap[26][26] = { 0, }; // 다음 세대 맵

// 8 방향을 나타내는 배열 => x방향, y방향
int dx[8] = { 1,1,1,-1,-1,-1,0,0 };
int dy[8] = { -1,1,0,-1,1,0,1,-1 };

void NextGeneration() {
	for (int i = 1; i <= 25; i++) {
		for (int j = 1; j <= 25; j++) {
			int count = 0;
			for (int x = 0; x < 8; x++) { // 8 방향 탐색
				if (map[i + dx[x]][j + dy[x]] == 1) { // 생명이 있을 경우 count ++
					count++;
				}
			}
			// 생명이 없는 칸 주변에 3개의 생명이 있을 때 생명 탄생
			if (map[i][j] == 0 && count == 3) {
				printMap[i][j] = 1;
			}
			else if (map[i][j] == 1 && (count >= 4 || count <= 1)) {
				// 생명이 있는 칸 주변에 4마리 이상 또는 1마리 이하의 생명이 있을 때 그 칸의 생명은 죽음
				printMap[i][j] = 0;
			}
		}
	}
}
int main() {
	
	for (int i = 1; i <= 25; i++) { // 맵 입력
		for (int j = 1; j <= 25; j++) {
			cin >> map[i][j];
			printMap[i][j] = map[i][j];
		}
	}

	NextGeneration();

	for (int i = 1; i <= 25; i++) { // 다음 세대 맵 출력
		for (int j = 1; j <= 25; j++) {
			cout << printMap[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}
