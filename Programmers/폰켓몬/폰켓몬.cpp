#include <vector>
#include <set>

// https://school.programmers.co.kr/learn/courses/30/lessons/1845

using namespace std;

int solution(vector<int> nums)
{
     set<int> uniqueMonsters(nums.begin(), nums.end()); // 중복 제거
    int maxPick = nums.size() / 2; // 최대 선택 가능한 폰켓몬 수
    return min((int)uniqueMonsters.size(), maxPick); // 종류의 수와 maxPick 중 작은 값 반환
}
