#include <bits/stdc++.h>

using namespace std;

int GetClose(char top, char push)
{
	if(top == '(' && push == ')') return 2;
	if(top == '[' && push == ']') return 3;
	return -1;
}
int GetOpen(char push)
{
	if(push == '(') return 2;
	return 3;
}
bool IsPlus(char prev, char cur)
{
	return  (prev == '(' && cur == ')') || (prev == '[' && cur == ']');
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	string input;
	cin >> input;

	stack<char> stack;
	stack.push('0');
	int sum = 0, num = 1;
	for(int i = 0; i < input.length(); i++)
	{
		char c = input[i];
		if(c == '(' || c == '[')
		{
			num *= GetOpen(c);
			stack.push(c);
		}
		else
		{
			int val = GetClose(stack.top(), c);
			if(val == -1)
			{
				cout << 0;
				return  0;
			}
			if(IsPlus(input[i -1], c)) sum += num;
			num /= val;
			stack.pop();
		}
	}

	sum = stack.size() != 1 ? 0 : sum;
	cout << sum;
	return 0;
}
