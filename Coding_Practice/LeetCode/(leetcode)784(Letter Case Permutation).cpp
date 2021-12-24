/*
문제 링크 : https://leetcode.com/problems/letter-case-permutation/
DFS로 해결할 수 있는 문제다.

문자열을 처음부터 살피며 숫자면 그냥 넘어가고 알파벳인 경우 소문자인 경우, 대문자인 경우 2가지로 DFS로 탐색해 나가면 된다.
*/
class Solution {
public:
    vector<string> letterCasePermutation(string s) {
        vector<string> answer;
        string new_s;
        Get_Answer(answer, s, new_s, 0);
        return answer;
    }

    void Get_Answer(vector<string>& answer, string s, string new_s, int index) {
        if (s.size() == new_s.size()) { //s전체를 다 탐색했으면 answer에 넣는다
            answer.push_back(new_s);
            return;
        }
        //소문자인 경우
        if (s[index] >= 'a' && s[index] <= 'z') {
            new_s.push_back(s[index]);
            Get_Answer(answer, s, new_s, index + 1);
            new_s.pop_back();
            new_s.push_back(s[index] - 32);
            Get_Answer(answer, s, new_s, index + 1);
            new_s.pop_back();
        }
        //대문자인 경우
        else if (s[index] >= 'A' && s[index] <= 'Z') {
            new_s.push_back(s[index]);
            Get_Answer(answer, s, new_s, index + 1);
            new_s.pop_back();
            new_s.push_back(s[index] + 32);
            Get_Answer(answer, s, new_s, index + 1);
            new_s.pop_back();
        }
        //숫자인 경우
        else {
            new_s.push_back(s[index]);
            Get_Answer(answer, s, new_s, index + 1);
            new_s.pop_back();
        }
        return;
    }
};