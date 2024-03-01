#include<iostream>
#include<vector>
#include<algorithm>

// https://www.acmicpc.net/problem/11399 11399번 ATM
using namespace std;

int n;
vector <int> line;

void ATM() {

	sort(line.begin(), line.end()); // 정렬

	int result = 0;
	for (int i = 0; i < n; i++) { // 첫 번째 사람부터 시간 계산
		for (int j = 0 ; j <= i; j++) {
			result += line[j];
		}
	}
	cout << result << endl;
}
int main() {
	cin >> n;
	
	int atm_Time;
	for (int i = 0; i < n; i++) {
		cin >> atm_Time;
		line.push_back(atm_Time);
	}

	ATM();
}
