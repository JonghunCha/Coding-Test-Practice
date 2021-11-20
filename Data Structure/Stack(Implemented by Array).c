/*
Stack을 배열 기반으로 구현한 예시다.

블로그의 "스택(Stack)" 글에 사용된 예제 소스코드이다.

Stack의 여러가지 기능중 top(), pop(), push()기능만 구현하였다.
*/
#include <stdio.h>

#define MAX_SIZE 10

int Stack[MAX_SIZE];
int top_index = -1;

int top();	//스택의 top에 위치한 값을 반환. 스택이 비어있다면 "top() error : 스택이 비어있습니다"를 출력하고 0을 반환
int pop();	//스택의 top을 제거하고 1을 반환. 스택이 비어있다면 "pop() error : 스택이 비어있습니다"를 출력하고 0을 반환
int push(int n);	//스택의 top에 n값을 가진 원소를 추가하고 1을 반환. 스택이 꽉찬 상태면 "push() error : 스택이 꽉 찼습니다"를 출력하고 0을 반환
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
	if (top_index == -1) {
		printf("top() error : 스택이 비어있습니다\n");
		return 0;
	}
	return Stack[top_index];
}

int pop() {
	if (top_index == -1) {
		printf("pop() error : 스택이 비어있습니다\n");
		return 0;
	}
	Stack[top_index--] = 0;
	return 1;
}

int push(int n) {
	if (top_index == MAX_SIZE - 1) {
		printf("push() error : 스택이 꽉 찼습니다\n");
		return 0;
	}
	Stack[++top_index] = n;
	return 1;
}

void printStack() {
	int a;
	printf("스택 내부 : ");
	for (a = 0; a <= top_index; a++)	printf("%d ", Stack[a]);
	printf("\n");
}