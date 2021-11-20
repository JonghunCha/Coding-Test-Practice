/*
Stack을 배열 기반으로 구현한 예시다.

블로그의 "스택(Stack)"글에서는 배열 기반으로 설명하였지만, 연결 리스트로 구현한 소스코드도 첨부하였다.

기능면에서는 배열 기반으로 작성한 코드와 차이가 없다. 

다만 배열 기반의 스택에서는 스택의 최대 capacity가 정해져 있었지만, 연결 리스트로 구현하면 스택의 전체 크기는 pop(), push()가 호출될 때마다 변한다.
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

int top();	//스택의 top에 위치한 값을 반환. 스택이 비어있다면 "top() error : 스택이 비어있습니다"를 출력하고 0을 반환
int pop();	//스택의 top을 제거하고 1을 반환. 스택이 비어있다면 "pop() error : 스택이 비어있습니다"를 출력하고 0을 반환
int push(int n);	//스택의 top에 n값을 가진 원소를 추가하고 1을 반환.
void printStack();	//스택에 있는 모든 값을 bottom부터 top순으로 출력

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
	printf("현재 top의 값 : %d\n", topVal);
	pop();
	push(12);
	printStack();
	topVal = top();
	printf("현재 top의 값 : %d\n", topVal);

	return 0;
}

int top() {
	if (!topNode) {
		printf("top() error : 스택이 비어있습니다\n");
		return 0;
	}
	return topNode->val;
}

int pop() {
	if (!topNode) {
		printf("pop() error : 스택이 비어있습니다\n");
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

	printf("스택 내부 : ");
	while (curr) {
		printf("%d ", curr->val);
		curr = curr->next;
	}
	printf("\n");
}