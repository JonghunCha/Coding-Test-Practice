/*
문제 링크 : https://leetcode.com/problems/reverse-linked-list/
재귀를 통해 해결할 수 있다.

리스트를 역으로 뒤집는 것은 맨 앞의 노드가 맨 뒤로가는 함수를 반복하면 된다. 

만약 1, 2, 3, 4, 5를 뒤집으려한다고 하자.

첫 재귀 함수는 1, 2, 3, 4, 5를 입력받는다. 여기서 맨 앞의 1을 뗴어내고 2, 3, 4, 5를 재귀 함수를 호출함으로써 뒤집도록 만든다. 

이를 반복하면 첫 번째 재귀함수는 5, 4, 3, 2를 얻을 수 있다. 이제 처음에 떼어낸 1을 맨 뒤에 이어붙이면 전부 다 뒤집은 형태가 된다.
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
    ListNode* reverseList(ListNode* head) {
        if (head == NULL || head->next == NULL)  return head;   //리스트의 끝에 도달하였을 때
        ListNode* ret, * temp;
        ret = reverseList(head->next);  //head를 떼어내고 그 뒷 부분에 대해 재귀 호출
        temp = ret;
        while (temp) {  //처음에 떼어낸 head를 리스트의 끝에 이어 붙인다
            if (temp->next == NULL) {
                temp->next = head;
                head->next = NULL;
                break;
            }
            temp = temp->next;
        }
        return ret;
    }
};