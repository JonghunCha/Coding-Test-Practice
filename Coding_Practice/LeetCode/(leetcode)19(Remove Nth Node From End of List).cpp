/*
문제 링크 : https://leetcode.com/problems/remove-nth-node-from-end-of-list/
two pointers로 해결할 수 있는 문제다.

사용한 포인터는 실질적으로 3개이지만 two pointers알고리즘과 유사한 방식으로 구현하였다.

쉽게 생각하면 linked list의 전체 길이를 먼저 구한 후에 뒤에서 n번째 노드를 지우면 된다.

그러나 follow up에서 one pass로 구현하는 과제가 주어져서 아래와 같이 구현하였다.

먼저 처음부터 n번째 노드까지는 그냥 넘긴다. 그런 다음 n+1번째 노드 부터는 뒤에서 n번째가 될 예비 노드를 갱신해주었다.

이렇게 모든 노드를 한번 순회하고 나면 뒤에서 NthNode는 뒤에서 n번째 노드를 가르키게 된다.

또한, NthNode를 지우고 리스트를 다시 연결해주기 위해 NthNode_prev라는 변수에 뒤에서 N+1번째 노드의 주소를 담았다.
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