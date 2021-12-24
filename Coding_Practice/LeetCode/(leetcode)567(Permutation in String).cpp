/*
문제 링크 : https://leetcode.com/problems/permutation-in-string/
Sliding Window로 해결할 수 있는 문제다.

s2에서 s1의 길이 만큼의 문자열이 s1의 permutation인지 확인하면 된다.

문제는 s1의 permutation을 어떻게 생각할 것인가인데, 이는 단순히 s1의 길이만큼의 문자열에 각 문자가 몇 번씩 등장했느냐로 빠르게 해결할 수 있다.

만약 모든 permutation을 만들고 그것과 일치하는 것이 있는지를 비교하면 훨씬 더 많은 시간이 걸릴 것이다.
*/
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int count1[26], count2[26], len = s1.size(), right = len;
        bool answer;
        //s1의 길이가 더 긴 경우 false 반환
        if (s1.size() > s2.size())   return false;
        for (int a = 0; a < 26; a++) {
            count1[a] = 0;
            count2[a] = 0;
        }
        //초기 count1과 count2 설정
        for (int a = 0; a < s1.size(); a++) {
            count1[s1[a] - 'a']++;
            count2[s2[a] - 'a']++;
        }
        //현재 보고있는 window의 바로 다음 index가 right이다.
        while (right <= s2.size()) {
            answer = true;
            for (int a = 0; a < 26; a++) {
                //만약 count1과 count2가 다르다면 현재 window는 s1의 permutation이 아니다.
                if (count1[a] != count2[a]) {
                    if (right == s2.size())  return false;  //다음 window가 없는 경우 false 반환
                    count2[s2[right - len] - 'a']--;    //윈도우의 가장 왼쪽을 빼고
                    count2[s2[right++] - 'a']++;        //오른쪽 하나를 추가
                    answer = false;
                    break;
                }
            }
            if (answer)  return answer;
        }
        return false;
    }
};