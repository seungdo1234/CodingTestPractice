#include <string>
#include <vector>

using namespace std;

string solution(string phone_number) {
    int length = phone_number.length();

    string answer = "";

    for (int i = 0; i < length; i++) {
        char c = '*';
        if (i >= length - 4)
            c = phone_number[i];

        answer += c;
    }
    return answer;
}