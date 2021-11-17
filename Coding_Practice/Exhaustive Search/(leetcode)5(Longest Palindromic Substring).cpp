/*
���� ��ũ : https://leetcode.com/problems/longest-palindromic-substring/
���� Ž������ �ذ��� �� �ִ�.(�����δ� ���� ū ���̸� �ʿ��ϱ⿡, ������� ���� ������ ���� �� �ۿ� ���� ���� Ž���� ���� ����)

int dp[n]�� n��° �ε������� ������ palindromic�� �ִ� ���̸� �����Ѵ�.

���� for���� �̿��ؼ� �ٱ��� for���� palindromic�ĺ��� ���� ��, ���� for���� ������ ���� �ε����� �����Ѵ�.

palindromic�� �Ƿ��� ���� ���� ������ ���� �׻� ���ƾ� �Ѵ�.

���� ���� for������ ���� ���� ������ ���� ���ٸ� ������ �κ��� palindromic���� Ȯ���� �ϸ� �ȴ�.
*/
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size(), max = 0, target = 0;

        for (int a = 0; a < n - max; a++) { //������� ���� max���� �� �� ��찡 ������ �ʴ� ��� Ž���� �ʿ䰡 ����
            for (int b = n - 1; b >= a; b--) {  //���� �� ���� ���ϱ� ���� �ڿ������� Ž��
                if (s[a] == s[b] && check_palindromic(s, a, b)) {   //���� ���� ������ ���� ���� palindromic�� ���
                    if (b - a + 1 > max) {
                        max = b - a + 1;
                        target = a;
                    }
                    break;
                }
            }
        }

        return s.substr(target, max);
    }
    //���� ���� ������ ���� �����Ǿ��� �� �ش� substring�� palindromic���� �Ǻ�
    bool check_palindromic(string& s, int left, int right) {
        while (left <= right) {
            if (s[left++] != s[right--]) return false;
        }
        return true;
    }
};