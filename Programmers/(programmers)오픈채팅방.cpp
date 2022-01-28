/*
문제 링크 : https://programmers.co.kr/learn/courses/30/lessons/42888
key-value값을 이용한 문제다(map을 이용한 문제)

key값으론 유저 아이디를, value값으론 닉네임을 사용한다.

닉네임이 바뀌는 경우는 Enter로 방에 들어오거나 Change로 닉네임을 바꿀 때만 일어난다.

따라서 모든 record를 살피며 닉네임이 바뀌는 경우 해당하는 key-value값을 계속하여 갱신한다.

그런 다음 다시 한 번 모든 record들에 대해 최신 닉네임을 적용하여 answer를 반환하면 된다.
*/
#include <string>
#include <iostream>
#include <vector>
#include <map>
using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    map<string, string> m;
    string id, name;
    bool is_id;
    //record들을 살피며 닉네임 변경을 갱신
    for (int a = 0; a < record.size(); a++) {
        if (record[a].substr(0, 5) == "Enter") {    //채팅방에 들어올 때 닉네임 확인
            id.clear();
            name.clear();
            is_id = true;
            for (int b = 6; b < record[a].size(); b++) {
                if (record[a][b] == ' ') {
                    is_id = false;
                    continue;
                }
                if (is_id)   id.push_back(record[a][b]);
                else    name.push_back(record[a][b]);
            }

            m[id] = name;
        }
        else if (record[a].substr(0, 6) == "Change") {  //채팅방 내에서 닉네임을 변경한 경우
            id.clear();
            name.clear();
            is_id = true;
            for (int b = 7; b < record[a].size(); b++) {
                if (record[a][b] == ' ') {
                    is_id = false;
                    continue;
                }
                if (is_id)   id.push_back(record[a][b]);
                else    name.push_back(record[a][b]);
            }

            m[id] = name;
        }
    }
    //모든 record들에 대해 최근의 닉네임을 적용한 answer 반환
    for (int a = 0; a < record.size(); a++) {
        if (record[a].substr(0, 5) == "Enter" || record[a].substr(0, 5) == "Leave") {
            id.clear();
            for (int b = 6; b < record[a].size(); b++) {
                if (record[a][b] != ' ') id.push_back(record[a][b]);
                else    break;
            }

            if (record[a].substr(0, 5) == "Enter")   answer.push_back(m[id] + "님이 들어왔습니다.");
            else    answer.push_back(m[id] + "님이 나갔습니다.");
        }
    }


    return answer;
}