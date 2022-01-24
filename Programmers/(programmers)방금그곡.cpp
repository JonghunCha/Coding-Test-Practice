/*
문제 링크 : https://programmers.co.kr/learn/courses/30/lessons/17683
완전 탐색 문제다.

각 노래가 재생된 시간동안 네오가 기억하는 멜로디가 포함되는지 일일히 탐색하면 쉽게 정답을 구할 수 있다.

음에 #이 붙는 경우를 처리하기 위해 음을 하나의 알파벳으로 변환해 주었다.
*/
#include <string>
#include <vector>
#include <iostream>
using namespace std;

void convert_to_alphabet(string& m, string& new_m);

string solution(string m, vector<string> musicinfos) {
    int start, end, answer_play_time = 0, index;
    string title, info, new_m, new_info, played_song;
    string answer = "";
    bool is_title;

    for (int a = 0; a < musicinfos.size(); a++) {
        start = 0;
        end = 0;
        title.clear();
        info.clear();
        //시작 시간 분 단위로 계산
        start += (int)(musicinfos[a][0] - '0') * 600;
        start += (int)(musicinfos[a][1] - '0') * 60;
        start += (int)(musicinfos[a][3] - '0') * 10;
        start += (int)(musicinfos[a][4] - '0');
        //끝난 시간 분 단위로 계산
        end += (int)(musicinfos[a][6] - '0') * 600;
        end += (int)(musicinfos[a][7] - '0') * 60;
        end += (int)(musicinfos[a][9] - '0') * 10;
        end += (int)(musicinfos[a][10] - '0');
        //음악 제목과 정보 추출
        is_title = true;
        for (int b = 12; b < musicinfos[a].size(); b++) {
            if (musicinfos[a][b] == ',')    is_title = false;
            else if (is_title)   title.push_back(musicinfos[a][b]);
            else    info.push_back(musicinfos[a][b]);
        }
        //편의를 위해 음의 종류 12개를 a ~ l의 알파벳으로 바꾸어 준다
        convert_to_alphabet(m, new_m);
        convert_to_alphabet(info, new_info);
        //실제로 재생된 노래의 전체 부분 계산
        played_song.clear();
        index = 0;
        for (int b = 0; b < end - start; b++) {
            played_song.push_back(new_info[index]);
            index++;
            index = index % new_info.size();
        }
        //기억한 멜로디의 길이보다 재생된 음악의 길이가 짧다면 정답이 될 수 없음
        if (played_song.size() < new_m.size())   continue;  
        //실제로 재생된 노래의 일부에 기억한 멜로디가 있는지 확인하고 정답을 갱신
        for (int b = 0; b <= played_song.size() - new_m.size(); b++) {
            if (played_song.compare(b, new_m.size(), new_m) == 0) {
                if (end - start > answer_play_time) {   //정답을 재생 시간이 가장 긴 것으로 갱신
                    answer_play_time = end - start;
                    answer = title;
                    break;
                }
            }
        }
    }
    if (answer.size() == 0)  answer = "(None)"; 
    return answer;
}
//m에 들어있는 음을 new_m에 단순 알파벳으로 변환하여 저장
void convert_to_alphabet(string& m, string& new_m) {
    new_m.clear();
    for (int a = 0; a < m.size();) {
        if (a + 1 != m.size() && m[a + 1] == '#') { //뒤에 #이 달린 경우
            if (m[a] == 'C') new_m.push_back('b');
            else if (m[a] == 'D')    new_m.push_back('d');
            else if (m[a] == 'F')    new_m.push_back('g');
            else if (m[a] == 'G')    new_m.push_back('i');
            else if (m[a] == 'A')    new_m.push_back('k');
            a += 2;
        }
        else {  //#이 안달린 경우
            if (m[a] == 'C') new_m.push_back('a');
            else if (m[a] == 'D')    new_m.push_back('c');
            else if (m[a] == 'E')    new_m.push_back('e');
            else if (m[a] == 'F')    new_m.push_back('f');
            else if (m[a] == 'G')    new_m.push_back('h');
            else if (m[a] == 'A')    new_m.push_back('j');
            else if (m[a] == 'B')    new_m.push_back('l');
            a++;
        }
    }
}