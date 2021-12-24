/*
문제 링크 : https://leetcode.com/problems/interval-list-intersections/
Two Pointers의 전형적인 문제다.

첫 리스트와 두번째 리스트의 가장 왼쪽부터 비교를 한다. 경우의 수는 총 4가지가 있을 수 있으며 아래와 같다.

1. firstList가 secondList에 완전히 포함되는 경우
2. firstList의 처음부터 secondList의 끝까지 겹치는 경우
3. secondList의 시작부터 firstList의 끝까지 겹치는 경우
4. secondList가 firstList에 완전히 포함되는 경우

서로 비교를 한 후에는 끝이 더 작은 List의 index를 높여주면 된다.
*/
class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        vector<vector<int>> ret;
        int idx1 = 0, idx2 = 0;
        while (idx1 < firstList.size() && idx2 < secondList.size()) {
            //3번 케이스
            if (firstList[idx1][0] < secondList[idx2][0] && firstList[idx1][1] < secondList[idx2][1]) { 
                if (firstList[idx1][1] >= secondList[idx2][0])   ret.push_back(vector<int>{secondList[idx2][0], firstList[idx1][1]});
                idx1++;
            }
            //4번 케이스
            else if (firstList[idx1][0] < secondList[idx2][0] && firstList[idx1][1] >= secondList[idx2][1]) {
                ret.push_back(secondList[idx2]);
                idx2++;
            }
            //1번 케이스
            else if (firstList[idx1][0] >= secondList[idx2][0] && firstList[idx1][1] < secondList[idx2][1]) {
                ret.push_back(firstList[idx1]);
                idx1++;
            }
            //2번 케이스
            else {
                if (secondList[idx2][1] >= firstList[idx1][0])   ret.push_back(vector<int>{firstList[idx1][0], secondList[idx2][1]});
                idx2++;
            }
        }

        return ret;
    }
};