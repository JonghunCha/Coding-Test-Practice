/*
문제 링크 : https://leetcode.com/problems/backspace-string-compare/
Two Pointers 알고리즘으로 해결할 수 있는 문제다.

두 개의 문자열을 뒤에서부터 탐색해 나가며 서로 비교하면 된다.

findCandidate함수는 각 문자열에서 backspace에 의해 지워지지 않는 문자열을 반환하도록 한다. 만약 그러한 문자가 없다면 '0'을 반환한다.

이렇게 살아남는 문자를 서로의 문자열 끝까지 비교하였을 때 모두 같다면 같은 문자열이 된다고 볼 수 있다.
*/
class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int s_backspace = 0, t_backspace = 0, s_index = s.size() - 1, t_index = t.size() - 1;
        while (s_index >= 0 && t_index >= 0) {  //둘 중 하나의 문자열의 탐색이 끝나면 종료
            if (findCandidate(s, s_backspace, s_index) != findCandidate(t, t_backspace, t_index))    return false;
        }
        //하나의 문자열은 탐색할 부분이 남았을 수도 있다. 남은 문자열에서 살아남는 문자가 있다면 서로 같지 않고, 그 반대의 경우는 같은 문자열이 된다.
        if (findCandidate(s, s_backspace, s_index) == findCandidate(t, t_backspace, t_index))  return true;
        else    return false;
    }

    char findCandidate(string str, int& backspace_num, int& index) {
        while (index >= 0) {
            if (str[index] == '#') {    //'#'이 보이면 backspace_num을 1더해주고 탐색을 진행
                backspace_num++;
                index--;
            }
            else {  //알파벳 문자가 나온 경우
                if (backspace_num > 0) {    //backspace_num이 0보다 크면 어차피 지워질 문자이니 탐색 진행    
                    backspace_num--;
                    index--;
                }
                else {  //현재 탐색중인 문자는 살아남는 문자이다
                    return str[index--];
                }
            }
        }
        return '0'; //살아남는 문자가 없는 경우 '0' 반환
    }
};