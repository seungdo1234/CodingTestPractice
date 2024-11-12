#include <string>
#include <vector>

using namespace std;

int idx ;

int GetMatchNum (int count){
    int n = 1;
    for(int i = 0;i  < count; i ++){
        n *= 2;
    }
    return n;
}

string GetBinary(int num){
    string str = "";
    
    for(int i = idx - 1; i >= 0; i--){
        int match = GetMatchNum(i);
        if(num >= match){
            str += '1';
            num -= match;
        }
        else{
            str += '0';
        }
    }
    
    return str;
}

void SetMaps(vector<string> &map, vector<int> arr){
    for(int i = 0; i < arr.size(); i++){
        string lock = GetBinary(arr[i]);
        map.push_back(lock);
    }
}
vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    idx = n;
    
    vector<string> answer;
    vector<string> map01;
    vector<string> map02;

    SetMaps(map01, arr1);
    SetMaps(map02, arr2);
    
    for(int i = 0; i < n; i++){
        string str = "";
        for(int j = 0; j < n; j++){
            if(map01[i][j] == '1' ||map02[i][j] == '1'){
                str += '#';
            }
            else{
                str += ' ';
            }
        }
        answer.push_back(str);
    }
    
    return answer;
}