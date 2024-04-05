// 맵을 이용한 풀이
#include <iostream>
#include<map>
// https://codeup.kr/problem.php?id=1430&rid=0
using namespace std;

int main() {
	int n,m, num;

	cin >> n;

	map <int, bool> memorys ; // 맵 선언

	for (int i = 0; i < n; i++) { // 해당 숫자를 키로 true 저장
		cin >> num;
		memorys[num] = true;
	}

	cin >> m;

	for (int i = 0; i < m; i++) {
		cin >> num;

		if (memorys[num]) { // 해당 숫자가 true 일 때 1 출력
			cout << "1 ";
		}
		else { // false 일 때 0 출력
			cout << "0 ";
		}
	}

	return 0;
}

//------------------------------------------------------------------------------------------------------
// 해시 셋을 이용한 풀이
#include <iostream>
#include <unordered_set>
// https://codeup.kr/problem.php?id=1430&rid=0
using namespace std;

int main() {
	int n, m, num;
	cin >> n;

	unordered_set<int> memorys; // 맵 대신 해시셋을 사용하여 빠른 검색 가능

	for (int i = 0; i < n; i++) {
		cin >> num;
		memorys.insert(num); // set에 숫자 추가
	}

	cin >> m;

	for (int i = 0; i < m; i++) {
		cin >> num;

		if (memorys.find(num) != memorys.end()) { // 숫자가 발견되면 1 출력
			cout << "1 ";
		}
		else { // 발견되지 않으면 0 출력
			cout << "0 ";
		}
	}

	return 0;
}
