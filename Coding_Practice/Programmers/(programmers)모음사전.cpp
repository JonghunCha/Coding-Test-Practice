/*
���� ��ũ : https://programmers.co.kr/learn/courses/30/lessons/84512
�ܼ��� ���� �����̴�.

�ߺ��� �����ϸ� �ڵ����� ������ �Ǿ� ����Ǵ� set�� ����ϸ� �����ذ��� �� �ִ�.
*/
#include <string>
#include <vector>
#include <set>

using namespace std;

int solution(string word) {
    int answer = 0, aeiou[5];
    string temp = "";
    set<string> dictionary; //���� �ܾ �־��� set
    //aeiou�� �� 0 -> �������, 1->A, 2->E, 3->I, 4->O, 5->U�� �ǹ�
    for (aeiou[0] = 1; aeiou[0] <= 5; aeiou[0]++) {
        for (aeiou[1] = 0; aeiou[1] <= 5; aeiou[1]++) {
            for (aeiou[2] = 0; aeiou[2] <= 5; aeiou[2]++) {
                for (aeiou[3] = 0; aeiou[3] <= 5; aeiou[3]++) {
                    for (aeiou[4] = 0; aeiou[4] <= 5; aeiou[4]++) {
                        temp = "";
                        //aeiou�� ���� �������� �ܾ ����� ������ �־��ش�
                        Make_word(temp, aeiou);
                        dictionary.insert(temp);
                    }
                }
            }
        }
    }
    //set�� ��ȸ�ϸ� �Է� word�� ���� �� ������ ����
    for (set<string>::iterator itr = dictionary.begin(); itr != dictionary.end(); itr++) {
        answer++;
        if (*itr == word)    break;
    }
    return answer;
}
//aeiou�� ���Ǹ� 0�� �ƴ϶�� �ش��ϴ� ���ڸ� �־��ְ� 0�̶�� ����
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