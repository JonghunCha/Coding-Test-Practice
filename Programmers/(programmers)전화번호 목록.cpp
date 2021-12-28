/*
문제 링크 : https://programmers.co.kr/learn/courses/30/lessons/42577
백준온라인의 5052(전화번호 목록)과 같은 문제다. 

당시에는 정렬로 풀었었다.

그러나 프로그래머스에서는 해쉬 문제라 되어 있다. 

따라서 해쉬로 푼 버젼과 정렬로 푼 버젼 두가지를 제시하겠다.
*/

//정렬로 푼 코드
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;

    sort(phone_book.begin(), phone_book.end());
    //정렬을 하고나면 a가 다른 번호의 접두어라면 항상 a+1의 접두어야만 한다는 점을 이용하였다.
    for (int a = 0; a < phone_book.size() - 1; a++) {
        if (phone_book[a].compare(phone_book[a + 1].substr(0, phone_book[a].size())) == 0)    return false;
    }

    return answer;
}

//해쉬로 푼 코드
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;

    unordered_map<string, int> hash_map;
    string temp;
    //해쉬에 모든 번호를 저장
    for (int a = 0; a < phone_book.size(); a++) {
        hash_map[phone_book[a]] = 1;
    }
    //모든 번호에 대해 접두어 번호가 존재하는지 확인
    for (int a = 0; a < phone_book.size(); a++) {
        temp = "";
        //phone_book[a]의 앞에서부터 하나씩 추가하며, 해당 번호가 hash에 존재하는지 확인한다
        for (int b = 0; b < phone_book[a].size() - 1; b++) {
            temp += phone_book[a][b];
            if (hash_map.find(temp) != hash_map.end())   return false;
        }
    }

    return answer;
}