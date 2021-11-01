/*
���� ��ũ : https://leetcode.com/problems/reverse-linked-list/
��͸� ���� �ذ��� �� �ִ�.

����Ʈ�� ������ ������ ���� �� ���� ��尡 �� �ڷΰ��� �Լ��� �ݺ��ϸ� �ȴ�. 

���� 1, 2, 3, 4, 5�� ���������Ѵٰ� ����.

ù ��� �Լ��� 1, 2, 3, 4, 5�� �Է¹޴´�. ���⼭ �� ���� 1�� ���� 2, 3, 4, 5�� ��� �Լ��� ȣ�������ν� �������� �����. 

�̸� �ݺ��ϸ� ù ��° ����Լ��� 5, 4, 3, 2�� ���� �� �ִ�. ���� ó���� ��� 1�� �� �ڿ� �̾���̸� ���� �� ������ ���°� �ȴ�.
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
        if (head == NULL || head->next == NULL)  return head;   //����Ʈ�� ���� �����Ͽ��� ��
        ListNode* ret, * temp;
        ret = reverseList(head->next);  //head�� ����� �� �� �κп� ���� ��� ȣ��
        temp = ret;
        while (temp) {  //ó���� ��� head�� ����Ʈ�� ���� �̾� ���δ�
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