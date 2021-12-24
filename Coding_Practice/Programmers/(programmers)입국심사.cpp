/*
���� ��ũ : https://programmers.co.kr/learn/courses/30/lessons/43238
���� Ž������ �ذ��� �� �ִ� ������.

���ѻ��׿� ������ ������ ������ 0~1,000,000,000,000,000,000 �����̴�.

���� ������ ������ Ȯ���ϴ� ���� ��û�� �ð��� ���Ѵ�.

���� ���� Ž���� ���ؼ� ���ʷ� n���� �Ա� �ɻ縦 ��ĥ �� �ִ� �ð��� ã���� �ȴ�.
*/
#include <string>
#include <vector>

using namespace std;

long long solution(int n, vector<int> times) {
    long long left = 0, right = 1000000000000000000, middle, temp;

    while (left < right) {
        middle = (left + right) / 2;
        temp = 0;
        for (int a = 0; a < times.size(); a++) {
            temp += middle / times[a];
        }

        if (temp >= n)   right = middle;    //���� n�� �̻��� �Ա��ɻ縦 ��ĥ �� �ִٸ� �ð��� ������ left~middle�� ����
        else    left = middle + 1;  //���� n���� �Ա��ɻ縦 ��ĥ �ð��� �ȵȴٸ� �ð��� ������ middle~right�� ����
    }

    return left;
}