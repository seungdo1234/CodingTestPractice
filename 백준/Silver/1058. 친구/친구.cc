#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

#define INF 1e9

// https://www.acmicpc.net/problem/1058

using namespace std;

bool isFriend[51][51] = { false, };
bool isCheck[51][51] = { false, };
int friendsCount[51] = { 0, };
int main() {
	int n;

	cin >> n;

	char input;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> input;

			if (input == 'Y') {
				isFriend[i][j] = true;
			}
		}
	}

	int maxCount = -1;
	for (int i = 1; i <= n; i++) {
		int count = 0;
		for (int j = 1; j <= n; j++) {
			if (!isCheck[i][j] && isFriend[i][j] && isFriend[j][i])
			{
				//cout << i << " 번째 친구 = > " << j << endl;
				isCheck[i][j] = true;
				count++;
				for (int k = 1; k <= n; k++) {
					if (i != k && !isCheck[i][k] && !isFriend[i][k] && isFriend[j][k] && isFriend[k][j]) {
						isCheck[i][k] = true;
						count++;
					//	cout << i << " 번째 친구 = > " << k << endl << endl;
					}
				}
			}
		}

		if (maxCount < count)
			maxCount = count;
	}
	
	cout << maxCount;
	return 0;
}
