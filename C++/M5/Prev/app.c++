#include <iostream>

using namespace std;

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

        ~LinkedList () {
            Node* temp = head;
            while (head != nullptr) {
                head = head->next;
                delete temp;
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

        void getHead() {
            cout << "Head: " << head->value << endl;
        }

        void getTail() {
            cout << "Tail: " << tail->value << endl;
        }

        void getLength() {
            cout << "Length: " << length << endl;
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

        void deleteLast() {
            if (length == 0) return; 
           
            Node* temp = head;

            if (length == 1) {
                head = nullptr;
                tail = nullptr;
            } else {
                Node* pre = head;
                while(temp->next != nullptr) {
                    pre = temp;
                    temp = temp->next;
                }
                tail = pre; 
                tail->next = nullptr;
            }
            length--;
            delete temp;
        }

        void reverse() 
        {
            Node* temp = head; 
            head = tail; 
            tail = temp;
            Node* after = temp->next;
            Node* before = nullptr;

            for (int i = 0; i < length; i++) 
            {
                after = temp->next;
                temp->next = before;
                before = temp;
                temp = after;
            }
        }
};

int main() {
    LinkedList* myLinkedList = new LinkedList(1);


    myLinkedList->append(2);
    myLinkedList->append(3);
    myLinkedList->append(4);
    myLinkedList->append(5);
    myLinkedList->reverse();
    
    // myLinkedList->getHead();
    // myLinkedList->getTail();
    // myLinkedList->getLength()

}