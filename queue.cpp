#include <iostream>
#include <cstring>
#include <sstream>
#include <exception>

using namespace std;

struct QNode {
	int info;
	QNode *next;
};

struct Queue {
	QNode *head;
	QNode *tail;
	int size;
};

void initQueue(Queue *q) {
	q->head = q->tail = NULL;
	q->size = 0;
}

bool isEmpty(Queue *q) {
	return q->head == NULL;
}

void enqueue(Queue *q, int value) {
	QNode *n = new QNode;
	n->info = value;
	n->next = NULL;
	if (isEmpty(q)) {
		q->head = q->tail = n;
	}
	else {
		q->tail->next = n;
		q->tail = n;
	}
	(q->size)++;
	cout << "ok" << endl;
}

int dequeue(Queue *q) {
    if(isEmpty(q) == false){
	    int info = q->head->info;
	    QNode *temp = q->head;
	    q->head = q->head->next;
	    delete temp;
	    (q->size)--;
	    return info;
    }
    else{
        ostringstream os;
        os << " error: queue is empty ";
        throw runtime_error(os.str());
    }
}

int front(Queue *q) {
	return q->head->info;
}

int size(Queue *q) {
	return q->size;
}

void clear(Queue *q) {
	QNode *temp = new QNode;
	temp = q->head;
	while (temp != NULL) {
		QNode *oldTop = temp;
		temp = temp->next;
		delete oldTop;
	}
	delete temp;
	q->head = q->tail = NULL;
	q->size = 0;
}

int main() {
	int m;
	cin >> m;
	char command[10];
	Queue *q = new Queue;
	initQueue(q);
	for (int i = 0; i < m; i++) {
		cin >> command;
		if (strcmp(command, "enqueue") == 0) {
			int n;
			cin >> n;
			enqueue(q, n);
		}
		else if (strcmp(command, "dequeue") == 0) {
			if (isEmpty(q)) {
				cout << "error" << endl;
			}
			else {
				cout << dequeue(q) << endl;
			}
		}
		else if (strcmp(command, "front") == 0) {
			if (isEmpty(q)) {
				cout << "error" << endl;
			}
			else {
				cout << front(q) << endl;
			}
		}
		else if (strcmp(command, "size") == 0) {
			cout << size(q) << endl;
		}
		else if (strcmp(command, "clear") == 0) {
			clear(q);
			cout << "ok" << endl;
		}
	}
	clear(q);
	delete q;
	return 0;
}