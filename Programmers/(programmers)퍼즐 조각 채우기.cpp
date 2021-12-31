/*
���� ��ũ : https://programmers.co.kr/learn/courses/30/lessons/84021
���� Ž������ �ذ��� �� �ִ� ������.

���Ӻ����� �� ��ϰ� ���̺��� �� ����� ������ ��, ���� ���� ������ ��Ī�� �Ǵ� ���� �ִٸ� ��Ī ��Ű�� ������ �����ָ� �ȴ�.

���̵�� ��ü�� ����� ������ ������ ������ �ϴ� �κп��� �ð��� ���� ��ƸԴ� ������ �����Ѵ�.
*/
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

void find_blocks_board(vector<vector<int>>& board, vector<vector<vector<int>>>& blocks, int x, int y);  //���Ӻ��忡�� �� ����� ã�� �Լ�
void search_near_board(vector<vector<int>>& board, vector<vector<int>>& new_block, int x, int y);   //���Ӻ����� �� ĭ���� ������ �� ĭ�� ã�� �Լ�
void find_blocks_table(vector<vector<int>>& board, vector<vector<vector<int>>>& blocks, int x, int y);  //���̺��� �� ����� ã�� �Լ�
void search_near_table(vector<vector<int>>& board, vector<vector<int>>& new_block, int x, int y);   //���̺��� ��� ĭ���� ������ ��� ĭ�� ã�� �Լ�
void move_blocks(vector<vector<vector<int>>>& blocks, vector<vector<vector<int>>>& moved_blocks);   //�� 4���� �Լ��� ã�� �����ǥ���� ���� ���� �� �°� �����̵� ��Ų ���¸� ����� �Լ�
void rotate_block(vector<vector<int>>& block, vector<vector<int>>& new_block, int rotate_index);    //���̺� ����� ȸ�� ��Ű�� �Լ�
bool is_same_block(vector<vector<int>>& block1, vector<vector<int>>& block2);   //�� ����� ������ Ȯ���ϴ� �Լ�

int solution(vector<vector<int>> game_board, vector<vector<int>> table) {
    int answer = 0;
    bool used[2500], matched;
    vector<vector<vector<int>>> game_board_blocks, table_blocks, empty_blocks, puzzle_blocks;
    vector<vector<int>> rotated_block;
    //���Ӻ��忡�� ����ִ� ����� ã�´�
    for (int a = 0; a < game_board.size(); a++) {
        for (int b = 0; b < game_board.size(); b++) {
            if (game_board[a][b] == 0) {
                find_blocks_board(game_board, game_board_blocks, a, b);
            }
        }
    }
    //���̺��� ����� �� �ִ� ����� ã�´�
    for (int a = 0; a < table.size(); a++) {
        for (int b = 0; b < table.size(); b++) {
            if (table[a][b] == 1) {
                find_blocks_table(table, table_blocks, a, b);
            }
        }
    }
    //������ ã�� ��ϵ��� ��ǥ ������ ����Ǿ� �ִµ�, �̸� ���� ���� �°Բ� �����̵� ��Ű�� ��ǥ���� �ƴ϶� �Է°��� ���� ���¸� ���ϵ��� ��ȯ
    move_blocks(game_board_blocks, empty_blocks);
    move_blocks(table_blocks, puzzle_blocks);
    //���̺��� ����� ���Ǿ����� ��Ÿ���� ���� used���� �ʱ�ȭ
    for (int a = 0; a < puzzle_blocks.size(); a++)   used[a] = false;
    //���Ӻ����� ��� ��ĭ�� ���� �´� ����� �ִ��� Ȯ��
    for (int a = 0; a < empty_blocks.size(); a++) {
        matched = false;
        for (int b = 0; b < puzzle_blocks.size(); b++) {    //��� ���̺� ��Ͽ� ���� ��Ī ���� Ȯ��
            for (int c = 0; c < 4; c++) {   //ȸ���� �Ͽ� ���� �� �ִ� 4 ��� ��� ���
                rotated_block.clear();
                rotate_block(puzzle_blocks[b], rotated_block, c);
                //b��° ���̺� ����� ������ �ʾҰ�, ���� ���Ӻ��� ��ϰ� ���ٸ� ���䰪 ����
                if (used[b] == false && is_same_block(empty_blocks[a], rotated_block)) {    
                    for (int d = 0; d < rotated_block.size(); d++) {
                        for (int e = 0; e < rotated_block.size(); e++) {
                            if (rotated_block[d][e] == 1)    answer++;
                        }
                    }
                    used[b] = true;
                    matched = true;
                    break;
                }
            }
            if (matched) break;
        }
    }

    return answer;
}
//���Ӻ����� �� ����� blocks�� �߰�
void find_blocks_board(vector<vector<int>>& board, vector<vector<vector<int>>>& blocks, int x, int y) {
    vector<vector<int>> new_block;
    int nx, ny;

    new_block.push_back({ x, y });
    board[x][y] = 1;
    for (int a = 0; a < 4; a++) {
        nx = x + dx[a];
        ny = y + dy[a];
        if (nx >= 0 && nx < board.size() && ny >= 0 && ny < board.size() && board[nx][ny] == 0) {
            search_near_board(board, new_block, nx, ny);
        }
    }

    blocks.push_back(new_block);
}
//x, y��ǥ�� ������ ���� �� ��� �ִ� ĭ�� ���� ������� �߰�
void search_near_board(vector<vector<int>>& board, vector<vector<int>>& new_block, int x, int y) {
    int nx, ny;

    new_block.push_back({ x, y });
    board[x][y] = 1;
    for (int a = 0; a < 4; a++) {
        nx = x + dx[a];
        ny = y + dy[a];
        if (nx >= 0 && nx < board.size() && ny >= 0 && ny < board.size() && board[nx][ny] == 0) {
            search_near_board(board, new_block, nx, ny);
        }
    }
}
//���̺��� ����� blocks�� �߰�
void find_blocks_table(vector<vector<int>>& board, vector<vector<vector<int>>>& blocks, int x, int y) {
    vector<vector<int>> new_block;
    int nx, ny;

    new_block.push_back({ x, y });
    board[x][y] = 0;
    for (int a = 0; a < 4; a++) {
        nx = x + dx[a];
        ny = y + dy[a];
        if (nx >= 0 && nx < board.size() && ny >= 0 && ny < board.size() && board[nx][ny] == 1) {
            search_near_table(board, new_block, nx, ny);
        }
    }

    blocks.push_back(new_block);
}
//x, y��ǥ�� ������ ���� �� ����� ĭ�� ���� ������� �߰�
void search_near_table(vector<vector<int>>& board, vector<vector<int>>& new_block, int x, int y) {
    int nx, ny;

    new_block.push_back({ x, y });
    board[x][y] = 0;
    for (int a = 0; a < 4; a++) {
        nx = x + dx[a];
        ny = y + dy[a];
        if (nx >= 0 && nx < board.size() && ny >= 0 && ny < board.size() && board[nx][ny] == 1) {
            search_near_table(board, new_block, nx, ny);
        }
    }
}
//������ ���� ��� ��ǥ���� ���� ���� �� �µ��� �����̵�
void move_blocks(vector<vector<vector<int>>>& blocks, vector<vector<vector<int>>>& moved_blocks) {
    int x_min, y_min, x_max, y_max, width, height;
    vector<vector<int>> block;
    vector<int> temp;

    for (int a = 0; a < blocks.size(); a++) {
        x_min = 50, y_min = 50, x_max = -1, y_max = -1;
        temp.clear();
        block.clear();
        for (int b = 0; b < blocks[a].size(); b++) {
            if (blocks[a][b][0] < x_min)  x_min = blocks[a][b][0];
            if (blocks[a][b][0] > x_max)  x_max = blocks[a][b][0];
            if (blocks[a][b][1] < y_min)  y_min = blocks[a][b][1];
            if (blocks[a][b][1] > y_max)  y_max = blocks[a][b][1];
        }

        width = y_max - y_min + 1;
        height = x_max - x_min + 1;
        for (int b = 0; b < max(width, height); b++) {
            temp.push_back(0);
        }
        for (int b = 0; b < max(width, height); b++) {
            block.push_back(temp);
        }

        for (int b = 0; b < blocks[a].size(); b++) {
            block[blocks[a][b][0] - x_min][blocks[a][b][1] - y_min] = 1;
        }

        moved_blocks.push_back(block);
    }
}
//rotate_index�� �°� ȸ�� ��Ų �� move_blocks�� ���������� ���� ���� �°Բ� �����̵� ��Ų �� new_block�� ����
void rotate_block(vector<vector<int>>& block, vector<vector<int>>& new_block, int rotate_index) {
    vector<int> temp;
    vector<vector<int>> temp_block;
    int length = block.size();

    for (int a = 0; a < length; a++)   temp.push_back(0);
    for (int a = 0; a < length; a++) {
        new_block.push_back(temp);
        temp_block.push_back(temp);
    }

    if (rotate_index == 0) {
        for (int a = 0; a < length; a++) {
            for (int b = 0; b < length; b++) {
                temp_block[a][b] = block[a][b];
            }
        }
    }
    else if (rotate_index == 1) {
        for (int a = 0; a < length; a++) {
            for (int b = 0; b < length; b++) {
                temp_block[a][b] = block[length - b - 1][a];
            }
        }
    }
    else if (rotate_index == 2) {
        for (int a = 0; a < length; a++) {
            for (int b = 0; b < length; b++) {
                temp_block[a][b] = block[length - a - 1][length - b - 1];
            }
        }
    }
    else {
        for (int a = 0; a < length; a++) {
            for (int b = 0; b < length; b++) {
                temp_block[a][b] = block[b][length - a - 1];
            }
        }
    }

    int x_min = 50, y_min = 50, x_max = -1, y_max = -1;
    for (int a = 0; a < length; a++) {
        for (int b = 0; b < length; b++) {
            if (temp_block[a][b] == 1) {
                if (a < x_min)   x_min = a;
                if (a > x_max)   x_max = a;
                if (b < y_min)   y_min = b;
                if (b > y_max)   y_max = b;
            }
        }
    }
    for (int a = 0; a < length; a++) {
        for (int b = 0; b < length; b++) {
            if (temp_block[a][b] == 1) {
                new_block[a - x_min][b - y_min] = 1;
            }
        }
    }
}
//block1�� block2�� ������ Ȯ��
bool is_same_block(vector<vector<int>>& block1, vector<vector<int>>& block2) {
    if (block1.size() != block2.size())  return false;

    for (int a = 0; a < block1.size(); a++) {
        for (int b = 0; b < block1.size(); b++) {
            if (block1[a][b] != block2[a][b])    return false;
        }
    }
    return true;
}