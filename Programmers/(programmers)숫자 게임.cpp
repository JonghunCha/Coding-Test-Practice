/*
���� ��ũ : https://programmers.co.kr/learn/courses/30/lessons/12987
���� �ذ� ����� �����س��� ������ ���� ������.

B������ �ִ� ������ ��� ����� �������� �����ϴ°� �߿��ϴ�.

�ִ� ������ ��� ���ؼ� �� ���� �ִ밡 �Ǿ�� �Ѵ�.

���� ���� ���� ����� �̱�� �ִ� ����� ���� ���� ���� ���� ����� ����ؾ� ������ ����� �̱� ���ɼ��� �ö󰣴�.

���� A�� B�� ������ �� ����, B���� ���� ���� ���� ����� A���� ���� ���� ���� ����� �����ϴ� ������� ��Ī�� ��Ű�� �ִ� �� ���� ���� �� �ִ�.
*/
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> A, vector<int> B) {
    int answer = 0, idxA = A.size() - 1, idxB = B.size() - 1;
    //A�� B�� ������������ ����
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    
    while (idxA >= 0 && idxB >= 0) {
        if (B[idxB] > A[idxA]) {    //���� ���� B�� ����� A�� ����� �̱� �� �ִ� ��� answer++
            answer++;
            idxB--;
            idxA--;
        }
        else {  //���� B�� ����� A�� ����� �̱� �� ���� ��� A�� ���� ��븦 Ȯ��
            idxA--;
        }
    }

    return answer;
}