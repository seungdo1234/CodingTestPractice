#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, count = 0;
	cin >> n;

	for(int i = 0; i < n; i++)
	{
		string input;
		cin >> input;

		stack<char> stack;
		stack.push('0');

		for(int j = 0; j < input.length(); j++)
		{
			if(stack.top() == input[j])
			{
				stack.pop();
			}
			else
			{
				stack.push(input[j]);
			}
		}

		if(stack.size() == 1)
		{
			count++;
		}
		
	}

	cout << count;
	
	return 0;
}