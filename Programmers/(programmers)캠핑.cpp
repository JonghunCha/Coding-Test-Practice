/*
���� ��ũ : https://programmers.co.kr/learn/courses/30/lessons/1833#
������ �ϸ� �ذ���� ���� �������� ������.

(a, b)����� (a + 2, b + 2)�� ������ ��Ʈ�� ������ ��������.

�� ��� x��ǥ�� a + 2���� ū ��� y ��ǥ�� b + 2���� ũ�� �ȵȴ�.((a + 2, b + 2)�� ���ο� ���� ����)

�� ���� �̿��Ͽ� 2�� ������ ���� Ž���ϸ� y��ǥ�� ���� ������ ������ �ƴ��� �Ǵ��� �� �ִ�.
*/
#include <vector>
#include <algorithm>
#include <iostream>
#include <climits>
using namespace std;

bool compare(vector<int> v1, vector<int> v2);

int solution(int n, vector<vector<int>> data) {
    int answer = 0, line_above, line_below, line_above_temp, line_below_temp;

    sort(data.begin(), data.end());

    for (int a = 0; a < (n - 1); a++) {
        line_above = INT_MAX;
        line_below = 0;
        line_above_temp = INT_MAX;
        line_below_temp = 0;
        for (int b = a + 1; b < n; b++) {
            if (data[b][0] == data[a][0]) { //x��ǥ�� ���� ��� ����
                continue;
            }
            
            if (data[b][1] > data[a][1] && data[b][1] <= line_above) {  //b�� ���Ⱑ a�� ���⺸�� ���� �ְ� ��Ʈ�� ��ġ�� �� �ִ� ���
                answer++;
                line_above_temp = min(line_above_temp, data[b][1]);
            }
            else if (data[b][1] < data[a][1] && data[b][1] >= line_below) { //b�� ���Ⱑ a�� ���⺸�� �Ʒ��� �ְ� ��Ʈ�� ��ġ�� �� �ִ� ���
                answer++;
                line_below_temp = max(line_below_temp, data[b][1]);
            }
            //���� ���� ������ x��ǥ�� ���� ��� line_above �� line_below�� �����ϸ� �ȵȴ�
            //x��ǥ�� ���� ��� ��Ʈ�� ��ġ�ص� ��輱�� ���Ⱑ ���� ����̱⿡ ������ ��Ʈ ��ġ ���ǿ� �����ϱ� ����
            if (b + 1 < n && data[b + 1][0] > data[b][0]) {
                line_above = line_above_temp;
                line_below = line_below_temp;
            }
        }
    }

    return answer;
}