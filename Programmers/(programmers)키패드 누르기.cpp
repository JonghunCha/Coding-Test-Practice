/*
문제 링크 : https://programmers.co.kr/learn/courses/30/lessons/67256
난이도 1인 문제이고 직관적으로 드는 생각 그대로 바로 해결할 수 있는 문제다.

따라서 별도의 설명은 하지 않겠다.
*/
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
//각 인덱스는 자판의 번호를 의미하며 10과 11은 각각 *, #을 의미
int dx[12] = { 3, 0, 0, 0, 1, 1, 1, 2, 2, 2, 3, 3 };
int dy[12] = { 1, 0, 1, 2, 0, 1, 2, 0, 1, 2, 0, 2 };

int get_dist(int loc1, int loc2);

string solution(vector<int> numbers, string hand) {
    string answer = "";
    int left = 10, right = 11, dist_left, dist_right;

    for (int a = 0; a < numbers.size(); a++) {
        if (numbers[a] == 1 || numbers[a] == 4 || numbers[a] == 7) {    //1, 4, 7인 경우 왼손 사용
            answer.push_back('L');
            left = numbers[a];
        }
        else if (numbers[a] == 3 || numbers[a] == 6 || numbers[a] == 9) {   //3, 6, 9인 경우 오른손 사용
            answer.push_back('R');
            right = numbers[a];
        }
        else {
            dist_left = get_dist(left, numbers[a]);
            dist_right = get_dist(right, numbers[a]);
            if (dist_left < dist_right) {   //왼손에서 더 가까운 경우
                answer.push_back('L');
                left = numbers[a];
            }
            else if (dist_left > dist_right) {  //오른손에서 더 가까운 경우
                answer.push_back('R');
                right = numbers[a];
            }
            else {  //거리가 같을 때
                if (hand == "right") {  //오른손잡이인 경우
                    answer.push_back('R');
                    right = numbers[a];
                }
                else {  //왼손잡이인 경우
                    answer.push_back('L');
                    left = numbers[a];
                }
            }
        }
    }

    return answer;
}
//두 지점사이의 거리를 구하는 함수
int get_dist(int loc1, int loc2) {
    int ret = 0;
    ret += max(dx[loc1], dx[loc2]) - min(dx[loc1], dx[loc2]);
    ret += max(dy[loc1], dy[loc2]) - min(dy[loc1], dy[loc2]);
    return ret;
}