/*
문제 링크 : https://leetcode.com/problems/middle-of-the-linked-list/
two pointers로 해결할 수 있는 문제다.

middle node는 end node가 2칸씩 이동할 때 1칸씩 이동한다고 볼 수 있다.

따라서 end_node를 2칸씩 옮기며 end_node가 linked list에 끝에 도달하였을 때 middle node의 위치를 반환하면 된다.
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