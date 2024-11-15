#include <string>
#include <vector>
#include<unordered_map>
#include<algorithm>
#include<iostream>
using namespace std;

unordered_map <int, int> boxMap;

bool cmp (pair<int,int> box01, pair<int,int> box02){
    return box01.second > box02.second;
}
int solution(int k, vector<int> tangerine) {
        
    for(int i = 0; i< tangerine.size(); i++){
        boxMap[tangerine[i]]++;
    }
    
    vector<pair<int,int>> vec (boxMap.begin(), boxMap.end());

    sort(vec.begin(), vec.end(), cmp);
   
   // for(int i = 0; i < vec.size(); i++){
   //      cout << vec[i].first << " " << vec[i].second<<endl;
   //  }    
    int idx = 0;
    for(idx =0 ; idx< vec.size(); idx++){
        k -= vec[idx].second;
        if(k <= 0)
            break;
    }
    return idx + 1;
}