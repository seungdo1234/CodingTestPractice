#include <string>
#include <vector>
#include <cmath>
// https://school.programmers.co.kr/learn/courses/30/lessons/136798
using namespace std;

// 약수의 갯수를 구하는 함수
int CountDivisors(int num){   
    int count = 0;    
    // 약수는 주어진 수의 제곱근까지만 확인하면 된다.
    for(int i = 1; i <= (int)sqrt(num); i++){
        if(num  % i == 0) {
            // 나눈 숫자하고 나눈 몫이 같을 경우는 약수 갯수 +1, 그 외엔 약수 갯수 +2
            if(num  / i == i) count += 1;
            else count += 2; 
        }
    }    
    return count;    
}
int solution(int number, int limit, int power) {
    // limit는 2이상이기 때문에 1은 무조건 포함
    int answer = 1; 
        
    for(int i = 2; i<=number; i++){
        // 각 숫자 별 약수의 갯수 구하기
        int divisorCount = CountDivisors(i);
        
        // 약수의 갯수가 limit를 넘는지 확인, 넘는다면 power로 조정
        if(divisorCount > limit) divisorCount = power;
        answer += divisorCount;
    }
    return answer;
}
