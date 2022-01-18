/*
���� ��ũ : https://programmers.co.kr/learn/courses/30/lessons/17676
���ڿ� �Ľ̰� ���õ� ������.

������ �־��� �� �α׵��� ó�� ���� �ð��� ����Ϸ� �ð��� �����Ѵ�.

�� �� ���Ǹ� ���� ���� ���� ������ ms�������� ������ �Ѵ�.

�������� ������ �Ǵ� �α��� end�������� 1�� ���� ������ ������ �α׵��� ������ �����ָ鼭 ���� Ž���� �����ϸ� �ȴ�.
*/
#include <string>
#include <vector>
#include <tuple>
#include <iostream>
using namespace std;

int string_to_int(string str);

int solution(vector<string> lines) {
    int answer = 0, temp, h, m, s, ss, gaps, gapss, sum;
    vector<int> start, end;
    string str;

    for (int a = 0; a < lines.size(); a++) {
        //�α� ���ڿ��� ��, ��, ��, �и��ʿ� �ش��ϴ� ���� ����
        str = lines[a].substr(11, 100);
        h = string_to_int(str.substr(0, 2));
        m = string_to_int(str.substr(3, 2));
        s = string_to_int(str.substr(6, 2));
        ss = string_to_int(str.substr(9, 3));
        gaps = string_to_int(str.substr(13, 1));
        if (str.size() > 15) {
            gapss = string_to_int(str.substr(15, str.size() - 16));
        }
        else {
            gapss = 0;
        }
        //������ ���� �ð� ������ ms�������� ��ȯ
        sum = 0;
        sum += h * 60 * 60 * 1000;
        sum += m * 60 * 1000;
        sum += s * 1000;
        sum += ss;
        //�� �α��� �������, ���۽����� ����
        end.push_back(sum);
        start.push_back(sum - (gaps * 1000 + gapss) + 1);
    }
    //��� �α׸� �������� Ž��
    for (int a = 0; a < lines.size(); a++) {
        temp = 1;
        for (int b = a + 1; b < lines.size(); b++) {    //b�� �αװ� a�� �α׿� ��ġ���� Ȯ��
            if (end[a] + 999 >= start[b]) {
                temp++;
            }
        }

        if (temp > answer) {
            answer = temp;
        }
    }

    return answer;
}
//string�� int�� ��ȯ�ϴ� �Լ�
int string_to_int(string str) {
    int ret = 0, temp = 1;

    for (int a = str.size() - 1; a >= 0; a--) {
        ret += temp * (int)(str[a] - '0');
        temp *= 10;
    }

    return ret;
}