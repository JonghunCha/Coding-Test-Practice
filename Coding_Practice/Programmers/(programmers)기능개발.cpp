/*
���� ��ũ : https://programmers.co.kr/learn/courses/30/lessons/42586
���α׷��ӽ������� ����/ť �������� �з��Ǿ� ������, ���� ť�� �̿����� �ʾƵ� ���� �ذ��� �� �ִ� ������.

���� �Ʒ��� ť�� �̿��� ����� �־��� �Է� ���ͷθ� �ذ��� ��� �� ������ �����Ѵ�.
*/

//ť�� �̿��� ���
#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<pair<int, int>> curr_progresses;
    int count, n_progresses, n_speeds;
    //ť�� progresses�� speeds�� pair�� ����ִ´�.
    for (int a = 0; a < progresses.size(); a++)  curr_progresses.push(make_pair(progresses[a], speeds[a]));
    //��� ������ ���������� �ݺ�
    while (!curr_progresses.empty()) {
        count = 0;
        //��� progresses�� ������ speeds��ŭ �����ش�.
        for (int a = 0; a < curr_progresses.size(); a++) {
            n_progresses = curr_progresses.front().first += curr_progresses.front().second;
            n_speeds = curr_progresses.front().second;
            curr_progresses.pop();
            curr_progresses.push(make_pair(n_progresses, n_speeds));
        }
        //�տ������� ���Ǹ� ��� �۾��� ���� progress�� �����Ѵ�.
        while (!curr_progresses.empty() && curr_progresses.front().first >= 100) {
            curr_progresses.pop();
            count++;
        }
        //�ش糯¥�� ������ �ִ� ��� answer�� �߰�
        if (count != 0)  answer.push_back(count);
    }

    return answer;
}

//�־��� �ڷḸ �̿��ϴ� ���
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    int index = 0, count;   //index�� ������ ������� ���� ù ��° �۾��� ��ġ�� ����Ų��
    //��� �۾��� ������ ������ �ݺ�
    while (index < progresses.size()) {
        count = 0;
        for (int a = index; a < progresses.size(); a++)  progresses[a] += speeds[a];    //�������� ���� ��� �۾��� ���൵�� ������ speeds�� �°� �����ش�
        for (int a = index; a < progresses.size(); a++) {   //������ ������ �۾��� ������ ī��Ʈ
            if (progresses[a] >= 100)    count++;
            else    break;
        }
        //������ ������ �۾��� �ִٸ� �� ������ answer�� �ְ�, index�� �׸�ŭ �÷��ش�.
        if (count != 0) {
            answer.push_back(count);
            index += count;
        }
    }

    return answer;
}