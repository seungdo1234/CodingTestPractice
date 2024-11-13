#include <string>
#include <vector>
#include<iostream>
#include<algorithm>
using namespace std;


    vector<int> cook;

int AddCook(int num){
    cook.push_back(num);
    int size = cook.size();
     if(num == 1 && size >= 4){
            if(cook[size - 1] == 1 && cook[size - 2] == 3 && cook[size - 3] == 2 && cook[size - 4] == 1){
                
                // for(int i = 0; i < 4; i++){
                //     cout << cook[i] << " ";
                // }
                // cout <<endl;
                for(int i = 0; i < 4; i ++) {
                    cout << cook[size - 1 -i] << " ";
                    cook.pop_back();
                }
                cout <<endl;
                return 1;
            }
     }
//     if((size != 0 && cook[size - 1]  <= num) || num == 1)
//     {
//         cook.push_back(num);
//         size++;
//         if(num == 1 && size >= 4){
//             if(cook[size - 1] == 1 && cook[size - 2] == 3 && cook[size - 3] == 2 && cook[size - 4] == 1){
                
//                 // for(int i = 0; i < 4; i++){
//                 //     cout << cook[i] << " ";
//                 // }
//                 // cout <<endl;
//                 for(int i = 0; i < 4; i ++) {
//                     cout << cook[size - 1 -i] << " ";
//                     cook.pop_back();
//                 }
//                 cout <<endl;
//                 return 1;
//             }
//         }   
//     }
    return 0;
}


int solution(vector<int> ingredient) {
    int answer = 0;
    
    for(int i = 0; i < ingredient.size(); i++){
        int num = ingredient[i];
        answer += AddCook(num);
    }

    return answer;
}