/*
문제 링크 : https://leetcode.com/problems/letter-combinations-of-a-phone-number/
재귀함수로 해결할 수 있는 문제다.

입력의 숫자에 따른 모든 조합을 완전 탐색을 통해 구하면 된다.

쉬운 문제라 코드만 보면 이해할 수 있을 것이다.
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