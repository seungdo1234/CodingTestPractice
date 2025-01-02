#include <iostream>
#include <vector>

using namespace std;

vector<int> solution(int n, long long left, long long right) {
    vector<int> answer;

    for(long long i = left; i <= right; i++){
       int row = i % n + 1;
       int column = i / n + 1;
                    
       answer.push_back(row <= column ? column : row);
    }


    return answer;
}