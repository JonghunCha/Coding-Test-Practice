/*
���� ��ũ : https://leetcode.com/problems/letter-case-permutation/
DFS�� �ذ��� �� �ִ� ������.

���ڿ��� ó������ ���Ǹ� ���ڸ� �׳� �Ѿ�� ���ĺ��� ��� �ҹ����� ���, �빮���� ��� 2������ DFS�� Ž���� ������ �ȴ�.
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
        if (s.size() == new_s.size()) { //s��ü�� �� Ž�������� answer�� �ִ´�
            answer.push_back(new_s);
            return;
        }
        //�ҹ����� ���
        if (s[index] >= 'a' && s[index] <= 'z') {
            new_s.push_back(s[index]);
            Get_Answer(answer, s, new_s, index + 1);
            new_s.pop_back();
            new_s.push_back(s[index] - 32);
            Get_Answer(answer, s, new_s, index + 1);
            new_s.pop_back();
        }
        //�빮���� ���
        else if (s[index] >= 'A' && s[index] <= 'Z') {
            new_s.push_back(s[index]);
            Get_Answer(answer, s, new_s, index + 1);
            new_s.pop_back();
            new_s.push_back(s[index] + 32);
            Get_Answer(answer, s, new_s, index + 1);
            new_s.pop_back();
        }
        //������ ���
        else {
            new_s.push_back(s[index]);
            Get_Answer(answer, s, new_s, index + 1);
            new_s.pop_back();
        }
        return;
    }
};