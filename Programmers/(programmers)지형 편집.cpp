/*
���� ��ũ : https://programmers.co.kr/learn/courses/30/lessons/12984
�̺� Ž������ �ذ��ؾ��ϴ� ������.

�� ĭ�� ���� �� �ִ� ����� ���� 0 �̻� 10�� ������ �����̱⿡, ������ Ž���ϴ� ���� �ð��ʰ��� �ɸ���.

������ Ư���� ���信 ����������� ��뵵 �پ���.(���信 �������� �װ� �����ϴ� �Ϳ� ���� ����� �پ��� ����)

���� �ּҺ���� 0 ~ 10�� ������ �̺� Ž������ ã�� �� �ִ�.
*/
#include <vector>
#include <algorithm>
using namespace std;

long long getCost(vector<vector<int>>& land, int P, int Q, int height);

long long solution(vector<vector<int>> land, int P, int Q) {
    long long answer = 9000000000000000, val1, val2;
    int low = 0, high = 1000000000, mid;
    //�ּ� ��� Ž��
    while (low < high) {
        mid = (low + high) / 2;

        val1 = getCost(land, P, Q, mid);
        val2 = getCost(land, P, Q, mid + 1);

        if (val1 < val2) {  //val1�� val2���� �۴ٴ� ���� ������ low ~ val1���̿� ������ �ǹ�
            high = mid;
            answer = min(answer, val1);
        }
        else {  //val1�� val2���� ũ�ų� ���ٴ� ���� ������ val2 ~ high���̿� ������ �ǹ�
            low = mid + 1;
            answer = min(answer, val2);
        }
    }

    return answer;
}
//height�� ���� �װ� �����ϴµ� ��� ����� ��ȯ�ϴ� �Լ�
long long getCost(vector<vector<int>>& land, int P, int Q, int height) {
    long long ret = 0;

    for (int a = 0; a < land.size(); a++) {
        for (int b = 0; b < land.size(); b++) {
            if (land[a][b] > height) {
                ret += ((long long)land[a][b] - (long long)height) * (long long)Q;
            }
            else if (land[a][b] < height) {
                ret += ((long long)height - (long long)land[a][b]) * (long long)P;
            }
        }
    }

    return ret;
}