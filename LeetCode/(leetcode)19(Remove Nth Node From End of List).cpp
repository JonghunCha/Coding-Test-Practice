/*
���� ��ũ : https://leetcode.com/problems/remove-nth-node-from-end-of-list/
two pointers�� �ذ��� �� �ִ� ������.

����� �����ʹ� ���������� 3�������� two pointers�˰���� ������ ������� �����Ͽ���.

���� �����ϸ� linked list�� ��ü ���̸� ���� ���� �Ŀ� �ڿ��� n��° ��带 ����� �ȴ�.

�׷��� follow up���� one pass�� �����ϴ� ������ �־����� �Ʒ��� ���� �����Ͽ���.

���� ó������ n��° �������� �׳� �ѱ��. �׷� ���� n+1��° ��� ���ʹ� �ڿ��� n��°�� �� ���� ��带 �������־���.

�̷��� ��� ��带 �ѹ� ��ȸ�ϰ� ���� �ڿ��� NthNode�� �ڿ��� n��° ��带 ����Ű�� �ȴ�.

����, NthNode�� ����� ����Ʈ�� �ٽ� �������ֱ� ���� NthNode_prev��� ������ �ڿ��� N+1��° ����� �ּҸ� ��Ҵ�.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* NthNode = head, * NthNode_prev, * currNode = head;
        int total_num = 0;
        while (currNode) {
            total_num++;
            if (total_num > n) {
                NthNode_prev = NthNode;
                NthNode = NthNode->next;
            }
            currNode = currNode->next;
        }
        if (total_num != n)  NthNode_prev->next = NthNode->next;
        else    head = NthNode->next;
        return head;
    }
};