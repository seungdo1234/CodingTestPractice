#include <iostream>
#include <string>
#include <list>

using namespace std;
int cursor = 0;

void GetPassword(string input) {
	list<char> password;
	auto cursor = password.begin();

	for (int i = 0; i < input.length(); i++) {
		char c = input[i];

		if (c == '<') {
			if (cursor != password.begin())
				cursor--;
		}
		else if (c == '>') {
			if (cursor != password.end())
				cursor++;
		}
		else if (c == '-') {
			if (cursor != password.begin()) {
				cursor--;
				cursor = password.erase(cursor);
			}
		}
		else {
			password.insert(cursor, c);
		}
	}

	for (auto iter = password.begin();iter != password.end(); iter++) {
		cout << *iter;
	}
	cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;

	cin >> n;

	for (int i = 0; i < n; i++) {
		string input;
		cin >> input;

		GetPassword(input);
	}


	return 0;
}