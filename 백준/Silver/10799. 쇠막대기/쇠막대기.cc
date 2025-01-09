#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	string input;
	cin >> input;

	int sum = 0, bar = 0;
	bool flag = false;
	stack<char> stack;
	stack.push('0');
	
	for(int i = 0; i < input.length(); i++)
	{
		char c = input[i];
		if(c == '(')
		{
			bar ++;
			stack.push(c);
			flag = true;
		}
		else
		{
			bar--;
			if(flag)
			{
				sum += bar;
				flag = false;
			}
			else sum += 1;
			
			stack.pop();
		}
	}

	cout << sum ;
	return 0;
}