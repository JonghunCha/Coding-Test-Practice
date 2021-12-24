/*
���� ��ũ : https://programmers.co.kr/learn/courses/30/lessons/43163
BFS�� �ذ��� �� �ִ� ������.

���� ª�� ��ȯ�� ã�� ���ؼ� begin���� ������ ��ȯ�� ��� ť�� �ִ´�.

�׷� ���� target������ ��ȯ�� �̷�� �� ������ ť���� �ϳ��� �̾� ��ȯ�� �� �� ť�� �� �ڿ� �־��ִ� �۾��� �ݺ��ϸ� �ȴ�.
*/
#include <string>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

int solution(string begin, string target, vector<string> words) {
    int visited[50], diff_num, curr;
    string temp;
    queue<pair<string, int>> q;
    bool isfind = false;
    //Ư�� �ܾ �̹� ��ȯ �� �� �ִ����� ��Ÿ���� visited �ʱ�ȭ
    for (int a = 0; a < words.size(); a++)  visited[a] = 0;
    //begin�ܾ�� ��ȯ �� �� �ִ� �ܾ ť�� �ְ� visited�� 1�� ����
    for (int a = 0; a < words.size(); a++) {
        diff_num = 0;
        for (int b = 0; b < begin.size(); b++) {
            if (begin[b] != words[a][b]) diff_num++;
        }
        if (diff_num == 1) {
            q.push(make_pair(words[a], 1));
            visited[a] = 1;
        }
    }
    //target�ܾ ã���� ������ ��ȯ, ť�� �������� �ݺ�
    while (!q.empty()) {
        temp = q.front().first;
        curr = q.front().second;
        q.pop();
        if (temp.compare(target) == 0)   return curr;   //���� ���� �ܾ target�ܾ��� ���� ��ȯ
        //���� �ܾ��� temp���� ��ȯ ������ �ܾ ť�� �߰�
        for (int a = 0; a < words.size(); a++) {
            diff_num = 0;
            if (visited[a] == 0) {
                for (int b = 0; b < temp.size(); b++) {
                    if (temp[b] != words[a][b])  diff_num++;
                }
                if (diff_num == 1) {
                    q.push(make_pair(words[a], curr + 1));
                    visited[a] = 1;
                }
            }
        }
    }
    //ť�� �� while���� ���� ���� ���� target�ܾ���� ��ȯ�� �Ұ��� �ϴٴ� ��
    return 0;
}