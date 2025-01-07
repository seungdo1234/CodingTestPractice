#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	while(true)
	{
		string input;
		getline(cin, input);
		if(input == ".")
			break;

		stack<char> stack;
		stack.push('0');
		
		for(int i = 0; i < input.length(); i++)
		{
			char c = input[i];
			if(!(c == '(' || c == ')' || c == '[' || c == ']')) continue;
			
			if((c == ')' && stack.top() == '(') || (c == ']' && stack.top() == '[')){
				stack.pop();
			}
			else
			{
				stack.push(c);
			}
		}
		
		string output = stack.size() == 1 ? "yes\n" : "no\n";
		cout << output;
	}
	return 0;
}