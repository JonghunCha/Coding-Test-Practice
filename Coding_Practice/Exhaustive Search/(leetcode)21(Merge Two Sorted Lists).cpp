/*
문제 링크 : https://leetcode.com/problems/merge-two-sorted-lists/
Recursion를 통해서 해결할 수 있다.

두 리스트가 오름차순으로 정렬되어있기에 두 리스트의 처음부터 살피며 아래의 과정을 거치면 된다.

1. 둘 중 하나의 리스트가 비어있다면 나머지 하나를 반환
2. 둘 다 비어있지 않다면 둘 중 val값이 작은 것을 취하고 해당 노드의 next를 재귀함수로 구한다.
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == NULL)  return l2; 
        if (l2 == NULL)  return l1;
        
        if (l1->val < l2->val) {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        }
        else {
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }
    }
};