/*
문제 링크 : https://programmers.co.kr/learn/courses/30/lessons/60060
이진 탐색으로 해결할 수 있는 문제다.

가사 단어와 검색 키워드가 각각 최대 100,000이기에 완전 탐색은 시간 초과에 걸린다.

따라서 가사를 단어 길이 오름차순으로, 길이가 같다면 사전순으로 정렬을 한다.

그런 다음 검색 키워드 각각에 대해 해당 키워드와 매칭되는 단어들 중 가장 앞에 위치한 것의 인덱스, 가장 뒤에 위치한 것의 인덱스를 구한다.

우리가 알고자하는 키워드와 매칭되는 단어의 갯수는 위에서 구한 가장 뒤의 인덱스 - 앞의 인덱스가 된다.

또한, 키워드에서 ?가 접두사로 오는 경우를 처리하기 위해 words_reverse버전을 만들어 주었다.

이 정도 아이디어를 인지하고 아래 코드를 보면 쉽게 이해가 갈 것이다.
*/
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
//단어를 길이의 오름차순, 길이가 같다면 사전순으로 오도록 하는 함수
bool compare(string s1, string s2) {
    if (s1.size() == s2.size()) {
        return s1 < s2;
    }
    return s1.size() < s2.size();
}

vector<int> solution(vector<string> words, vector<string> queries) {
    vector<int> answer;
    vector<string> words_reverse;
    string str_temp, q;
    int left, right, middle, index_left, index_right;
    //words의 reverse버전 생성
    for (int a = 0; a < words.size(); a++) {
        str_temp.clear();
        for (int b = words[a].size() - 1; b >= 0; b--)   str_temp.push_back(words[a][b]);
        words_reverse.push_back(str_temp);
    }
    //단어들을 정렬
    sort(words.begin(), words.end(), compare);
    sort(words_reverse.begin(), words_reverse.end(), compare);
    //각 검색 키워드에 대해 매칭되는 단어의 갯수 구하기
    for (int a = 0; a < queries.size(); a++) {
        if (queries[a][0] == '?') { //words_reverse를 써야하는 경우
            q.clear();
            for (int b = queries[a].size() - 1; b >= 0; b--) q.push_back(queries[a][b]);
            //먼저 키워드와 매칭되는 단어중 가장 왼쪽에 위치한 것의 인덱스를 구한다
            left = 0;
            right = words_reverse.size() - 1;
            while (left <= right) {
                middle = (left + right) / 2;
                if (q.size() < words_reverse[middle].size()) {  //키워드의 길이가 middle의 길이보다 작은 경우
                    right = middle - 1;
                }
                else if (q.size() > words_reverse[middle].size()) { //키워드의 길이가 middle의 길이보다 큰 경우
                    left = middle + 1;
                }
                else {  //키워드의 길이와 middle의 길이가 같은 경우
                    for (int b = 0; b < q.size(); b++) {    //각 글자를 비교
                        if (q[b] == '?') {  //'?'를 만난 경우 해당 단어는 매칭이 된다. 따라서 더 왼쪽에 매칭되는 단어가 있는지 탐색
                            right = middle - 1;
                            break;
                        }
                        else {
                            if (q[b] > words_reverse[middle][b]) {  //키워드가 middle보다 사전순으로 오른쪽에 위치할 경우
                                left = middle + 1;
                                break;
                            }
                            else if (q[b] < words_reverse[middle][b]) { //키워드가 middle보다 사전순으로 왼쪽에 위치할 경우
                                right = middle - 1;
                                break;
                            }
                        }
                    }
                }
            }
            index_left = left;
            //키워드와 매칭되는 단어중 가장 오른쪽에 위치한 것의 인덱스 구하기
            left = 0;
            right = words_reverse.size() - 1;
            while (left <= right) {
                middle = (left + right) / 2;
                if (q.size() < words_reverse[middle].size()) {
                    right = middle - 1;
                }
                else if (q.size() > words_reverse[middle].size()) {
                    left = middle + 1;
                }
                else {
                    for (int b = 0; b < q.size(); b++) {    //가장 왼쪽의 것을 구하는 것과 다른 유일한 부분(왼쪽탐색 대신 오른쪽 탐색)
                        if (q[b] == '?') {
                            left = middle + 1;
                            break;
                        }
                        else {
                            if (q[b] > words_reverse[middle][b]) {
                                left = middle + 1;
                                break;
                            }
                            else if (q[b] < words_reverse[middle][b]) {
                                right = middle - 1;
                                break;
                            }
                        }
                    }
                }
            }
            index_right = left;
        }
        else {  //words를 써야하는 경우(나머지는 위와 동일한 코드)
            q.clear();
            q = queries[a];

            left = 0;
            right = words.size() - 1;
            while (left <= right) {
                middle = (left + right) / 2;
                if (q.size() < words[middle].size()) {
                    right = middle - 1;
                }
                else if (q.size() > words[middle].size()) {
                    left = middle + 1;
                }
                else {
                    for (int b = 0; b < q.size(); b++) {
                        if (q[b] == '?') {
                            right = middle - 1;
                            break;
                        }
                        else {
                            if (q[b] > words[middle][b]) {
                                left = middle + 1;
                                break;
                            }
                            else if (q[b] < words[middle][b]) {
                                right = middle - 1;
                                break;
                            }
                        }
                    }
                }
            }
            index_left = left;

            left = 0;
            right = words.size() - 1;
            while (left <= right) {
                middle = (left + right) / 2;
                if (q.size() < words[middle].size()) {
                    right = middle - 1;
                }
                else if (q.size() > words[middle].size()) {
                    left = middle + 1;
                }
                else {
                    for (int b = 0; b < q.size(); b++) {
                        if (q[b] == '?') {
                            left = middle + 1;
                            break;
                        }
                        else {
                            if (q[b] > words[middle][b]) {
                                left = middle + 1;
                                break;
                            }
                            else if (q[b] < words[middle][b]) {
                                right = middle - 1;
                                break;
                            }
                        }
                    }
                }
            }
            index_right = left;
        }

        answer.push_back(index_right - index_left);
    }

    return answer;
}