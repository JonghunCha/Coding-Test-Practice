/*
���� ��ũ : https://programmers.co.kr/learn/courses/30/lessons/12899
������ ���� ������.

�ᱹ 124 ������ ���� ǥ���ϴ� ����� 3������ ����ϴ�.

���� n�� 3���� ���� �������� ���� �̿��Ͽ� ��ȯ�� �� �� �ִ�.

�Ʒ� �ڵ带 ���� ������ �� ���� ���̴�.
*/
#include <string>
#include <vector>

using namespace std;

string solution(int n) {
    string answer = "", reverse = "";
    int temp;

    if (n == 1)  return "1";
    n--;
    while (n > 0) {
        //���� n���� 3���� ���� �������� ���� 124������ ���� ������ ���� �ȴ�.
        if (n % 3 == 0)  reverse.push_back('1');    
        else if (n % 3 == 1) reverse.push_back('2');
        else    reverse.push_back('4');
        n /= 3;
        if (n == 1) {
            reverse.push_back('1');
            break;
        }
        n--;
    }
    //while������ �������� reverse�� ���ڸ� �־����� answer�� �ٽ� ������� ����
    for (int a = reverse.size() - 1; a >= 0; a--)    answer.push_back(reverse[a]);

    return answer;
}