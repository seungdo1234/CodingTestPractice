#include <string>
#include <vector>
#include <iostream>

using namespace std;

char GetNum(string s){
    char c;
    
    if(s == "zero"){
        c = '0';
    }
    else if(s == "one"){
        c = '1';
    }
    else if(s == "two"){
        c = '2';
    }
    else if(s == "three"){
        c = '3';
    }
    else if(s == "four"){
        c = '4';
    }
    else if(s == "five"){
        c = '5';
    }
    else if(s == "six"){
        c = '6';
    }
    else if(s == "seven"){
        c = '7';
    }
    else if(s == "eight"){
        c = '8';
    }
    else if(s == "nine"){
        c = '9';
    }
   return c;
}

bool IsParsing(string s){
    bool b = false ;

    if(s == "zero"){
        b = true;
    }
    else if(s == "one"){
          b = true;
    }
    else if(s == "two"){
         b = true;
    }
    else if(s == "three"){
              b = true;
    }
    else if(s == "four"){
            b = true;
    }
    else if(s == "five"){
       b = true;
    }
    else if(s == "six"){
            b = true;
    }
    else if(s == "seven"){
        b = true;
    }
    else if(s == "eight"){
          b = true;
    }
    else if(s == "nine"){
      b = true;
    }
    
   return b;
}

int solution(string s) {
    int answer = 0;
    string str = "", sub ="";
    
    for(int i =0; i < s.length(); i++){
        char c = s[i];
        sub += c;
        
        if(c >= 48 && c <=57){
            str += c;
            sub = "";
        }
        else if(IsParsing(sub)){
            str += GetNum(sub);
            sub ="";
        }
        
    }
    
    answer = stoi(str);
    return answer;
}