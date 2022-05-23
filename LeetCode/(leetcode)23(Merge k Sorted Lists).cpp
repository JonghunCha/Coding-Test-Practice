/*
���� ��ũ : https://leetcode.com/problems/merge-k-sorted-lists/
��� val���� �ϳ��� ���Ϳ� �ְ� �������ش�.

�׷� ���� ���ĵ� ������ ���� ���ο� ListNode���� ����� �̾��ָ� �ȴ�.
*/
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int> vals;
        ListNode* temp, * ret, * tail;

        //��� ������ val���� vals���Ϳ� �ִ´�
        for (int a = 0; a < lists.size(); a++) {
            temp = lists[a];
            while (temp) {
                vals.push_back(temp->val);
                temp = temp->next;
            }
        }
        //vals���� �������� ����
        sort(vals.begin(), vals.end());

        if (vals.size() == 0)    return NULL;   //���� ��尡 0���� ��� NULL ��ȯ  
        else {  //vals�� ��� val���� ���� ��带 �����ϰ� �̾��ش�
            ret = new ListNode(vals[0]);
            tail = ret;
            for (int a = 1; a < vals.size(); a++) {
                temp = new ListNode(vals[a]);
                tail->next = temp;
                tail = temp;
            }
            return ret;
        }
    }
};