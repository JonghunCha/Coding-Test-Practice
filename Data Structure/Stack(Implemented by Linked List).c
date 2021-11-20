/*
Stack�� �迭 ������� ������ ���ô�.

��α��� "����(Stack)"�ۿ����� �迭 ������� �����Ͽ�����, ���� ����Ʈ�� ������ �ҽ��ڵ嵵 ÷���Ͽ���.

��ɸ鿡���� �迭 ������� �ۼ��� �ڵ�� ���̰� ����. 

�ٸ� �迭 ����� ���ÿ����� ������ �ִ� capacity�� ������ �־�����, ���� ����Ʈ�� �����ϸ� ������ ��ü ũ��� pop(), push()�� ȣ��� ������ ���Ѵ�.
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct __Node {
	int val;
	struct __node* prev;
	struct __node* next;
}Node;

Node* topNode = NULL;
Node* bottomNode = NULL;

int top();	//������ top�� ��ġ�� ���� ��ȯ. ������ ����ִٸ� "top() error : ������ ����ֽ��ϴ�"�� ����ϰ� 0�� ��ȯ
int pop();	//������ top�� �����ϰ� 1�� ��ȯ. ������ ����ִٸ� "pop() error : ������ ����ֽ��ϴ�"�� ����ϰ� 0�� ��ȯ
int push(int n);	//������ top�� n���� ���� ���Ҹ� �߰��ϰ� 1�� ��ȯ.
void printStack();	//���ÿ� �ִ� ��� ���� bottom���� top������ ���

int main(void) {
	int topVal;

	top();
	pop();
	printStack();
	push(1);
	push(2);
	push(3);
	push(4);
	push(5);
	push(6);
	push(7);
	push(8);
	push(9);
	push(10);
	push(11);
	printStack();
	topVal = top();
	printf("���� top�� �� : %d\n", topVal);
	pop();
	push(12);
	printStack();
	topVal = top();
	printf("���� top�� �� : %d\n", topVal);

	return 0;
}

int top() {
	if (!topNode) {
		printf("top() error : ������ ����ֽ��ϴ�\n");
		return 0;
	}
	return topNode->val;
}

int pop() {
	if (!topNode) {
		printf("pop() error : ������ ����ֽ��ϴ�\n");
		return 0;
	}

	Node* temp = topNode;
	topNode = topNode->prev;
	if (!topNode)	bottomNode = NULL;
	if (topNode)	topNode->next = NULL;
	free(temp);
	return 1;
}

int push(int n) {
	Node* new_node = (Node*)malloc(sizeof(Node));
	new_node->val = n;

	if (!topNode) {
		new_node->prev = NULL;
		new_node->next = NULL;
		topNode = new_node;
		bottomNode = new_node;
		return 1;
	}

	new_node->prev = topNode;
	new_node->next = NULL;
	topNode->next = new_node;
	topNode = new_node;
	return 1;
}

void printStack() {
	Node* curr = bottomNode;

	printf("���� ���� : ");
	while (curr) {
		printf("%d ", curr->val);
		curr = curr->next;
	}
	printf("\n");
}