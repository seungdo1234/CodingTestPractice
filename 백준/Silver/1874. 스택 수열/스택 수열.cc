#include <iostream>
#include <stack>
#include <vector>
#include <queue>

using namespace std;

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	queue <int> q;
	for (int i = 0; i < n; i++) {
		int input;
		cin >> input;
		q.push(input);
	}

	vector <char> answer;
	stack <int> stack;
	for (int i = 1; i <= n; i++) {
		stack.push(i);
		answer.push_back('+');

		while (true) {
			if (stack.empty() || q.empty() || stack.top() != q.front()) break;

			q.pop();
			stack.pop();
			answer.push_back('-');
		};
	}

	if (!q.empty())
		cout << "NO";
	else {
		for (int i = 0; i < answer.size(); i++) {
			cout << answer[i] << "\n";
		}

	}

	return 0;
}