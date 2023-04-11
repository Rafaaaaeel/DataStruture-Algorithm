#include <iostream>

using namespace std;

class Node 
{
    public: 
        int value;
        Node* next;
        Node* prev; 

        Node(int value)
        {
            this->value = value;
            this->next = nullptr;
            this->prev = nullptr;
        }
};

class DoublyLinkedList 
{
    private:
        Node* head;
        Node* tail;
        int length;

    public:
        DoublyLinkedList(int value)
        {
            Node* newNode = new Node(value);

            this->head = newNode;
            this->tail = newNode;
            this->length = 1; 
        }

        ~DoublyLinkedList()
        {
            Node* temp = head; 

            while(temp != nullptr)
            {
                head = head->next;
                delete temp;
                temp = head; 
            }
        }

        void getHead() 
        {
            cout << "Head: " << head->value << endl;
        }

        void getTail()
        {
            cout << "Tail: " << tail->value << endl;
        }

        void getLength() 
        {
            cout << "Length: " << length << endl;
        }

        void printList()
        {
            Node* temp = head;

            while(temp != nullptr)

            {
                cout << temp->value << endl;
                temp = temp->next;
            }
        }

       void append(int value)
       {
            Node* newNode = new Node(value);
            if (length == 0){
                head = newNode;
                tail = newNode;
            } else 
            {
                tail->next = newNode;
                newNode->prev = tail;
                tail = newNode;
            }
            length++;
       }

       void prepend(int value)
       {
            if (length == 0) return append(value);

            Node* newNode = new Node(value);

            head->prev = newNode;
            newNode->next = head;
            head = newNode;
            length++;
       }

       void insert(int index, int value)
       {
            if (index < 0 || index >= length) return;
            if (index == 0) return prepend(value);
            if (index == length - 1) return append(value);

            Node* newNode = new Node(value);
            Node* temp = get(index);

            newNode->next = temp;
            newNode->prev = temp->prev;

            temp->prev->next = newNode;
            temp->next->prev = newNode;
            length++;

       }

       Node* get(int index)
       {
            if (index < 0 || index >= length) return nullptr;
            if (index == 0) return head;
            if (index == length - 1) return tail;

            Node* temp;
            if (index < length / 2)
            {
                temp = head;

                for (int i = 0; i < index; i++) 
                {
                    temp = temp->next; 
                }

            } else 
            {
                temp = tail; 

                for (int i = length - 1; i > index; i--) 
                {
                    temp = temp->prev;
                }
            }

            return temp;
       }

       void set(int index, int value)
       {
            Node* temp = get(index);
            if (temp) 
            {
                temp->value = value;
            }
       }

       void deletefirst()
       {
            if (length == 0) return;
            Node* temp = head;
            if (length == 1)
            {
                head = nullptr;
                tail = nullptr;
            } else 
            {
                head = head->next;
                head->prev = nullptr;
            }
            delete temp;
            length--;
       }

       void deleteLast() 
       {
            if (length == 0) return;
            if (length == 1) return deletefirst();

            Node* temp = tail;
            temp->prev->next = nullptr;
            tail = temp->prev;
            delete temp;
            length--;
       }

       void deleteNode(int index)
       {
            if (index < 0 || index >= length) return;
            if (index == 0) return deletefirst();
            if (index == length - 1) return deleteLast();

            Node* temp = get(index);

            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            delete temp;
            length--; 
            
       }
};

int main()
{
    DoublyLinkedList* list = new DoublyLinkedList(1);
    list->append(2);
    list->append(4);
    list->append(5);
    delete list;
    list->printList();
    list->getHead();
    list->getTail();
    list->getLength();
    // cout << "Get: " << list->get(1)->value << endl;
}