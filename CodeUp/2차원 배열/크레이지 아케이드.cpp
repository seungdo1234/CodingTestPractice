#include <iostream>
#include <vector>

// https://codeup.kr/problem.php?id=1525
using namespace std;

int map[10][10] = { 0, }; // 전체 맵
vector<pair<int, int>> waterBalloons; // 물풍선의 위치 정보를 저장하는 벡터
vector<pair<int, int>> playerPos; // 플레이어의 위치 정보를 저장하는 벡터

// 4방향 배열
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

void Explode() {
	for (int i = 0; i < waterBalloons.size(); i++) { // 물풍선 터트림
		int x = waterBalloons[i].first, y = waterBalloons[i].second; // 물풍선의 x,y 좌표 저장
		int power = map[x][y]; // 물풍선의 파워 저장

		for (int z = 0; z < 4; z++) { // 물풍선이 4방향으로 터짐
			for (int j = 0; j <= power; j++) { // 물풍선의 파워 만큼 반복
				// 물풍선이 터졌을 때 물 줄기 x,y 좌표
				int explode_X = x + dx[z] * j;
				int explode_Y = y + dy[z] * j;

				// 물줄기가 맵을 벗어났거나 벽(-1)에 맞았을 때 물줄기는 멈춤
				if (explode_X < 0 || explode_X > 9 || explode_Y < 0 || explode_Y > 9
					|| map[explode_X][explode_Y] == -1) {
					break;
				}

				// 혹시나 다른 물풍선을 건들 수도 있으니 빈칸에만 물줄기(-2)를 저장
				if (j == 0 || map[explode_X][explode_Y] == 0) { // j == 0은 자기 자신은 터져야 하기때문에 조건에 넣음
					map[explode_X][explode_Y] = -2;
				}
			}
		}
	}
}

void PlayerState() {
	int n;

	cin >> n; // 플레이어 수 입력
	for (int i = 0; i < n; i++) { // 플레이어 수만큼 위치 입력
		int x, y;
		cin >> x >> y;
		if (map[x - 1][y - 1] == 0) {  // 물풍선이 터진 맵에 살아 남은 플레이어 번호 저장
			map[x - 1][y - 1] = i + 1;
		}
		playerPos.push_back({ x - 1, y - 1 }); // 플레이어 위치 정보 벡터에 저장
	}

	for (int i = 0; i < 10; i++) { // 전체 맵 출력
		for (int j = 0; j < 10; j++) {
			cout << map[i][j] << " ";
		}
		cout << endl;
	}

	cout << "Character Information" << endl;
	for (int i = 0; i < n; i++) { // 플레이어의 현재 상태 출력
		int state = map[playerPos[i].first][playerPos[i].second];

		if (state < 0) {
			cout << "player " << i + 1 << " dead\n";
		}
		else {
			cout << "player " << i + 1 << " survive\n";
		}
	}
}

int main() {

	for (int i = 0; i < 10; i++) { // 맵 입력
		for (int j = 0; j < 10; j++) {
			cin >> map[i][j];
			if (map[i][j] > 0) {
				waterBalloons.push_back({ i, j });
			}
		}
	}

	Explode(); // 물풍선 터짐 

	PlayerState(); // 플레이어 상태 정보 
	
	return 0;
}
