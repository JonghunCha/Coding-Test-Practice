/*
���� ��ũ : https://leetcode.com/problems/search-a-2d-matrix/
�� ���� Binary Search�� ���ؼ� �ذ��� �� �ִ�.

���� target���� ��� row�� ���� �� �ִ��� �Ǻ��Ѵ�.

�׷� ���� �ش� row�� ���ؼ� target���� �����ϴ��� Ȯ���ϸ� �ȴ�.
*/
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int height = matrix.size(), width = matrix[0].size();
        int left = 0, right = height - 1, middle, target_row = 0;
        //target�� � row�� ���� �� �ִ��� �˾Ƴ���
        while (left <= right) {
            middle = (left + right) / 2;
            if (matrix[middle][0] == target)  return true;  //���� target�� �߰��ϸ� true ��ȯ
            else if (matrix[middle][0] > target) right = middle - 1;    //middle row�� ù ���� target���� ũ�ٴ� ���� target�� �׺��� ���� row�� ������ �� ������ �ǹ�
            else {  //�켱 ���� middle row�� target�� ������ �� ������ ���� Ž������ ���� �ĺ� row���� �ֱ⿡ Ž���� ��� ����
                target_row = middle;
                left = middle + 1;
            }
        }
        //������ ����� row�� ���� target�� �ִ��� Ȯ��
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