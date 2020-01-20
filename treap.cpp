#include <iostream>
#include <string>

using namespace std;

class Treap {
public:
	int key;
	int priority;
	int size;
	int sum;
	Treap *left;
	Treap *right;

	Treap(int key) : key(key), priority(rand()), left(NULL), right(NULL), size(1), sum(key) {}
};

int get_size(Treap* vertex) {
	return ((vertex == NULL) ? 0 : vertex->size);
}

void resize(Treap* vertex) {
	vertex->size = 1 + get_size(vertex->left) + get_size(vertex->right);
}

Treap* merge(Treap* left_vertex, Treap* right_vertex) {
	if (left_vertex == NULL) {
		return right_vertex;
	}
	if (right_vertex == NULL) {
		return left_vertex;
	}
	if (left_vertex->priority >= right_vertex->priority) {
		left_vertex->right = merge(left_vertex->right, right_vertex);
		resize(left_vertex);
		return left_vertex;
	}
	else {
		right_vertex->left = merge(left_vertex, right_vertex->left);
		resize(right_vertex);
		return right_vertex;
	}
}

void split(Treap* root, int value, Treap*& left_vertex, Treap* &right_vertex) {
	if (root == NULL) {
		left_vertex = NULL;
		right_vertex = NULL;
		return;
	}

	if (root->key <= value) {
		split(root->right, value, root->right, right_vertex);
		left_vertex = root;
	}
	else {
		split(root->left, value, left_vertex, root->left);
		right_vertex = root;
	}
	resize(root);
}

Treap* root = NULL;

bool find(Treap* root, int value) {
	if (root == NULL) {
		return false;
	}
	if (root->key == value) {
		return true;
	}
	if (root->key < value) {
		return find(root->right, value);
	}
	else {
		return find(root->left, value);
	}
}

void insert(int value) {
	if (!find(root, value)) {
		Treap* new_vertex = new Treap(value);
		Treap* left;
		Treap* right;
		split(root, value, left, right);
		root = merge(merge(left, new_vertex), right);
	}
}

void del(int value) {
	if (find(root, value)) {
		Treap* left;
		Treap* right;
		Treap* new_left;
		Treap* new_right;
		split(root, value, left, right);
		split(left, value - 1, new_left, new_right);
		root = merge(new_left, right);
	}
}

void next(int value) {
	Treap* left;
	Treap* right;
	split(root, value, left, right);
	if (right == NULL) {
		cout << "none" << endl;
		merge(left, right);
		return;
	}
	Treap* temp = right;
	while (temp->left != NULL) {
		temp = temp->left;
	}
	cout << temp->key << endl;
	merge(left, right);
}

void prev(int value) {
	Treap* left;
	Treap* right;
	split(root, value - 1, left, right);
	if (left == NULL) {
		cout << "none" << endl;
		merge(left, right);
		return;
	}
	Treap* temp = left;
	while (temp->right != NULL) {
		temp = temp->right;
	}
	cout << temp->key << endl;
	merge(left, right);
}

void kth(Treap* root, int k) {
	if (k > get_size(root)) {
		cout << "none" << endl;
	}
	else {
		if (get_size(root->left) == k - 1) {
			cout << root->key << endl;
		}
		else if (get_size(root->left) < k - 1) {
			kth(root->right, k - get_size(root->left) - 1);
		}
		else {
			kth(root->left, k);
		}
	}
}

int main() {
	string command;
	int value;
	while (cin >> command >> value) {
		if (command == "insert") {
			insert(value);
		}
		else if (command == "exists") {
			if (find(root, value)) {
				cout << "true" << endl;
			}
			else {
				cout << "false" << endl;
			}
		}
		else if (command == "delete") {
			del(value);
		}
		else if (command == "next") {
			next(value);
		}
		else if (command == "prev") {
			prev(value);
		}
		else if (command == "kth") {
			kth(root, value);
		}
	}
	return 0;
}
