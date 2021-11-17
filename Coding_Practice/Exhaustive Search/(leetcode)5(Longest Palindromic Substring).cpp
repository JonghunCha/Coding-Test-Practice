/*
문제 링크 : https://leetcode.com/problems/longest-palindromic-substring/
완전 탐색으로 해결할 수 있다.(실제로는 가장 큰 길이만 필요하기에, 현재까지 구한 값보다 작을 수 밖에 없는 경우는 탐색을 하지 않음)

int dp[n]은 n번째 인덱스부터 시작한 palindromic의 최대 길이를 저장한다.

이중 for문을 이용해서 바깥쪽 for문은 palindromic후보의 왼쪽 끝, 안쪽 for문은 오른쪽 끝의 인덱스로 지정한다.

palindromic이 되려면 왼쪽 끝과 오른쪽 끝은 항상 같아야 한다.

따라서 이중 for문에서 왼쪽 끝과 오른쪽 끝이 같다면 나머지 부분이 palindromic인지 확인을 하면 된다.
*/
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size(), max = 0, target = 0;

        for (int a = 0; a < n - max; a++) { //현재까지 구한 max보다 더 긴 경우가 나오지 않는 경우 탐색할 필요가 없다
            for (int b = n - 1; b >= a; b--) {  //가장 긴 것을 구하기 위해 뒤에서부터 탐색
                if (s[a] == s[b] && check_palindromic(s, a, b)) {   //왼쪽 끝과 오른쪽 끝이 같고 palindromic인 경우
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
    //왼쪽 끝과 오른쪽 끝이 지정되었을 때 해당 substring이 palindromic인지 판별
    bool check_palindromic(string& s, int left, int right) {
        while (left <= right) {
            if (s[left++] != s[right--]) return false;
        }
        return true;
    }
};