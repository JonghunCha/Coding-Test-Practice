/*
문제 링크 : https://programmers.co.kr/learn/courses/30/lessons/12987
문제 해결 방법만 생각해내면 구현은 쉬운 문제다.

B팀원이 최대 승점을 얻는 방법이 무엇인지 생각하는게 중요하다.

최대 승점을 얻기 위해선 승 수가 최대가 되어야 한다.

높은 수를 가진 사람이 이길수 있는 상대중 가장 높은 수를 가진 사람을 상대해야 나머지 사람이 이길 가능성이 올라간다.

따라서 A와 B를 정렬을 한 다음, B에서 높은 수를 가진 사람이 A에서 높은 수를 가진 사람을 제거하는 방식으로 매칭을 시키면 최대 승 수를 구할 수 있다.
*/
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> A, vector<int> B) {
    int answer = 0, idxA = A.size() - 1, idxB = B.size() - 1;
    //A와 B를 오름차순으로 정렬
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    
    while (idxA >= 0 && idxB >= 0) {
        if (B[idxB] > A[idxA]) {    //만약 현재 B의 사원이 A의 사원을 이길 수 있는 경우 answer++
            answer++;
            idxB--;
            idxA--;
        }
        else {  //현재 B의 사원이 A의 사원을 이길 수 없는 경우 A의 다음 상대를 확인
            idxA--;
        }
    }

    return answer;
}