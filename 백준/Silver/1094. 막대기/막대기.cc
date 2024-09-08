#include<iostream>

//https://www.acmicpc.net/problem/1094
using namespace std;


int main() {
	int X;

	cin >> X;

    int count = 0;
    while (X > 0) {
        if (X % 2 == 1) {
            count++;
        }
        X /= 2;
    }

    cout << count;
	return 0;
}