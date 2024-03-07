#include <string>
#include <vector>
// https://school.programmers.co.kr/learn/courses/30/lessons/161989
using namespace std;

int solution(int n, int m, vector<int> section) {
    int answer = 1; // 최소 1개의 구역 이상이기 때문에 answer = 1
    int draw = section.size(); // 덧칠 해야할 구역 갯수
    
    for(int i = 0; i< section.size(); ){
        for(int j = i; j < section.size(); j++){
            // 덧칠 하지 못한 구역이 있다면 
            if(section[i] + m <= section[j]){
                // 해당 부분부터 다시 덧칠
                i = j;
                break;
            }
            draw--; // 반복문이 반복된 만큼 덧칠해야할 구역 갯수 --
        }        
        if(draw == 0){ // 모든 구역을 덧칠 완료 했다면 break
            break;
        }
        answer++;
    }
        
    return answer;
}
