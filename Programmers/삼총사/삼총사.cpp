#include <vector>

using namespace std;

int solution(vector<int> number) {
    int answer = 0;
    
    for(int i = 0; i< number.size(); i++){
       for(int j = i + 1; j< number.size(); j++){
           for(int x = j + 1; x< number.size(); x++){
                if(number[i] + number[j] + number[x] == 0){
                    answer++;
                }
           }
       } 
    }
    return answer;
}
