#include <iostream>
using namespace std;

class Node {
	public:
		int data;
		Node *next;
		Node(int val) : data(val), next(nullptr) {}
};

class SinglyLinkedList {
	public:
		Node *head;

		SinglyLinkedList() : head(nullptr) {}

		void insertAtBeginning(int value) {
			Node *newNode = new Node(value);
			newNode->next = head;
			head = newNode;
		}

		void insertAtEnd(int value) {
			Node *newNode = new Node(value);
			if (!head) {
				head = newNode;
			} else {
				Node *temp = head;
				while (temp->next) {
					temp = temp->next;
				}
				temp->next = newNode;
			}
		}
		void insertAtPosition(int value, int pos) {
			if (pos < 1) {
				cout << "Invalid position!" << endl;
				return;
			}

			Node *newNode = new Node(value);
			if (pos == 1) {
				newNode->next = head;
				head = newNode;
				return;
			}

			Node *temp = head;
			for (int i = 1; i < pos - 1 && temp; ++i) {
				temp = temp->next;
			}

			if (!temp) {
				cout << "Position out of bounds!" << endl;
				return;
			}

			newNode->next = temp->next;
			temp->next = newNode;
		}

		void deleteFromBeginning() {
			if (head) {
				Node *temp = head;
				head = head->next;
				delete temp;
			} else {
				cout << "List is empty!" << endl;
			}
		}

		void deleteFromEnd() {
			if (!head) {
				cout << "List is empty!" << endl;
				return;
			}

			if (!head->next) {
				delete head;
				head = nullptr;
				return;
			}
			Node *temp = head;
			while (temp->next && temp->next->next) {
				temp = temp->next;
			}
			delete temp->next;
			temp->next = nullptr;
		}
		void deleteFromPosition(int pos) {
			if (pos < 1 || !head) {
				cout << "Invalid position or empty list!" << endl;
				return;
			}
			if (pos == 1) {
				deleteFromBeginning();
				return;
			}

			Node *temp = head;
			for (int i = 1; i < pos - 1 && temp; ++i) {
				temp = temp->next;
			}

			if (!temp || !temp->next) {
				cout << "Position out of bounds!" << endl;
				return;
			}

			Node *toDelete = temp->next;
			temp->next = temp->next->next;
			delete toDelete;
		}

		void display() {
			if (!head) {
				cout << "List is empty!" << endl;
				return;
			}

			Node *temp = head;
			while (temp) {
				cout << temp->data << " ->";
				temp = temp->next;
			}
			cout << endl;
		}
};

int main() {
	SinglyLinkedList list;
	int choice, value, position;

	while (true) {
		cout << "1. Insert at beginning\n";
		cout << "2. Insert at end\n";
		cout << "3. Insert at position\n";
		cout << "4. Delete from beginning\n";
		cout << "5. Delete from end\n";
		cout << "6. Delete from position\n";
		cout << "7. Display list\n";
		cout << "8. Exit\n";
		cout << "Enter your choice: ";
		cin >> choice;

		switch (choice) {
			case 1:
				cout << "Enter value: ";
				cin >> value;
				list.insertAtBeginning(value);
				break;
			case 2:
				cout << "Enter value: ";
				cin >> value;
				list.insertAtEnd(value);
				break;
			case 3:
				cout << "Enter value: ";
				cin >> value;
				cout << "Enter position: ";
				cin >> position;
				list.insertAtPosition(value, position);
				break;
			case 4:
				list.deleteFromBeginning();
				break;
			case 5:
				list.deleteFromEnd();
				break;
			case 6:
				cout << "Enter position: ";
				cin >> position;
				list.deleteFromPosition(position);
				break;
			case 7:
				list.display();
				break;
			case 8:
				exit(0);
				return 0;
			default:
				cout << "Invalid choice!" << endl;
		}
	}
	return 0;
}
