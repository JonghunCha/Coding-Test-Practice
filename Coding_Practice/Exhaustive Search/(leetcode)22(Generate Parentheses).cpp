/*
문제 링크 : https://leetcode.com/problems/generate-parentheses/
재귀 함수를 통해 정답을 도출할 수 있다.

well-formed parentheses는 아래의 조건을 만족하면 된다.

1. 항상 시작은 '(', 끝은 ')'이어야 한다.
2. n번째 index까지 본다고 할 때, 항상 '('의 갯수가 ')'의 갯수와 같거나 커야한다.
3. 전체 '('와 ')'의 수는 n개로 같아야 한다.

위 조건을 만족하도록 재귀함수를 구현하면 아래와 같다.
*/
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> answer;
        string str = "";

        Get_Answer(answer, str, n, 0, 0);

        return answer;
    }

    void Get_Answer(vector<string>& answer, string& str, int n, int num1, int num2) {
        if (str.size() == 0) {  //시작은 항상 '('
            str.push_back('(');
            Get_Answer(answer, str, n, num1 + 1, num2);
            str.pop_back();
        }
        else if (str.size() == 2 * n - 1) { //마지막은 항상 ')'
            str.push_back(')');
            Get_Answer(answer, str, n, num1, num2 + 1);
            str.pop_back();
        }
        else if (str.size() == 2 * n) { //parentheses가 완성 된 경우
            answer.push_back(str);
        }
        else {  
            if (num1 < n) { //'('가 들어가도 될 때
                str.push_back('(');
                Get_Answer(answer, str, n, num1 + 1, num2);
                str.pop_back();
            }
            if (num1 > num2) {  //')'가 들어가도 될 떄
                str.push_back(')');
                Get_Answer(answer, str, n, num1, num2 + 1);
                str.pop_back();
            }
        }
    }
};