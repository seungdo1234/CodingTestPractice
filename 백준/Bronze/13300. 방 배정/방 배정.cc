#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	
	int n, room, count = 0;

	cin >> n >> room;

	int arr[7][2] = { 0, };
	for (int i = 0; i < n; i++) {
		int gender, grade;
		cin >> gender >> grade;

		if (arr[grade][gender] == 0) count++;
		if (++arr[grade][gender] == room) arr[grade][gender] = 0;
	}

	cout << count;

	return 0;
}