#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> numbers) {
    int answer = 0, curNum = 0;
    sort(numbers.begin(), numbers.end());

    for (int i = 0; i < numbers.size(); i++) {
        if (curNum != numbers[i])
        {
            answer += curNum;
            i--;
        }
        curNum++;
    }

    for (int i = curNum; i < 10; i++) answer += i;
    
    return answer;
}