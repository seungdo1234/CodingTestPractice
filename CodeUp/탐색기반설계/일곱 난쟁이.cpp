
#include <iostream>
#include <vector>
#include<algorithm>
// https://codeup.kr/problem.php?id=3008
using namespace std;

int dwarfs[9] = { 0, }, sum = 0;
void Func() {

	for (int i = 0; i < 9; i++) {
		for (int j = i + 1; j < 9; j++) {
			if (dwarfs[i] + dwarfs[j] == sum) {
				dwarfs[i] = 101;
				dwarfs[j] = 101;
				return;
			}
		}
	}

}
int main() {


	for (int i = 0; i < 9; i++) {
		cin >> dwarfs[i];
		sum += dwarfs[i];
	}

	sum -= 100;

	Func();

	sort(dwarfs, dwarfs + 9);

	for (int i = 0; i < 7; i++) {
		cout << dwarfs[i] << endl;
	}

	return 0;
}
