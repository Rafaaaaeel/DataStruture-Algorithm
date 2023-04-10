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

        void getHead() 
        {
            cout << "Head: " << head->value << endl;
        }

        void getTail() 
        {
            cout << "Tail: " << tail->value << endl;
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
            if (length == 0)
            {
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

        void deleteLast()
        {
            if (length == 0) return;
            Node* temp = tail; 
            if (length == 1)
            {
                head = nullptr;
                tail = nullptr;
            } else 
            {
                tail = tail->prev;
                tail->next = nullptr;
            }

            delete temp; 
            length--;
        }

        void prepend(int value) 
        {
            Node* newNode = new Node(value);
            if (length == 0)
            {
                head = newNode;
                tail = newNode;
            } else 
            {
                newNode->next = head;
                head->prev = newNode;
                head = newNode;
            }
            length++;
        }

        void deleteFirst()
        {
            if (length == 0) return;
            if (length == 1) return deleteLast();

            Node* temp = head; 
            head = head->next;
            head->prev = nullptr;
            delete temp;
            length--;
        }

        Node* get(int index)
        {
            if (index < 0 || index > length) return nullptr;
            if (index == 0) return head;
            if (index == length) return tail; 
            Node* temp;
            if (index < length / 2 )
            {
                temp = head;

                for (int i = 0; i < index; i++)
                {
                    temp = temp->next;
                }

            } else 
            {
                temp = tail;

                for(int i = length - 1; i > index; i--)
                {
                    temp = temp->prev;
                }
            }
            return temp;
        }
        
        bool set(int index, int value)
        {
            Node* temp = get(index);
            if (temp) 
            {
                temp->value = value;
                return true;
            }
            
            return false;
            
        }

        void insert(int index, int value)
        {
            if (index < 0 || index > length) return;
            if (index == 0) return prepend(value);
            if (index == length) return append(value);

            Node* newNode = new Node(value);
            Node* before = get(index - 1);
            Node* after = before->next;

            newNode->next = after;
            newNode->prev = before;

            before->next = newNode;
            after->prev = newNode;

            length++;
        }

        void deleteNode(int index)
        {
            if (index < 0 || index >= length) return; 
            if (index == 0) return deleteFirst();
            if (index == length - 1) return deleteLast();

            Node* temp = get(index);
            temp->next->prev = temp->prev;
            temp->prev->next = temp->next;
            delete temp;
            length--;

        }
};

int main() 
{
    DoublyLinkedList* list = new DoublyLinkedList(1);
    list->append(2);
    list->append(3);
    list->append(4);
    list->append(5);
    list->deleteFirst();
    list->insert(0,20);
    cout << "Get: " << list->get(1)->value << endl;
    list->printList();
    list->getHead();
    list->getTail();
}
