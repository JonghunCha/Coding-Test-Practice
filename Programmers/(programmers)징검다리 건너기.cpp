/*
���� ��ũ : https://programmers.co.kr/learn/courses/30/lessons/64062
¡�˴ٸ��� �� �ǳʴ� ������ ������ k���� ¡�˴ٸ��� ���ڰ� 0�� �Ǵ� ����.

�̴� k���� ������ ¡�˴ٸ� �� ���� ū ���ڸ�ŭ�� ����� �������� ��� �ش� ������ �ǳμ� ���� ������ �ȴ�.

k���� ������ ¡�˴ٸ� ������ ������ ���� ���̰� �� �������� ���� ū ���� ���� ¡�˴ٸ��� ���� ���̴�.

�� ������ ���� ū ���� ���� ¡�˴ٸ��� ����ŭ�� ����� �������� �ش� ������ k������ �����ε� ������ �� ���� ������ �ȴ�.

����, ������ ��� �� �������� ���� ū ���� �� ���� ���� ���̴�.

¡�˴ٸ��� ���� �ִ� 20�����̰�, k���� �ִ� 20�� �̱⿡ 2�� ������ ����ϸ� �ð��ʰ��� �Ͼ ���ɼ��� ����.

�̸� �ذ��ϱ� ���� map�� ����Ͽ� sliding window�������� �����Ͽ���.
*/
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(vector<int> stones, int k) {
    int section_max, entire_min = 200000001;
    map<int, int> m;
    //ù k�� map�� �ֱ�
    for (int a = 0; a < k; a++) {
        if (m.find(stones[a]) == m.end()) {
            m[stones[a]] = 1;
        }
        else {
            m[stones[a]]++;
        }
    }
    //a�� k�� �ε������� ������ �ݺ��ϸ� ���ο� ¡�˴ٸ��� map�� �ְ� ���� ������ ¡�˴ٸ��� map���� ����
    for (int a = k; a < stones.size(); a++) {
        //���� �������� ���� ū ���� ���� entire_min���� �۴ٸ� ����
        section_max = m.rbegin()->first;
        if (section_max < entire_min)    entire_min = section_max;
        //���ο� ¡�˴ٸ��� map�� �ִ´�
        if (m.find(stones[a]) == m.end()) {
            m[stones[a]] = 1;
        }
        else {
            m[stones[a]]++;
        }
        //���� ������ ¡�˴ٸ��� map���� ����
        m[stones[a - k]]--;
        if (m[stones[a - k]] == 0) {
            m.erase(stones[a - k]);
        }
    }
    section_max = m.rbegin()->first;
    if (section_max < entire_min)    entire_min = section_max;

    return entire_min;
}