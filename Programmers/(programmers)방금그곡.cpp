/*
���� ��ũ : https://programmers.co.kr/learn/courses/30/lessons/17683
���� Ž�� ������.

�� �뷡�� ����� �ð����� �׿��� ����ϴ� ��ε� ���ԵǴ��� ������ Ž���ϸ� ���� ������ ���� �� �ִ�.

���� #�� �ٴ� ��츦 ó���ϱ� ���� ���� �ϳ��� ���ĺ����� ��ȯ�� �־���.
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
        //���� �ð� �� ������ ���
        start += (int)(musicinfos[a][0] - '0') * 600;
        start += (int)(musicinfos[a][1] - '0') * 60;
        start += (int)(musicinfos[a][3] - '0') * 10;
        start += (int)(musicinfos[a][4] - '0');
        //���� �ð� �� ������ ���
        end += (int)(musicinfos[a][6] - '0') * 600;
        end += (int)(musicinfos[a][7] - '0') * 60;
        end += (int)(musicinfos[a][9] - '0') * 10;
        end += (int)(musicinfos[a][10] - '0');
        //���� ����� ���� ����
        is_title = true;
        for (int b = 12; b < musicinfos[a].size(); b++) {
            if (musicinfos[a][b] == ',')    is_title = false;
            else if (is_title)   title.push_back(musicinfos[a][b]);
            else    info.push_back(musicinfos[a][b]);
        }
        //���Ǹ� ���� ���� ���� 12���� a ~ l�� ���ĺ����� �ٲپ� �ش�
        convert_to_alphabet(m, new_m);
        convert_to_alphabet(info, new_info);
        //������ ����� �뷡�� ��ü �κ� ���
        played_song.clear();
        index = 0;
        for (int b = 0; b < end - start; b++) {
            played_song.push_back(new_info[index]);
            index++;
            index = index % new_info.size();
        }
        //����� ��ε��� ���̺��� ����� ������ ���̰� ª�ٸ� ������ �� �� ����
        if (played_song.size() < new_m.size())   continue;  
        //������ ����� �뷡�� �Ϻο� ����� ��ε� �ִ��� Ȯ���ϰ� ������ ����
        for (int b = 0; b <= played_song.size() - new_m.size(); b++) {
            if (played_song.compare(b, new_m.size(), new_m) == 0) {
                if (end - start > answer_play_time) {   //������ ��� �ð��� ���� �� ������ ����
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
//m�� ����ִ� ���� new_m�� �ܼ� ���ĺ����� ��ȯ�Ͽ� ����
void convert_to_alphabet(string& m, string& new_m) {
    new_m.clear();
    for (int a = 0; a < m.size();) {
        if (a + 1 != m.size() && m[a + 1] == '#') { //�ڿ� #�� �޸� ���
            if (m[a] == 'C') new_m.push_back('b');
            else if (m[a] == 'D')    new_m.push_back('d');
            else if (m[a] == 'F')    new_m.push_back('g');
            else if (m[a] == 'G')    new_m.push_back('i');
            else if (m[a] == 'A')    new_m.push_back('k');
            a += 2;
        }
        else {  //#�� �ȴ޸� ���
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