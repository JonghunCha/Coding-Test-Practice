/*
���� ��ũ : https://leetcode.com/problems/letter-combinations-of-a-phone-number/
����Լ��� �ذ��� �� �ִ� ������.

�Է��� ���ڿ� ���� ��� ������ ���� Ž���� ���� ���ϸ� �ȴ�.

���� ������ �ڵ常 ���� ������ �� ���� ���̴�.
*/
class Solution {
public:
    string letters[10] = { "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };

    vector<string> letterCombinations(string digits) {
        vector<string> answer;
        string str;

        if (digits.size() == 0)  return answer;
        Get_Answer(digits, answer, str, 0);

        return answer;
    }

    void Get_Answer(string& digits, vector<string>& answer, string& str, int index) {
        if (digits.size() == index) {
            answer.push_back(str);
            return;
        }

        string candidate = letters[digits[index] - '0'];
        for (int a = 0; a < candidate.size(); a++) {
            str.push_back(candidate[a]);
            Get_Answer(digits, answer, str, index + 1);
            str.pop_back();
        }

    }
};