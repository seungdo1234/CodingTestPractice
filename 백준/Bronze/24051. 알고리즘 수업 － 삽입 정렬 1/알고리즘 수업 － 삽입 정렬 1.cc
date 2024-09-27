#include <iostream>
#include <vector>

// https://www.acmicpc.net/problem/24051

using namespace std;

int n, k;

void InsertionSort(vector<int> &vec) {
    int count = 0;

    for(int i = 1; i < n; i ++){
        int sortNum = vec[i];
        
        for (int j = i; j > 0; j--) {
            if (vec[j] < vec[j - 1]) {
                int tmp = vec[j];
                vec[j] = vec[j - 1];
                vec[j - 1] = tmp;
				count++;
				if (count == k) {
				    cout << vec[j];
				    return;
				}
            }
            else
                break;
        }

        if (vec[i] != sortNum) {
            count++;
            if (count == k) {
                cout << sortNum;
                return;
            }
        }
    }

    cout << -1;
}
int main() {
   
    cin >> n >> k;

    vector<int> numbers(n);
    for (int i = 0; i < n; i++) {
        cin >> numbers[i];
    }

    InsertionSort(numbers);


    return 0;
}