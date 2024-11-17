#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

unordered_map<int,int> leftCut;
unordered_map<int,int> rightCut;


int solution(vector<int> topping) {
    int answer = 0;

    if(topping.size() == 1){
        return answer;
    }
    
    int leftCount = 0, rightCount = 0;
    for(int i  = 0; i < topping.size(); i++){
        if(rightCut[topping[i]]++ == 0){
            rightCount ++;
        }
    }
    
    for(int i  = 0; i < topping.size(); i++){
         if(leftCut[topping[i]]++ == 0){
            leftCount ++;
        }   
        
       if(--rightCut[topping[i]] == 0){
            rightCount --;
        }
        
        if(leftCount == rightCount){
            answer++;
        }
    }
    
    
    return answer;
}