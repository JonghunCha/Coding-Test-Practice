/*
문제 링크 : https://programmers.co.kr/learn/courses/30/lessons/17685
정렬을 이용하여 해결한 문제다.

각 단어별로 (다른 단어와 접두어가 겹치는 가장 긴 길이 + 1)만큼의 단어를 쳐야 자동완성이 된다.

이를 위해 접두어가 가장 길게 겹치는 단어를 찾는 것이 중요한데, 이를 정렬을 통해 해결하였다.

"word"라는 단어가 있을 때, word와 접두어가 가장 길게 겹치는 단어는 word의 앞 뒤에 배치되게 된다.

따라서 단어들을 서로 일일히 비교할 필요 없이 각 단어별로 2번의 비교만으로 정답을 계산할 수 있다.

***다른 풀이를 보니 Trie자료구조를 사용하여 풀었는데, 이를 이용하는 것도 좋은 방법이라 생각한다
*/
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int compare(string& str, string& prev, string& next);

int solution(vector<string> words) {
    int answer = 0, n = words.size();
    string empty_str = "";
    //words를 사전순으로 정렬
    sort(words.begin(), words.end());
    //각 단어별 자동완성을 위한 입력 수 계산
    for (int a = 0; a < n; a++) {
        if (a == 0)  answer += compare(words[a], empty_str, words[a + 1]);
        else if (a == n - 1) answer += compare(words[a], words[a - 1], empty_str);
        else    answer += compare(words[a], words[a - 1], words[a + 1]);
    }

    return answer;
}

int compare(string& str, string& prev, string& next) {
    int compare_prev = 0, compare_next = 0;
    //앞의 단어와 몇 개의 글자가 겹치는지 확인
    if (prev != "") {
        for (int a = 0; a < str.size(); a++) {
            //만약 앞 단어보다 크기가 커지는 순간이거나, 서로 다른 문자인 경우 해당 시점에서 자동완성 가능
            if (a >= prev.size() || str[a] != prev[a]) {
                compare_prev = a + 1;
                break;
            }
        }

        if (compare_prev == 0)   compare_prev = str.size();
    }
    //뒤의 단어와 몇 개의 글자가 겹치는지 확인
    if (next != "") {
        for (int a = 0; a < str.size(); a++) {
            if (a >= next.size() || str[a] != next[a]) {
                compare_next = a + 1;
                break;
            }
        }

        if (compare_next == 0)   compare_next = str.size();
    }
    //둘 중 더 큰 값을 반환
    return max(compare_prev, compare_next);
}