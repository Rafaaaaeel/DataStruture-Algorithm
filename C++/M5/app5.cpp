#include <iostream>

using namespace std;

class Node { 
    public:
        int value;
        Node* next;

        Node(int value) {
            this->value = value;
            next = nullptr;
        }
};

class LinkedList {
    private: 
        Node* head;
        Node* tail;
        int length;

    public: 
        LinkedList(int value) {
            Node* newNode = new Node(value);
            this->head = newNode;
            this->tail = newNode;
            this->length = 1; 
        }

        ~LinkedList() {
            Node* temp = head;
            while(head != nullptr) {
                head = head->next;
                delete temp;
                temp = head; 
            }
        }

        void printlist() {
            Node* temp = head;
            while(temp != nullptr) {
                cout << temp->value << endl;
                temp = temp->next;
            }
        }

        void append(int value) {
            Node* newNode = new Node(value);
            if (length == 0) {
                head = newNode;
                tail = newNode;
            } else {
                tail->next = newNode;
                tail = newNode;
            }
            length++;
        }
};

int main() {
    LinkedList* myList = new LinkedList(4);
    myList->append(8);
    myList->append(16);



    myList->printlist();

}