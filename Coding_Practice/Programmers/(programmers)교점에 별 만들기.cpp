/*
���� ��ũ : https://programmers.co.kr/learn/courses/30/lessons/87377
�ܼ��� ���� Ž�� ������.

x�� y��ǥ�� ���� ���ϴ� ����� ������ ���õǾ� ������ �ܼ��� ��길 �ϸ� �ȴ�.(���⼭ int���� �Ѿ �� �ֱ⿡ long long���� ��ȯ)

���� ��ǥ�� ������ ��� ������ �� x, y��ǥ�� �ּ� �ִ밪�� ���Ѵ�.

x��ǥ�� �ּ� �ִ��� ���� answer�� ���� ���̰� �ǰ�, y��ǥ�� �ּ� �ִ��� ���� answer�� ���� ���̰� �ȴ�.

���������� ������ ��ǥ�� y�� �ִ밪, x�� �ּҰ��� �̿��Ͽ� answer�� ���� �־��ָ� �ȴ�.
*/
#include <string>
#include <vector>
#include <utility>
using namespace std;

vector<string> solution(vector<vector<int>> line) {
    vector<string> answer;
    vector<pair<int, int>> stars;
    long long x1, y1, div;
    //���� �ٸ� �� �������� ��ǥ�� �� �� ������ ������ �ִٸ� stars�� �߰�
    for (int a = 0; a < line.size(); a++) {
        for (int b = a + 1; b < line.size(); b++) {
            x1 = ((long long)line[a][1] * (long long)line[b][2]) - ((long long)line[a][2] * (long long)line[b][1]);
            y1 = ((long long)line[a][2] * (long long)line[b][0]) - ((long long)line[a][0] * (long long)line[b][2]);
            div = ((long long)line[a][0] * (long long)line[b][1]) - ((long long)line[a][1] * (long long)line[b][0]);
            //�� ������ �ϳ��� ������ ������, x�� y��ǥ�� ������ ���
            if (div != 0 && x1 % div == 0 && y1 % div == 0) {   
                stars.push_back(make_pair(x1 / div, y1 / div));
            }
        }
    }
   
    int x_max = stars[0].first, x_min = stars[0].first, y_max = stars[0].second, y_min = stars[0].second;
    int width, height;
    string temp;
    //x�� �ִ� �ּҰ�, y�� �ִ� �ּҰ��� ���� width�� height�� ���
    for (int a = 1; a < stars.size(); a++) {
        if (stars[a].first < x_min)  x_min = stars[a].first;
        if (stars[a].first > x_max)  x_max = stars[a].first;
        if (stars[a].second < y_min) y_min = stars[a].second;
        if (stars[a].second > y_max) y_max = stars[a].second;
    }
    width = x_max - x_min + 1;
    height = y_max - y_min + 1;
    //���� ���� ���̿� ���� answer�� ũ�� ����
    for (long long a = 0; a < width; a++)  temp.push_back('.');
    for (long long a = 0; a < height; a++) answer.push_back(temp);
    //answer�� ���� ��ġ ����
    for (int a = 0; a < stars.size(); a++) {
        answer[y_max - stars[a].second][stars[a].first - x_min] = '*';
    }

    return answer;
}