#include <string>
#include <vector>
// https://school.programmers.co.kr/learn/courses/30/lessons/132267#
using namespace std;

int solution(int a, int b, int n) {
    int answer = 0, coke = 0 , emptyCoke= 0;
    
    while(true){
        emptyCoke = n;  // 빈 콜라 병 갯수 저장      
        coke = (emptyCoke / a) * b; // 마트에서 받은 콜라 갯수
        answer += coke; // 받은 콜라 ++
        emptyCoke %= a; // 마트에 전달하지 않은 빈 콜라 병 갯수
        
        n = emptyCoke + coke; // 현재 가지고 있는 콜라 갯수
               
        if(n / a == 0) {break; } // 더 이상 마트에 전달할 콜라가 없다면 break;
    }
    return answer;
}
