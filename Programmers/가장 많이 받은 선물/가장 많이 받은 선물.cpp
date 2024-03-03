#include <string>
#include <map>
#include <sstream>
#include <algorithm>
#include <vector>

// https://codingjj.tistory.com/106#google_vignette 해당 블로그 참조해 풀이했습니다.
using namespace std;

map<string,int> giftNum; // 사람 별 선물지수 (사람, 선물지수)
map<string,int> personNum; // 사람 별 번호 (사람, 번호)
int giftGraph[50][50] = {0,}; // 선물 지표

void Init(vector<string> friends){ // 사람 별 번호 저장하는 함수
    int count = 0;
    
    for(string name : friends){
        personNum[name] = count;
        count ++;
    }
}
int cmp(int a, int b){
    return a>b;
}
int solution(vector<string> friends, vector<string> gifts) {
    Init(friends); 
    
    vector<int> result (50, 0); // 사람마다 다음달에 받아야할 선물 갯수가 들어가는 벡터
   
    for(string person : gifts){ // 선물 지수 및 선물 지표 
        istringstream iss(person); // 문자열 파싱
        string name1, name2;
        iss >> name1 >> name2; // 문자열 파싱
        
        giftNum[name1]++; // 선물을 준사람 선물 지수 ++
        giftNum[name2]--; // 선물을 받은 사람 선물 지수 --
        giftGraph[personNum[name1]][personNum[name2]] ++; // 선물 지표 ++        
    }
    
    for(int i = 0; i<friends.size(); i++){ // 다음달에 받아야할 선물 갯수 구하기
        for(int j= i; j<friends.size(); j++){
            // 이름 저장
            string name1 =  friends[i]; 
            string name2 =  friends[j];
            // 번호 저장    
            int num1 = personNum[name1];
            int num2 = personNum[name2];
            
            // 주고 받은 선물 갯수 비교
            if(giftGraph[num1][num2] > giftGraph[num2][num1])  result[num1] ++;
            else if(giftGraph[num1][num2] < giftGraph[num2][num1]) result[num2] ++;
            else{ // 주고 받은 선물 갯수가 같다면
                // 선물 지수 비교
                if(giftNum[name1] > giftNum[name2]) result[num1]++;
                else if(giftNum[name1] < giftNum[name2]) result[num2]++;
            }
            
        }
    }
    // 내림차순 정렬
    sort(result.begin(), result.end(), cmp);
    
    return result[0]; 
}
