#include <vector>

using namespace std;

bool IsEven(int num){
    return num % 2 == 0;
}

vector<int> solution(vector<int> arr, vector<int> query) {
    
    for(int i = 0;i < query.size(); i++){
        int q = query[i];
        if(IsEven(i))
            arr.erase(arr.begin() + q + 1, arr.begin() + arr.size());
        else
            arr.erase(arr.begin() , arr.begin() + q ); 
    }
    return arr;
}