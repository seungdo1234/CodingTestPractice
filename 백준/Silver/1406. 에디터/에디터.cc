#include <iostream>
#include <string>
#include <list>

using namespace std;

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	string input;
	int n;
	cin >> input >> n;

	list<char> editor;
	for (int i = 0; i < input.length(); i++) {
		editor.push_back(input[i]);
	}
	auto cursor = editor.end();

	for (int i = 0; i < n; i++) {
		char c;
		cin >> c;

		if (c == 'P') {
			cin >> c;
			editor.insert(cursor, c);
		}
		else if (c == 'L') {
			if (cursor != editor.begin()) cursor--;
		}
		else if (c == 'D')
		{
			if (cursor != editor.end()) cursor++;
		}
		else if (c == 'B')
		{
			if (cursor != editor.begin()) {
				cursor--;
				cursor = editor.erase(cursor);
			}
		}
	}

	for (auto c : editor) {
		cout << c;
	}

	return 0;
}