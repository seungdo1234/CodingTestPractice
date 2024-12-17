#include <iostream>
#include <stack>

using namespace std;

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int k, input;
	cin >> k;

	stack<int> stack;
	for (int i = 0; i < k; i++)
	{
		cin >> input;

		if (input == 0)
			stack.pop();
		else
			stack.push(input);
	}

	int sum = 0;
	while (!stack.empty()) {
		sum += stack.top();
		stack.pop();
	}

	cout << sum;

	return 0;
}

