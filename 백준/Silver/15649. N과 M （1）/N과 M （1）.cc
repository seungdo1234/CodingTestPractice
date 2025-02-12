#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    
	int n, m;
	cin >> n >> m;
    
	vector<int> v(n);
	vector<bool> selector(n, false);
	for (int i = 0; i < n; ++i) {
		v[i] = i + 1;
		if (i >= n - m) selector[i] = true;
	}
    
	vector<vector<int>> result;
	do {
		vector<int> selected;
		for (int i = 0; i < n; ++i) {
			if (selector[i]) selected.push_back(v[i]);
		}
		sort(selected.begin(), selected.end());
		do {
			result.push_back(selected);
		} while (next_permutation(selected.begin(), selected.end()));
	} while (next_permutation(selector.begin(), selector.end()));
    
	sort(result.begin(), result.end());
	for (auto& perm : result) {
		for (int num : perm) cout << num << ' ';
		cout << '\n';
	}
	return 0;
}
