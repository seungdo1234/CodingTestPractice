#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n, x, count = 0;

	cin >> n;
	vector <int> vec(n);
	for (int i = 0; i < n; i++) {
		cin >> vec[i];
	}
	cin >> x;

	sort(vec.begin(), vec.end());

	int left = 0, right = n - 1;
	while (left < right) {
		int value = vec[left] + vec[right];
		if (value > x) {
			right--;
		}
		else if (value < x) {
			left++;
		}
		else {
			count++;
			left++;
			right--;
		}
	}
	

	cout << count;

	return 0;
}