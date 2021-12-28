/*
���� ��ũ : https://leetcode.com/problems/backspace-string-compare/
Two Pointers �˰������� �ذ��� �� �ִ� ������.

�� ���� ���ڿ��� �ڿ������� Ž���� ������ ���� ���ϸ� �ȴ�.

findCandidate�Լ��� �� ���ڿ����� backspace�� ���� �������� �ʴ� ���ڿ��� ��ȯ�ϵ��� �Ѵ�. ���� �׷��� ���ڰ� ���ٸ� '0'�� ��ȯ�Ѵ�.

�̷��� ��Ƴ��� ���ڸ� ������ ���ڿ� ������ ���Ͽ��� �� ��� ���ٸ� ���� ���ڿ��� �ȴٰ� �� �� �ִ�.
*/
class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int s_backspace = 0, t_backspace = 0, s_index = s.size() - 1, t_index = t.size() - 1;
        while (s_index >= 0 && t_index >= 0) {  //�� �� �ϳ��� ���ڿ��� Ž���� ������ ����
            if (findCandidate(s, s_backspace, s_index) != findCandidate(t, t_backspace, t_index))    return false;
        }
        //�ϳ��� ���ڿ��� Ž���� �κ��� ������ ���� �ִ�. ���� ���ڿ����� ��Ƴ��� ���ڰ� �ִٸ� ���� ���� �ʰ�, �� �ݴ��� ���� ���� ���ڿ��� �ȴ�.
        if (findCandidate(s, s_backspace, s_index) == findCandidate(t, t_backspace, t_index))  return true;
        else    return false;
    }

    char findCandidate(string str, int& backspace_num, int& index) {
        while (index >= 0) {
            if (str[index] == '#') {    //'#'�� ���̸� backspace_num�� 1�����ְ� Ž���� ����
                backspace_num++;
                index--;
            }
            else {  //���ĺ� ���ڰ� ���� ���
                if (backspace_num > 0) {    //backspace_num�� 0���� ũ�� ������ ������ �����̴� Ž�� ����    
                    backspace_num--;
                    index--;
                }
                else {  //���� Ž������ ���ڴ� ��Ƴ��� �����̴�
                    return str[index--];
                }
            }
        }
        return '0'; //��Ƴ��� ���ڰ� ���� ��� '0' ��ȯ
    }
};