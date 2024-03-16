#include <string>
#include <vector>
// https://school.programmers.co.kr/learn/courses/30/lessons/132267#
using namespace std;

int solution(int a, int b, int n) {
    int answer = 0, coke = 0 , emptyCoke= 0;
    
    while(true){
        emptyCoke = n; // 다 마신 콜라 갯수        
        coke = (emptyCoke / a) * b; // 마트에서 받은 콜라 갯수
        emptyCoke %= a; // 마트에 가져가지 않은 빈 콜라 갯수
        
        answer += coke; // 받은 콜라 갯수 ++
        
        n = emptyCoke + coke; // 현재 가지고 있는 콜라 갯수
    
        if(n / a == 0) {break;} // 더이상 받을 게 없다면
    }
    return answer;
}
