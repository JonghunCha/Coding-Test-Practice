#include <stdio.h>
#include <stdlib.h>

//Singly Linked List의 노드는 저장하고자 하는 값과 다음 노드에 대한 포인터로만 구성
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
	Node* head = (Node*)malloc(sizeof(Node));	//head노드는 연결리스트의 시작에 접근하기 위한 노드로 유의미한 데이터를 저장하지 않음

	insert(head, 0, 0);	//연결리스트의 0번째에 0삽입
	insert(head, 1, 1);	//연결리스트의 1번째에 1삽입
	insert(head, 2, 2); 	//연결리스트의 2번째에 2삽입
	printAll(head);		//연결리스트의 모든 노드들의 val값을 순서대로 출력
	erase(head, 1);		//1번째 노드 삭제
	printAll(head);		//1번째 노드 삭제되었는지 확인

	return 0;
}