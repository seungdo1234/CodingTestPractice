#include <string>
#include <vector>
#include <algorithm>
#include <iostream>


using namespace std;

int solution(vector<vector<int>> targets) {
    int answer = 0;
    
    sort(targets.begin(), targets.end());
    
    int end = 987654321;
    
//     for(int i = 0; i < targets.size(); i++){
//         cout << targets[i][0] << " " << targets[i][1]<< " | " ;
//         }
    
    for(int i = 0; i < targets.size(); i++){
        if(end > targets[i][1]){
            end = targets[i][1];
        }
        else if(end <= targets[i][0]  ){
        //    cout << i <<endl;
            answer ++;
            end = targets[i][1];
        }
    }
    
    return ++answer;
}