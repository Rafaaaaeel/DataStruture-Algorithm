#include <iostream>

class Node {
    public:
        int value;
        Node* next;

        Node(int value) {
            this->value = value;
            this->next = nullptr;
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
                delete head;
                temp = head;
            }
        }

        void printList() {
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
                tail = newNode
            }

            length++;
        }
};