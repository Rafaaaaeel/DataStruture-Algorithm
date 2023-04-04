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

        void printList() 
        {
            Node* temp = head;
            while(head != nullptr) 
            {
                head = head->next;
                cout << temp->value << endl;
                temp = head;
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
                tail = newNode;
            }

            length++;
        }

        void prepend(int value) 
        {
            Node* newNode = new Node(value);
            if(length == 0)
            {
                head = newNode;
                tail = newNode;
            } else 
            {
                newNode->next = head;
                head = newNode;
            }

            length++;
        }

        void deleteFirst()
        {
            if (length == 0) return; 
            Node* temp = head;
            if(length == 1)
            {
                head = nullptr;
                tail = nullptr;
            } else 
            {
                head = head->next;
            }
            delete temp;
            length--;
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
                Node* pre = head; 

                while(temp->next != nullptr) 
                {
                    pre = temp;
                    temp = temp->next;
                }

                tail = pre;
                tail->next = nullptr
            }
            delete temp;
            length--;
        }

        Node* get(int index)
        {
            if (index < 0 || index >= length) 
            {
                return nullptr;
            }

            Node* temp = head;

            for(int i = 0; i < index; i++)
            {
                temp = temp->next;
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


        bool insert(int index, int value) 
        {
            if (index == 0 || index > length) 
            {
                return false;
            }

            if (index == 0) 
            {
                prepend(value);
                return true; 
            }

            if (index == length) 
            {
                append(value);
                return true; 
            }


            Node* newValue = new Node(value);
            Node* temp = get(index - 1);
            newValue->next = temp->next;
            temp->next = newValue;
            length++;
            return true;
        }

        void deleteNode(int index) 
        {
            if (index < 0 || index > length) return;
            if (index == 0) return deleteFirst();
            if (index == length) return deleteLast();

            Node* prev = get(index); 
            Node* temp = prev->next;
            prev->next = temp-next;
            delete temp;
            length--;
        } 
};


int main()
{
    LinkedList* myLinkedList = new LinkedList(0);


    myLinkedList->append(1);
    myLinkedList->append(2);
    myLinkedList->append(4);
    
    myLinkedList->insert(3,3);
    
    myLinkedList->printList();
    

}