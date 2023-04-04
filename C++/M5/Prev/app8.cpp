#include <iostream>

using namespace std;


class Node 
{
    public:
        int value;
        Node* next;

        Node(int value) 
        {
            this->value = value;
            this->next = nullptr;
        }
};

class LinkedList 
{
    private:
        Node* head; 
        Node* tail;
        int length;

    public:
        LinkedList(int value) 
        {
            Node* node = new Node(value);
            this->head = node;
            this->tail = node; 
            this->length = 1;
        }

        ~LinkedList() 
        {
            Node* temp = head;
            while(head->next != nullptr) 
            {
                head = temp->next;
                delete temp;
                temp = head;
            }
        }

        void getHead() 
        {
            cout << "head: " << head->value << endl;
        }


        void getTail() 
        {
            cout << "tail: " << tail->value << endl;
        }

        void printList() 
        {
            Node* temp = head;
            
            while (temp != nullptr) 
            {
                cout << temp->value << endl;
                temp = temp->next;
            }
        }

        Node* get(int index) 
        {
            if (index < 0 || index > length) return nullptr;

            Node* temp = head;

            for (int i = 0; i < index; i++) 
            {
                temp = temp->next;
            }

            return temp;
        }

        void set(int index, int value) 
        {
            Node* temp = get(index);
            temp->value = value;
        }

        void append(int value) 
        {
            Node* node = new Node(value);

            if (length == 0)
            {
                head = node;
                tail = node; 
            } else 
            {
                tail->next = node;
                tail = node; 
            }
            
            length++;
        }

        void prepend(int value) 
        {
            Node* node = new Node(value);

            if (length == 0) 
            {
                head = node; 
                tail = node; 
            } else 
            {
                node->next = head;
                head = node;
            }
            
            
            length++;
        }

        void insert(int index, int value) 
        {
            if (index < 0 || index > length) return;
            if (length == 0) return prepend(value);
            if (index == length) return append(value);

            Node* node = new Node(value); 
            Node* temp = get(index -1);

            node->next = temp->next;
            temp->next = node;
            length++;
        }

        void deleteLast() 
        {
            Node* temp = head; 
            if (length == 1) 
            {
                head = nullptr;
                tail = nullptr;
            } else 
            {
                Node* prev = head;

                while(temp->next != nullptr) 
                {
                    prev = temp;
                    temp = temp->next;
                }

                tail = prev;
                tail->next = nullptr;
            }

            delete temp;
            length--;
        }

        void deleteFirst() 
        {
            if (length == 1) return deleteLast();
            
            Node* temp = head; 
            head = head->next; 
            delete temp;
            length--;
        }

        void deleteNode(int index) 
        {
            if (index < 0 || index > length) return;
            if (index == 0) return deleteFirst(); 
            if (index == length) return deleteLast();


            Node* pre = get(index - 1);
            Node* temp = pre->next;

            pre->next = temp->next;
            delete temp;
            length--;

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

int main() 
{
    LinkedList* list = new LinkedList(1);
    list->append(3);
    list->append(4);
    list->append(5);
    list->append(6);
    list->prepend(0);
    list->insert(2,2);
    list->deleteNode(2);
    list->set(2,100);
    list->deleteLast();    
    list->deleteFirst();
    list->reverse();

    list->printList();
    list->getHead();
    list->getTail();
}