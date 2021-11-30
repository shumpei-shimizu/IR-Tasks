#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	char* str;
	struct Node* tail;
} Node_t;

void printNode(Node_t* node) {
	printf("%s\n", node->str);
	return;
}

void printValues(Node_t* node) {
	printf("%s ", node->str);
	if(node->tail == NULL) return;
	printValues(node->tail);
	return;
}

Node_t* getNodeOf(Node_t* node, int index) {
	if (index == 0) return node;
	return getNodeOf(node->tail, index - 1);
}

Node_t* getPrevOf(Node_t* node, int index) {
	if (index == 1) return node;
	return getPrevOf(node->tail, index - 1);
}

Node_t* getTail(Node_t* node) {
	if (node->tail == NULL) return node;
	return getTail(node->tail);
}

Node_t* getTailPrev(Node_t* node) {
	if (node->tail->tail == NULL) return node;
	return getTailPrev(node->tail);
}
	
void addTail(Node_t* head, char* str) {
	Node_t* tail = getTail(head);
	Node_t* new_node = (Node_t*)malloc(sizeof(Node_t));
	new_node->str = str;
	new_node->tail = NULL;
	tail->tail = new_node;
	return;
}

void removeTail(Node_t* head) {
	getTailPrev(head)->tail = NULL;
}

Node_t* addHead(Node_t* head, char* str) {
	Node_t* new_head = (Node_t*)malloc(sizeof(Node_t));
	new_head->str = str;
	new_head->tail = head;
	return new_head;
}

Node_t* removeHead(Node_t* head) {
	return head->tail;
}

Node_t* insert(Node_t* head, char* str, int index) {
	if (index < 0 ) {
		addTail(head, str);
		return head;
	}
	if (index == 0) {
		return addHead(head, str);
	}
	Node_t* target = getPrevOf(head, index);
	Node_t* new_node = (Node_t*)malloc(sizeof(Node_t));
	new_node->str = str;
	new_node->tail = target->tail;
	target->tail = new_node;
	return head;
}

Node_t* removeNode(Node_t* head, int index) {
	if (index < 0) {
		removeTail(head);
		return head;
	}
	if (index == 0) {
		return removeHead(head);
	}
	Node_t* target = getPrevOf(head, index);
	target->tail = target->tail->tail;
	return head;
}

int main(void) {
	Node_t* head = (Node_t*)malloc(sizeof(Node_t));
	head->str = "I";
	head->tail = NULL;
	printNode(head);

	head = insert(head, "am", 1);
	head = insert(head, "a", 2);
	head = insert(head, "books", -1);
	head = insert(head, ".", -1);
	printValues(head);
	printf("\n");

	head = insert(head, "uoooooo!!", -1);
	head = insert(head, "uhmmmm...", 0);
	head = insert(head, "yeah!", 1);
	printValues(head);
	printf("\n");

	head = removeNode(head, 0);
	head = removeNode(head, -1);
	head = removeNode(head, 3);
	printValues(head);
	printf("\n");
	return 0;
}

