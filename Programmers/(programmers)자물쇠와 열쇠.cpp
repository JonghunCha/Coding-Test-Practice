/*
���� ��ũ : https://programmers.co.kr/learn/courses/30/lessons/60059
���� Ž������ �ذ��� �� �ִ�.

�׷��� Ű�� �Ϻθ����� �ڹ��踦 �� �� �ֱ⿡ �迭�� Ȯ���Ͽ� �ذ��Ͽ���.
*/
#include <string>
#include <vector>
#include <cstring>

using namespace std;

void rotate_key(vector<vector<int>>& key);

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    bool flag;
    int board[60][60], n = lock.size(), m = key.size();

    //�迭 Ȯ�� �� (20, 20)�������� lock ����
    memset(board, 0, sizeof(int) * 3600);
    for (int a = 0; a < n; a++) {
        for (int b = 0; b < n; b++) {
            board[a + 20][b + 20] = lock[a][b];
        }
    }

    for (int times = 0; times < 4; times++) {   //key�� ȸ���� ���� 4�� ����
        for (int x = 20 - m; x <= 20 + n; x++) {    //key�� ���� x
            for (int y = 20 - m; y <= 20 + n; y++) {    //key�� ���� y
                //lock���� key �����
                for (int a = x; a < x + m; a++) {
                    for (int b = y; b < y + m; b++) {
                        board[a][b] += key[a - x][b - y];
                    }
                }
                //lock�� key�� �� �´��� Ȯ��
                flag = true;
                for (int a = 20; a < 20 + n; a++) {
                    for (int b = 20; b < 20 + n; b++) {
                        if (board[a][b] != 1) {
                            flag = false;
                            break;
                        }
                    }
                    if (!flag)   break;
                }
                if (flag)    return true;
                //lock�� ���� key ����
                for (int a = x; a < x + m; a++) {
                    for (int b = y; b < y + m; b++) {
                        board[a][b] -= key[a - x][b - y];
                    }
                }
            }
        }
        //Ű ȸ��
        rotate_key(key);
    }

    return false;
}

void rotate_key(vector<vector<int>>& key) {
    int m = key.size();
    vector<vector<int>> new_key;
    vector<int> temp;

    for (int a = 0; a < m; a++)  temp.push_back(0);
    for (int a = 0; a < m; a++)  new_key.push_back(temp);

    for (int a = 0; a < m; a++) {
        for (int b = 0; b < m; b++) {
            new_key[b][m - a - 1] = key[a][b];
        }
    }
    for (int a = 0; a < m; a++) {
        for (int b = 0; b < m; b++) {
            key[a][b] = new_key[a][b];
        }
    }
}