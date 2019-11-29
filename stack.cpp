#include <iostream>
#include <cstring>
using namespace std;

struct SNode {
	int info;
	int min;
	SNode *prev;
};

struct Stack {
	SNode *top;
	int size;
};

void initStack(Stack *s) {
	s->top = NULL;
	s->size = 0;
}

bool isEmpty(Stack *s) {
	return s->top == NULL;
}

void push(Stack *s, int value) {
	SNode *oldTop = s->top;
	SNode *n = new SNode;
	n->info = value;
	n->prev = s->top;
	s->top = n;
	if (oldTop == NULL || s->top->prev->min >= value) {
		s->top-> min = value;
	}
	else {
		s->top->min = s->top->prev->min;
	}
	delete oldTop;
	s->size++;
}

int pop(Stack *s) {
	int info = s->top->info;
	SNode *oldTop = s->top;
	s->top = s->top->prev;
	delete oldTop;
	s->size--;
	return info;
}

int min_num(Stack *s) {
	return s->top->min;
}

int back(Stack *s) {
	return s->top->info;
}

int size(Stack *s) {
	return s->size;
}

void clear(Stack *s) {
	SNode *temp = s->top;
	while (temp != NULL) {
		SNode *oldTop = temp;
		temp = temp->prev;
		delete oldTop;
	}
	delete temp;
	s->top = NULL;
	s->size = 0;
}

int main() {
	Stack *s1 = new Stack;
	Stack *s2 = new Stack;
	initStack(s1);
	initStack(s2);
	int m;
	cin >> m;
	char command[10];
	for (int i = 0; i < m; i++) {
		cin >> command;
		if (strcmp(command, "enqueue") == 0) {
			int n;
			cin >> n;
			push(s1, n);
			cout << "ok" << endl;
		}
		else if (strcmp(command, "dequeue") == 0) {
			if (isEmpty(s1) && isEmpty(s2)) {
				cout << "error" << endl;
			}
			else {
				if (isEmpty(s2)) {
					while (s1->top != NULL) {
						push(s2, pop(s1));
					}
				}
				cout << pop(s2) << endl;
			}
		}
		else if (strcmp(command, "front") == 0) {
			if (isEmpty(s1) && isEmpty(s2)) {
				cout << "error" << endl;
			}
			else {
				if (isEmpty(s2)) {
					while (s1->top != NULL) {
						push(s2, pop(s1));
					}
				}
				cout << back(s2) << endl;
			}
		}
		else if (strcmp(command, "min") == 0) {
			if (isEmpty(s1) && isEmpty(s2)) {
				cout << "error" << endl;
			}
			else if (isEmpty(s1)) {
				cout << min_num(s2) << endl;
			}
			else if (isEmpty(s2)) {
				cout << min_num(s1) << endl;
			}
			else {
				if (min_num(s1) > min_num(s2)) {
					cout << min_num(s2) << endl;
				}
				else {
					cout << min_num(s1) << endl;
				}
			}
		}
		else if (strcmp(command, "size") == 0) {
			cout << size(s2) + size(s1) << endl;
		}
		else if (strcmp(command, "clear") == 0) {
			clear(s1);
			clear(s2);
			cout << "ok" << endl;
		}
	}
	clear(s1);
	clear(s2);
	delete s1;
	delete s2;
	return 0;
}