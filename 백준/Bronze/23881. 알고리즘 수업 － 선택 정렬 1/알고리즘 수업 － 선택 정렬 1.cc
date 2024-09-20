#include<iostream>
#include<vector>

// https://www.acmicpc.net/problem/23881

using namespace std;


int main() {
	int n, k, count = 0;

	cin >> n >> k;

	vector <int > vec(n);
	for (int i = 0; i < n; i++) {
		cin >> vec[i];
	}

	for (int i = n - 1; i > 0; i--) {
		int max = i;

		for (int j = i - 1; j >= 0; j--) {
			if (vec[max] < vec[j]) {
				max = j;
			}
		}

		if (max != i) {
			int tmp = vec[max];
			vec[max] = vec[i];
			vec[i] = tmp;
			count++;
		}

		if (k == count) {
			cout << vec[max] << " " << vec[i];
			return 0;
		}
	}

	cout << "-1";


	return 0;
}
