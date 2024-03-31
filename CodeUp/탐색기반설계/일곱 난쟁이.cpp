// 처음 풀이한 코드
#include <iostream>
#include<algorithm>
using namespace std;
// https://codeup.kr/problem.php?id=3008

int dwarfs[9] = { 0, }, sum = 0;
void Func() {
	for (int i = 0; i < 9; i++) {
		for (int j = i + 1; j < 9; j++) {
			if (dwarfs[i] + dwarfs[j] == sum) { // 나머지 난쟁이 둘의 키의 합과 같다면
				// 일곱 난쟁이가 아닌 나머지 난쟁이 둘을 구하고 키를 최대로 만듬
				dwarfs[i] = 101;
				dwarfs[j] = 101;
				return;
			}
		}
	}

}
int main() {
	for (int i = 0; i < 9; i++) { // 아홉 난쟁이를 입력받음
		cin >> dwarfs[i];
		sum += dwarfs[i]; // 아홉 난쟁이의 합을 구함
	}

	// 아홉 난쟁이의 합 - 일곱 난쟁이의 합 =  나머지 난쟁이 둘의 합
	sum -= 100; 

	Func(); // 일곱 난쟁이를 구함

	sort(dwarfs, dwarfs + 9); // 오름차순 정렬

	for (int i = 0; i < 7; i++) { // 일곱 난쟁이 출력
		cout << dwarfs[i] << endl;
	}

	return 0;
}

----------------------------------------------------------------------------------------------------------------------------------
// 투 포인터 알고리즘을 적용해 풀이한 코드
#include <iostream>
#include<algorithm>
using namespace std;
// https://codeup.kr/problem.php?id=3008

int main() {
    int dwarfs[9], sum = 0;

    for (int i = 0; i < 9; i++) { // 난쟁이들의 키를 입력 받음
        cin >> dwarfs[i];
        sum += dwarfs[i]; // 9 난쟁이들의 키의 합을 구함
    }
    
    // 투포인터 알고리즘을 사용해야하기 때문에 오름차순으로 정렬
    sort(dwarfs, dwarfs + 9);

    int left = 0, right = 8, currentSum = 0;
    // 아홉 난쟁이의 합 - 일곱 난쟁이의 합 =  나머지 난쟁이 둘의 합
    sum -= 100; 
    while (left < right)
    {
        currentSum = dwarfs[left] + dwarfs[right]; // 난쟁이 둘의 합
        if (currentSum == sum) { // 처음에 구했던 나머지 난쟁이 둘의 합과 같다면
            for (int i = 0; i < 9; i++) { // 해당 난쟁이들을 빼고 나머지 일곱 난쟁이의 키 출력
                if (i != left && i != right) {
                    cout << dwarfs[i] << endl;
                }
            }
            break;
        }
        else if (currentSum > sum) { // 난쟁이 둘의 합이 크다면 right --
            right--; 
        }
        else { // 난쟁이 둘의 합이 크다면 left --
            left++;
        }
    }
   
    return 0;
}
