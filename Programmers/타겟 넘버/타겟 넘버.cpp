#include <string>
#include <vector>

using namespace std;

// https://school.programmers.co.kr/learn/courses/30/lessons/43165#

int answer = 0;

void Solution(int curNum , int target ,int curStep, vector<int> numbers){
    if(curStep == numbers.size() - 1){
        if (curNum == target)
            answer++;
        return;
    }
    
    curStep++;
    
    Solution(curNum + numbers[curStep], target, curStep, numbers );
    Solution(curNum - numbers[curStep], target, curStep, numbers );
}

int solution(vector<int> numbers, int target) {
    
    Solution(numbers[0], target, 0, numbers);
    Solution(-numbers[0], target, 0, numbers);
    
    return answer;
}
