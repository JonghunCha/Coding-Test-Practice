/*
���� ��ũ : https://programmers.co.kr/learn/courses/30/lessons/62048
������ �ذ��ϴ� ����� �˸� ����.

�켱 �߸��� ���簢���� ���ο� ������ �ּҰ���� ��ŭ ���� �������� �� �� �ִ�.

���� �ϳ��� ���Ͽ��� �߸��� ���簢���� ���� �ش� ������ ���� ���� + ���� ���� - 1�̴�.

�ֳ��ϸ� �� col���� �߸��� ���簢���� ���� �ּ� 1���̴�. �׷��� ���μ��� ���������� ��쿣 2���� �� �ִ�. ���μ��� ������ row�� �� - 1�̴�.

���� col�� �� + (row�� �� - 1)�� �߸��� ���簢���� ���� �ȴ�.
*/
using namespace std;

int GCD(int w, int h);

long long solution(int w, int h) {
    long long answer, count;
    int gcd = GCD(w, h), nw = w / gcd, nh = h / gcd;

    answer = (long long)w * (long long)h;
    answer -= gcd * (nw + nh - 1);

    return answer;
}
//w�� h�� �ּҰ������ ��ȯ�ϴ� �Լ�
int GCD(int w, int h) {
    int big, small, temp;
    if (w > h) {
        big = w;
        small = h;
    }
    else {
        big = h;
        small = w;
    }

    while (1) {
        if (big % small == 0)    return small;
        temp = big - small;
        if (temp > small)    big = temp;
        else {
            big = small;
            small = temp;
        }
    }
}