/*
Doubly Linked List�� ���� ���ô�.

��α׿� �������� "���� ����Ʈ(Linked List)" �ۿ� ���� ���� �ҽ��ڵ��.

���� ����Ʈ�� ��� �����ϴ��� Ȯ���ϱ� ���� �ڵ�� ����, ����, ����Ʈ��� ��ɸ� �ۼ��Ͽ��� �߸��� �Ű������� ���� ����ó���ڵ�� ���Խ�Ű�� �ʾҴ�.
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct __Node {
	int val;
	struct __Node* prev;
	struct __Node* next;
}Node;

void insert(Node** head, int __val, int position);
void erase(Node** head, int position);
void printList(Node* head);

int main(void) {
	Node* head = NULL;

	insert(&head, 0, 0);
	insert(&head, 1, 1);
	insert(&head, 2, 2);
	insert(&head, 3, 3);
	insert(&head, 4, 4);
	insert(&head, 5, 5);
	printList(head);
	insert(&head, 100, 2);
	printList(head);
	erase(&head, 3);
	printList(head);

	return 0;
}

void insert(Node** head, int __val, int position) {
	Node* new_node = (Node*)malloc(sizeof(Node));
	new_node->val = __val;
	if (*head == NULL || position == 0) {
		new_node->prev = NULL;
		new_node->next = *head;
		if (*head != NULL) {
			(*head)->prev = new_node;
		}
		*head = new_node;
	}
	else {
		int count = 1;
		Node* curr = *head;
		while (curr) {
			if (count == position) {
				new_node->prev = curr;
				new_node->next = curr->next;
				if (curr->next != NULL)	curr->next->prev = new_node;
				curr->next = new_node;
				return;
			}
			curr = curr->next;
			count++;
		}
	}
}

void erase(Node** head, int position) {
	int count = 0;
	Node* curr = *head;
	while (curr) {
		if (count == position) {
			if (position == 0) {
				if (curr->next != NULL) {
					curr->next->prev = NULL;
					*head = curr->next;
					free(curr);
					return;
				}
				else {
					*head = NULL;
					free(curr);
					return;
				}
			}
			else {
				curr->prev->next = curr->next;
				if (curr->next != NULL)	curr->next->prev = curr->prev;
				free(curr);
				return;
			}
		}
		curr = curr->next;
		count++;
	}
}

void printList(Node* head) {
	Node* curr = head;
	if (curr == NULL)	printf("����Ʈ�� ����ֽ��ϴ�\n");
	while (curr) {
		printf("%d ", curr->val);
		curr = curr->next;
	}
	printf("\n");
}