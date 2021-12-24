/*
문제 링크 : https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/
Two Pointers로 해결할 수 있는 문제다.

전체 리스트에서 중복되는 노드들을 다 제거하는 문제다.

while문을 통해 기존 리스트의 전체 노드들을 탐색하며 해당 노드가 중복이라면 무시하고 그렇지 않다면 tail에 해당하는 노드에 이어 붙이고 tail을 갱신하면 된다.
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
            //head가 중복이 아닌 경우 tail에 이어 붙인다.
            if (head->val != curr_val && (head->next == NULL || head->next->val != head->val)) {
                curr_val = head->val;
                tail->next = head;
                tail = head;
                head = head->next;
                tail->next = NULL;
            }
            //head가 중복인 경우 무시하고 다음 노드 탐색
            else {
                curr_val = head->val;
                head = head->next;
            }
        }
        return ret->next;
    }
};