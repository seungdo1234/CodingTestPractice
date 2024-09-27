#include <iostream>
#include <vector>

// https://www.acmicpc.net/problem/23968

using namespace std;

int n, k;

void BubbleSort(vector<int> &vec) {
    int count = 0;

    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j < i; j++) {
            if (vec[j] > vec[j + 1]) {
                int tmp = vec[j];
                vec[j] = vec[j + 1];
                vec[j + 1] = tmp;
                count++;
                if (count == k) {
                    cout << vec[j] << " " << vec[j + 1];
                    return;
                }
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

    BubbleSort(numbers);


    return 0;
}