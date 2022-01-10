/*
���� ��ũ : https://programmers.co.kr/learn/courses/30/lessons/68646
������ �ٽ��� ���ڰ� ���� ǳ���� �� �ѹ��� ��Ʈ�� �� �ִٴ� ���̴�.

���� �迭���� ���� ���� ���� �ƴ� ǳ���� ���� ���� ǳ���� ������ �� ���� ǳ���� ��Ʈ���� ������ ǳ���� �� �� �ִ�.

ǳ���� 1��~N�� ���� �ְ�, ���� ���� ǳ���� x���� �ִٰ� ��������.

�׷��ٸ� ���� ���� ǳ������ �����ʿ� �ִ� ǳ���� �ڽź��� �����ʿ� �ִ� ǳ������ ���� �۴ٸ� ���� ���� ǳ���� ���� �� �ִ�.(������ ���� ���� ǳ���� �� ��Ʈ�� ���̱⿡)

�ݴ�� ���� ���� ǳ������ ���ʿ� �ִ� ǳ���� �ڽź��� ���ʿ� �ִ� ǳ���� �� ���� �۴ٸ� ������ ǳ���� �� �� �ִ� ���̴�.

�̷��� ���̵� �̿��Ͽ� ������ ���� �ڵ尡 �Ʒ��� ����.
*/
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> input) {
    int answer = 0, min_val = 1000000000, min_idx = 0, min_val_curr;
    //���� ���� ǳ���� ���� �ε����� ���Ѵ�
    for (int a = 0; a < input.size(); a++) {
        if (input[a] < min_val) {
            min_val = input[a];
            min_idx = a;
        }
    }
    //���� ����, ������, ���� ���� ǳ���� �׻� ������ ǳ���� �� �� �ִ�
    if (min_idx == 0 || min_idx == input.size() - 1) {  //���� ���� ǳ���� �迭�� ���� ��ġ�� ���
        answer += 2;
    }
    else {  //���� ���� ǳ���� �迭�� ���� �ƴѰ��� ��ġ�� ���
        answer += 3;
    }
    //���ʺ��� Ž���ϸ� �ش� �ε����� ǳ���� ����������� ǳ���� ���� �۴ٸ� ������ ǳ���� �� �� ����
    min_val_curr = input[0];
    for (int a = 1; a < min_idx; a++) {
        if (input[a] < min_val_curr) {
            answer++;
            min_val_curr = input[a];
        }
    }
    //�������� ���
    min_val_curr = input[input.size() - 1];
    for (int a = input.size() - 2; a > min_idx; a--) {
        if (input[a] < min_val_curr) {
            answer++;
            min_val_curr = input[a];
        }
    }

    return answer;
}