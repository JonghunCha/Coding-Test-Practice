/*
문제 링크 : https://programmers.co.kr/learn/courses/30/lessons/84512
단순한 구현 문제이다.

중복을 제거하며 자동으로 정렬이 되어 저장되는 set을 사용하면 쉽게해결할 수 있다.
*/
#include <string>
#include <vector>
#include <set>

using namespace std;

int solution(string word) {
    int answer = 0, aeiou[5];
    string temp = "";
    set<string> dictionary; //만든 단어를 넣어줄 set
    //aeiou의 값 0 -> 비어있음, 1->A, 2->E, 3->I, 4->O, 5->U를 의미
    for (aeiou[0] = 1; aeiou[0] <= 5; aeiou[0]++) {
        for (aeiou[1] = 0; aeiou[1] <= 5; aeiou[1]++) {
            for (aeiou[2] = 0; aeiou[2] <= 5; aeiou[2]++) {
                for (aeiou[3] = 0; aeiou[3] <= 5; aeiou[3]++) {
                    for (aeiou[4] = 0; aeiou[4] <= 5; aeiou[4]++) {
                        temp = "";
                        //aeiou의 값이 정해지면 단어를 만들고 사전에 넣어준다
                        Make_word(temp, aeiou);
                        dictionary.insert(temp);
                    }
                }
            }
        }
    }
    //set을 순회하며 입력 word와 같은 값 나오면 종료
    for (set<string>::iterator itr = dictionary.begin(); itr != dictionary.end(); itr++) {
        answer++;
        if (*itr == word)    break;
    }
    return answer;
}
//aeiou를 살피며 0이 아니라면 해당하는 문자를 넣어주고 0이라면 종료
void Make_word(string& str, int aeiou[5]) {
    for (int a = 0; a < 5; a++) {
        if (aeiou[a] == 0)   return;
        else if (aeiou[a] == 1)  str.push_back('A');
        else if (aeiou[a] == 2)  str.push_back('E');
        else if (aeiou[a] == 3)  str.push_back('I');
        else if (aeiou[a] == 4)  str.push_back('O');
        else if (aeiou[a] == 5)  str.push_back('U');
    }
}