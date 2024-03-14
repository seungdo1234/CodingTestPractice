#include <string>
#include <vector>
#include <algorithm>
// https://school.programmers.co.kr/learn/courses/30/lessons/135808
using namespace std;

bool cmp (int a, int b){
    return a > b;
}

int solution(int k, int m, vector<int> score) {
    int answer = 0;
    
    // 내림차순 정렬
    sort(score.begin(), score.end(), cmp);
    
    // 상자 갯수 만큼 반복
    for(int i =0; i< score.size() / m; i++){
        // 최저 점수, 사과 포장 시작 위치
        int min = 10, startPos = i * m;      
        for(int j = startPos; j < startPos + m; j ++ ){
            if(score[j] < min){
                min = score[j]; // 상저 별 최저 점수 구하기
            }
        }
        // 최저 점수 * 상자에 담긴 사과 개수
        answer += min * m;

    }
    return answer;
}
