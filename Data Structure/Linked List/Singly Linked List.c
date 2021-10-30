#include <stdio.h>
#include <stdlib.h>

//Singly Linked List�� ���� �����ϰ��� �ϴ� ���� ���� ��忡 ���� �����ͷθ� ����
typedef struct _Node {
	int val;
	struct Node* next;
}Node;

void insert(Node* head, int _val, int index) {
	int count = 0;
	Node* temp = head, * new_node;
	while (temp) {
		if (count == index) {
			new_node = (Node*)malloc(sizeof(Node));
			new_node->val = _val;
			new_node->next = temp->next;
			temp->next = new_node;
			return;
		}
		temp = temp->next;
		count++;
	}
}

void erase(Node* head, int index) {
	int count = 0;
	Node* temp = head, * target;
	while (temp->next) {
		if (count == index) {
			target = temp->next;
			temp->next = target->next;
			free(target);
			return;
		}
		temp = temp->next;
		count++;
	}
}

void printAll(Node* head) {
	Node* temp = head->next;
	while (temp) {
		printf("%d ", temp->val);
		temp = temp->next;
	}
	printf("\n");
}

int main(void) {
	Node* head = (Node*)malloc(sizeof(Node));	//head���� ���Ḯ��Ʈ�� ���ۿ� �����ϱ� ���� ���� ���ǹ��� �����͸� �������� ����

	insert(head, 0, 0);	//���Ḯ��Ʈ�� 0��°�� 0����
	insert(head, 1, 1);	//���Ḯ��Ʈ�� 1��°�� 1����
	insert(head, 2, 2); //���Ḯ��Ʈ�� 2��°�� 2����
	printAll(head);		//���Ḯ��Ʈ�� ��� ������ val���� ������� ���
	erase(head, 1);		//1��° ��� ����
	printAll(head);		//1��° ��� �����Ǿ����� Ȯ��

	return 0;
}