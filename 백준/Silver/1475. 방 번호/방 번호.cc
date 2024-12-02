#include <iostream>
#include <string>

using namespace std;

int main() {
	int roomNumber;
	int arr[10] = { 0, };

	cin >> roomNumber;

	string str = to_string(roomNumber);
	int maxNum = 0;
	for (int i = 0; i < str.length(); i++) {
		int n = str[i] - '0';
		if (++arr[n] > maxNum  && n != 6 && n != 9) {
			maxNum = arr[n];
		}
	}

	int a = arr[6] + arr[9];

	maxNum = max(maxNum, (a) / 2 + (a % 2 == 0 ? 0 : 1));
	cout << maxNum;
	return 0;
}