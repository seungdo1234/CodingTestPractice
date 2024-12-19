#include <iostream>
#include <queue>
#include <string>

using namespace std;

queue<int> q;

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	for(int i = 0; i < n; i++)
	{
		string input;
		cin >> input;

		int result = 0;
		if(input == "push")
		{
			cin >> input;
			int pushNum = stoi(input);
			q.push(pushNum);
			continue;
		}

		if(input == "pop" || input == "front")
		{
			result = q.empty() ? -1 : q.front();
			if (!q.empty() && input == "pop")
				q.pop();
		}
		else if (input == "back")
			result = q.empty() ? -1 : q.back();
		else if (input == "empty")
			result = q.empty() ? 1 : 0;
		else if (input == "size")
			result = q.size();

		cout << result << "\n";
	}

	return 0;
}
