/*
���� ��ũ : https://leetcode.com/problems/middle-of-the-linked-list/
two pointers�� �ذ��� �� �ִ� ������.

middle node�� end node�� 2ĭ�� �̵��� �� 1ĭ�� �̵��Ѵٰ� �� �� �ִ�.

���� end_node�� 2ĭ�� �ű�� end_node�� linked list�� ���� �����Ͽ��� �� middle node�� ��ġ�� ��ȯ�ϸ� �ȴ�.
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
    ListNode* middleNode(ListNode* head) {
        ListNode* middle = head, * end = head;
        while (end != NULL && end->next != NULL) {
            middle = middle->next;
            end = end->next->next;
        }
        return middle;
    }
};