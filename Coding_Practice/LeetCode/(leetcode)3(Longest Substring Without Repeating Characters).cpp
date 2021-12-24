/*
문제 링크 : https://leetcode.com/problems/longest-substring-without-repeating-characters/
sliding window를 통해 해결할 수 있는 문제다.

우선 문자열을 처음부터 탐색하며 중복이 없도록 유지하며 unordered_set에 substring을 넣는다.

만약 새로운 문자가 이전의 substring에 없던 문자면 unordered_set에 추가하고 가장 긴 것인지 비교하고 answer을 갱신한다.

새로운 문자가 이전의 substring에 존재하던 문자면 해당 문자가 사라질 때까지 left를 높여주며 set에서 없애주면 된다.
*/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0, right = 0, answer = 0, len = s.size();
        unordered_set<char> _set;
        //left와 right가 s의 범위안에 있는 동안 아래 반복
        while (left < len && right < len) {
            //right에 위치한 문자가 _set에 존재하지 않던 문자인 경우 해당 문자를 _set에 넣고 right를 1높여준다
            if (_set.find(s[right]) == _set.end()) {
                _set.insert(s[right++]);
                answer = max(answer, right - left);
            }
            //right에 위치한 문자가 이미 _set에 존재하면 해당 문자가 사라질 때 까지 left를 지워나간다.
            else {
                _set.erase(s[left++]);
            }
        }
        return answer;
    }
};