/*
���� ��ũ : https://leetcode.com/problems/interval-list-intersections/
Two Pointers�� �������� ������.

ù ����Ʈ�� �ι�° ����Ʈ�� ���� ���ʺ��� �񱳸� �Ѵ�. ����� ���� �� 4������ ���� �� ������ �Ʒ��� ����.

1. firstList�� secondList�� ������ ���ԵǴ� ���
2. firstList�� ó������ secondList�� ������ ��ġ�� ���
3. secondList�� ���ۺ��� firstList�� ������ ��ġ�� ���
4. secondList�� firstList�� ������ ���ԵǴ� ���

���� �񱳸� �� �Ŀ��� ���� �� ���� List�� index�� �����ָ� �ȴ�.
*/
class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        vector<vector<int>> ret;
        int idx1 = 0, idx2 = 0;
        while (idx1 < firstList.size() && idx2 < secondList.size()) {
            //3�� ���̽�
            if (firstList[idx1][0] < secondList[idx2][0] && firstList[idx1][1] < secondList[idx2][1]) { 
                if (firstList[idx1][1] >= secondList[idx2][0])   ret.push_back(vector<int>{secondList[idx2][0], firstList[idx1][1]});
                idx1++;
            }
            //4�� ���̽�
            else if (firstList[idx1][0] < secondList[idx2][0] && firstList[idx1][1] >= secondList[idx2][1]) {
                ret.push_back(secondList[idx2]);
                idx2++;
            }
            //1�� ���̽�
            else if (firstList[idx1][0] >= secondList[idx2][0] && firstList[idx1][1] < secondList[idx2][1]) {
                ret.push_back(firstList[idx1]);
                idx1++;
            }
            //2�� ���̽�
            else {
                if (secondList[idx2][1] >= firstList[idx1][0])   ret.push_back(vector<int>{firstList[idx1][0], secondList[idx2][1]});
                idx2++;
            }
        }

        return ret;
    }
};