using namespace std;
// https://school.programmers.co.kr/learn/courses/30/lessons/82612
long long solution(int price, int money, int count)
{
    long long sum = 0;
    
    for(int i = 1; i <= count ; i++){
        sum += price * i;      
    }
    
    return money >= sum ? 0 : sum - money;
}
