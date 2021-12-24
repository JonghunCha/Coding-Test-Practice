/*
���� ��ũ : https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/
Two Pointers�� �ذ��� �� �ִ� ������.

��ü ����Ʈ���� �ߺ��Ǵ� ������ �� �����ϴ� ������.

while���� ���� ���� ����Ʈ�� ��ü ������ Ž���ϸ� �ش� ��尡 �ߺ��̶�� �����ϰ� �׷��� �ʴٸ� tail�� �ش��ϴ� ��忡 �̾� ���̰� tail�� �����ϸ� �ȴ�.
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
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head || !head->next)   return head;
        ListNode* ret = new ListNode(1000);
        ListNode* tail = ret;
        int curr_val = 1000;
        while (head) {
            //head�� �ߺ��� �ƴ� ��� tail�� �̾� ���δ�.
            if (head->val != curr_val && (head->next == NULL || head->next->val != head->val)) {
                curr_val = head->val;
                tail->next = head;
                tail = head;
                head = head->next;
                tail->next = NULL;
            }
            //head�� �ߺ��� ��� �����ϰ� ���� ��� Ž��
            else {
                curr_val = head->val;
                head = head->next;
            }
        }
        return ret->next;
    }
};