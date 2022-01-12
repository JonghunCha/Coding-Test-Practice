/*
���� ��ũ : https://programmers.co.kr/learn/courses/30/lessons/1831
3�ܰ��� ��Ģ�� �� �����ϸ� ���� �ذ��� �� �ִ�.

3�� ���� ���ڿ��� �ڿ������� ���߾� ������, ������� ����� *�� ������ star_num, +�� ������ plus_num�̶� ����.

*�� �߰��ϱ� ���ؼ� ���� num�� 3���� ������ ���������ϸ�, star_num < (plus_num / 2)�� �����ؾ��Ѵ�.

+�� �߰��ϱ� ���ؼ� pow((plus_num / 2) - star_num)�� ���� num���� �۾ƾ��Ѵ�.
(�̴� 3�� ���� ���ڿ��� �����ϱ� ���� ������ �߰��ؾ� �� *��� ���� ���� num���� Ŀ���� �ȵǱ� ����)
*/
#include <iostream>
using namespace std;

int answer;

void check(int num, int star_num, int plus_num);
long long pow3(int times);

int solution(int n) {
    answer = 0;
    check(n - 2, 0, 2);

    return answer;
}

void check(int num, int star_num, int plus_num) {
    //���� ���ڿ��� ������ ������ �����ϸ� answer++
    if (num == 1 && (star_num * 2) == plus_num)  answer++;  
    //*�� �߰��� �� �ִ� ��� *�� �߰��ϰ� ���� ��� ����
    if (star_num < (plus_num / 2) && num % 3 == 0) {    
        check(num / 3, star_num + 1, plus_num);
    }
    //+�� �߰��� �� �ִ� ��� +�� �߰��ϰ� ���� ��� ����
    if (pow3((plus_num / 2) - star_num) < num) {
        check(num - 1, star_num, plus_num + 1);
    }
}
//3�� times���� ��ȯ
long long pow3(int times) {
    long long ret = 1;

    for (int a = 0; a < times; a++) {
        ret *= 3;
    }

    return ret;
}