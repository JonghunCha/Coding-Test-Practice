/*
문제 링크 : https://programmers.co.kr/learn/courses/30/lessons/84021
완전 탐색으로 해결할 수 있는 문제다.

게임보드의 빈 블록과 테이블의 빈 블록을 추출한 뒤, 서로 비교해 나가며 매칭이 되는 것이 있다면 매칭 시키고 정답을 높여주면 된다.

아이디어 자체는 어렵지 않으나 구현을 일일히 하는 부분에서 시간을 많이 잡아먹는 문제라 생각한다.
*/
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

void find_blocks_board(vector<vector<int>>& board, vector<vector<vector<int>>>& blocks, int x, int y);  //게임보드에서 빈 블록을 찾는 함수
void search_near_board(vector<vector<int>>& board, vector<vector<int>>& new_block, int x, int y);   //게임보드의 빈 칸에서 인접한 빈 칸을 찾는 함수
void find_blocks_table(vector<vector<int>>& board, vector<vector<vector<int>>>& blocks, int x, int y);  //테이블에서 빈 블록을 찾는 함수
void search_near_table(vector<vector<int>>& board, vector<vector<int>>& new_block, int x, int y);   //테이블의 블록 칸에서 인접한 블록 칸을 찾는 함수
void move_blocks(vector<vector<vector<int>>>& blocks, vector<vector<vector<int>>>& moved_blocks);   //위 4개의 함수로 찾은 블록좌표들을 왼쪽 위에 딱 맞게 평행이동 시킨 상태를 만드는 함수
void rotate_block(vector<vector<int>>& block, vector<vector<int>>& new_block, int rotate_index);    //테이블 블록을 회전 시키는 함수
bool is_same_block(vector<vector<int>>& block1, vector<vector<int>>& block2);   //두 블록이 같은지 확인하는 함수

int solution(vector<vector<int>> game_board, vector<vector<int>> table) {
    int answer = 0;
    bool used[2500], matched;
    vector<vector<vector<int>>> game_board_blocks, table_blocks, empty_blocks, puzzle_blocks;
    vector<vector<int>> rotated_block;
    //게임보드에서 비어있는 블록을 찾는다
    for (int a = 0; a < game_board.size(); a++) {
        for (int b = 0; b < game_board.size(); b++) {
            if (game_board[a][b] == 0) {
                find_blocks_board(game_board, game_board_blocks, a, b);
            }
        }
    }
    //테이블에서 사용할 수 있는 블록을 찾는다
    for (int a = 0; a < table.size(); a++) {
        for (int b = 0; b < table.size(); b++) {
            if (table[a][b] == 1) {
                find_blocks_table(table, table_blocks, a, b);
            }
        }
    }
    //위에서 찾은 블록들은 좌표 값으로 저장되어 있는데, 이를 왼쪽 위에 맞게끔 평행이동 시키고 좌표값이 아니라 입력값과 같은 형태를 취하도록 변환
    move_blocks(game_board_blocks, empty_blocks);
    move_blocks(table_blocks, puzzle_blocks);
    //테이블의 블록이 사용되었는지 나타내기 위한 used변수 초기화
    for (int a = 0; a < puzzle_blocks.size(); a++)   used[a] = false;
    //게임보드의 모든 빈칸에 대해 맞는 블록이 있는지 확인
    for (int a = 0; a < empty_blocks.size(); a++) {
        matched = false;
        for (int b = 0; b < puzzle_blocks.size(); b++) {    //모든 테이블 블록에 대해 매칭 여부 확인
            for (int c = 0; c < 4; c++) {   //회전을 하여 나올 수 있는 4 경우 모두 고려
                rotated_block.clear();
                rotate_block(puzzle_blocks[b], rotated_block, c);
                //b번째 테이블 블록이 사용되지 않았고, 현재 게임보드 블록과 같다면 정답값 증가
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
//게임보드의 빈 블록을 blocks에 추가
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
//x, y좌표와 인접한 구역 중 비어 있는 칸을 같은 블록으로 추가
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
//테이블의 블록을 blocks에 추가
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
//x, y좌표와 인접한 구역 중 블록인 칸을 같은 블록으로 추가
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
//위에서 구한 블록 좌표들을 왼쪽 위에 딱 맞도록 평행이동
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
//rotate_index에 맞게 회전 시킨 뒤 move_blocks와 마찬가지로 왼쪽 위에 맞게끔 평행이동 시킨 뒤 new_block에 저장
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
//block1과 block2가 같은지 확인
bool is_same_block(vector<vector<int>>& block1, vector<vector<int>>& block2) {
    if (block1.size() != block2.size())  return false;

    for (int a = 0; a < block1.size(); a++) {
        for (int b = 0; b < block1.size(); b++) {
            if (block1[a][b] != block2[a][b])    return false;
        }
    }
    return true;
}