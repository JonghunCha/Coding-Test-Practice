/*
문제 링크 : https://leetcode.com/problems/search-a-2d-matrix/
두 번의 Binary Search를 통해서 해결할 수 있다.

먼저 target값이 어느 row에 속할 수 있는지 판별한다.

그런 다음 해당 row에 대해서 target값이 존재하는지 확인하면 된다.
*/
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int height = matrix.size(), width = matrix[0].size();
        int left = 0, right = height - 1, middle, target_row = 0;
        //target이 어떤 row에 속할 수 있는지 알아낸다
        while (left <= right) {
            middle = (left + right) / 2;
            if (matrix[middle][0] == target)  return true;  //만약 target을 발견하면 true 반환
            else if (matrix[middle][0] > target) right = middle - 1;    //middle row의 첫 수가 target보다 크다는 것은 target은 그보다 낮은 row에 존재할 수 있음을 의미
            else {  //우선 현재 middle row에 target이 존재할 수 있지만 아직 탐색하지 않은 후보 row들이 있기에 탐색을 계속 진행
                target_row = middle;
                left = middle + 1;
            }
        }
        //위에서 계산한 row에 대해 target이 있는지 확인
        left = 0, right = width - 1;
        while (left <= right) {
            middle = (left + right) / 2;
            if (matrix[target_row][middle] == target)    return true;
            else if (matrix[target_row][middle] < target)    left = middle + 1;
            else    right = middle - 1;
        }
        return false;
    }
};