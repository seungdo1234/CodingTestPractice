#include <iostream>
#include<stack>
#include<string>

using namespace std;

int main() {
	int num;

	cin >> num;

	while (num > 0) {

		string vps;
		cin >> vps;
		
		stack<char> vpsStack;
		
		for (int i = 0; i < vps.length(); i++) {
			if (vpsStack.empty()) { // 문자열이 비어 있을때 괄호 Push
				vpsStack.push(vps[i]);
			}
			else {
				if (vpsStack.top() < vps[i]) { // '('은 ')'보다 작기 때문에 해당 조건문으로 () 짝 판별, 스택에 맞는 괄호가 나온다면 top에 있는 '('팝
					vpsStack.pop();
				}
				else { // 짝이 맞지 않다면 Push
					vpsStack.push(vps[i]);
				}
			}
		}
		if (vpsStack.empty()) { // 스택이 비어있다면 Yes
			cout << "YES\n";
		}
		else {
			cout << "NO\n"; // 스택에 뭔가가 남아있다면 No
		}
		num--;
	}


	return 0;
}
