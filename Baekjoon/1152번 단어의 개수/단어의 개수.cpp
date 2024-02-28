#include <iostream>
#include<string>

// https://www.acmicpc.net/problem/1152 단어의 개수
using namespace std;

int main() {
	string str;
	char chr = ' ';
	int count = 1; // 문자 1개 이상은 무조건 입력되기 때문에 기본 단어의 갯수는 1로 설정

	getline(cin, str); // 문자열 입력

	if (str.length() == 1 && str[0] == ' ') { // 공백 하나만 입력할 수 있으므로 0출력
		cout << 0;
		return 0;
	}

	for (int i = 0; i < str.length(); i++) { // 문자열 길이 만큼 for문 반복
		 // 단어는 공백으로 구분하기 때문에 공백마다 Count++, 문자열 처음과 마지막에 공백이 나오는 경우도 있으니깐 조건으로 제외
		if (str[i] == ' ' && i > 0 && i < str.size() - 1) {
			count++;
		}
	}

	cout << count << "\n"; // 출력

	return 0;
}



----------------------------------------------------------------------------------------------------------------------------------------
#include <iostream>
#include<string>
#include<sstream>
// https://www.acmicpc.net/problem/1152 단어의 개수
using namespace std;

int main() {
	string str, buf;
	int count = 0; // 문자 1개 이상은 무조건 입력되기 때문에 기본 단어의 갯수는 1로 설정

	getline(cin, str); // 문자열 입력

	stringstream ss(str); // stringstream 변수에 문자열 저장

 // 공백과\n 기준으로 문자열 탐색
	while (ss >> buf) { // 문자열 끝까지 탐색 완료시 반복문 break 
		count++;
	}

	cout << count << endl;

	return 0;
}
