/*
Stack�� �迭 ������� ������ ���ô�.

��α��� "����(Stack)" �ۿ� ���� ���� �ҽ��ڵ��̴�.

Stack�� �������� ����� top(), pop(), push()��ɸ� �����Ͽ���.
*/
#include <stdio.h>

#define MAX_SIZE 10

int Stack[MAX_SIZE];
int top_index = -1;

int top();	//������ top�� ��ġ�� ���� ��ȯ. ������ ����ִٸ� "������ ����ֽ��ϴ�"�� ����ϰ� 0�� ��ȯ
int pop();	//������ top�� �����ϰ� 1�� ��ȯ. ������ ����ִٸ� "������ ����ֽ��ϴ�"�� ����ϰ� 0�� ��ȯ
int push(int n);	//������ top�� n���� ���� ���Ҹ� �߰��ϰ� 1�� ��ȯ. ������ ���� ���¸� "������ �� á���ϴ�"�� ����ϰ� 0�� ��ȯ
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
	if (top_index == -1) {
		printf("������ ����ֽ��ϴ�\n");
		return 0;
	}
	return Stack[top_index];
}

int pop() {
	if (top_index == -1) {
		printf("������ ����ֽ��ϴ�\n");
		return 0;
	}
	Stack[top_index--] = 0;
	return 1;
}

int push(int n) {
	if (top_index == MAX_SIZE - 1) {
		printf("������ �� á���ϴ�\n");
		return 0;
	}
	Stack[++top_index] = n;
	return 1;
}

void printStack() {
	int a;
	printf("���� ���� : ");
	for (a = 0; a <= top_index; a++)	printf("%d ", Stack[a]);
	printf("\n");
}