/*
���� ��ũ : https://leetcode.com/problems/longest-substring-without-repeating-characters/
sliding window�� ���� �ذ��� �� �ִ� ������.

�켱 ���ڿ��� ó������ Ž���ϸ� �ߺ��� ������ �����ϸ� unordered_set�� substring�� �ִ´�.

���� ���ο� ���ڰ� ������ substring�� ���� ���ڸ� unordered_set�� �߰��ϰ� ���� �� ������ ���ϰ� answer�� �����Ѵ�.

���ο� ���ڰ� ������ substring�� �����ϴ� ���ڸ� �ش� ���ڰ� ����� ������ left�� �����ָ� set���� �����ָ� �ȴ�.
*/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0, right = 0, answer = 0, len = s.size();
        unordered_set<char> _set;
        //left�� right�� s�� �����ȿ� �ִ� ���� �Ʒ� �ݺ�
        while (left < len && right < len) {
            //right�� ��ġ�� ���ڰ� _set�� �������� �ʴ� ������ ��� �ش� ���ڸ� _set�� �ְ� right�� 1�����ش�
            if (_set.find(s[right]) == _set.end()) {
                _set.insert(s[right++]);
                answer = max(answer, right - left);
            }
            //right�� ��ġ�� ���ڰ� �̹� _set�� �����ϸ� �ش� ���ڰ� ����� �� ���� left�� ����������.
            else {
                _set.erase(s[left++]);
            }
        }
        return answer;
    }
};