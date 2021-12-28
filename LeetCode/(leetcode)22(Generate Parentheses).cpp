/*
���� ��ũ : https://leetcode.com/problems/generate-parentheses/
��� �Լ��� ���� ������ ������ �� �ִ�.

well-formed parentheses�� �Ʒ��� ������ �����ϸ� �ȴ�.

1. �׻� ������ '(', ���� ')'�̾�� �Ѵ�.
2. n��° index���� ���ٰ� �� ��, �׻� '('�� ������ ')'�� ������ ���ų� Ŀ���Ѵ�.
3. ��ü '('�� ')'�� ���� n���� ���ƾ� �Ѵ�.

�� ������ �����ϵ��� ����Լ��� �����ϸ� �Ʒ��� ����.
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
        if (str.size() == 0) {  //������ �׻� '('
            str.push_back('(');
            Get_Answer(answer, str, n, num1 + 1, num2);
            str.pop_back();
        }
        else if (str.size() == 2 * n - 1) { //�������� �׻� ')'
            str.push_back(')');
            Get_Answer(answer, str, n, num1, num2 + 1);
            str.pop_back();
        }
        else if (str.size() == 2 * n) { //parentheses�� �ϼ� �� ���
            answer.push_back(str);
        }
        else {  
            if (num1 < n) { //'('�� ���� �� ��
                str.push_back('(');
                Get_Answer(answer, str, n, num1 + 1, num2);
                str.pop_back();
            }
            if (num1 > num2) {  //')'�� ���� �� ��
                str.push_back(')');
                Get_Answer(answer, str, n, num1, num2 + 1);
                str.pop_back();
            }
        }
    }
};