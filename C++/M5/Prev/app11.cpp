#include <iostream>


class Node 
{
    public:
        int value;
        Node* next;

        Node(int value)
        {
            this->value = value;
            next = nullptr;
        }
};

class LinkedList 
{
    private:
        Node* head;
        Node* tail;
        int length;

    public:

        LinkedList()
        {
            head = nullptr;
            tail = nullptr;
            length = 0;
        }

        void printList()
        {
            Node* temp = head;

            while(temp)
            {
                std::cout << temp->value << "\n";
                temp = temp->next;
            }
        }

        void getHead()
        {
            std::cout << "Head: " << head->value << "\n";
        }

        void getTail()
        {
            std::cout << "Tail: " << tail->value << "\n";
        }

        void getLength() 
        {
            std::cout << "Length: " << length << "\n";
        }

        Node* get(int index)
        {
            if (index < 0 || index >= length) return nullptr;
            if (index == 0) return head;
            if (index == length - 1) return tail;

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

            if(temp)
            {
                temp->value = value;
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
            if (length == 0) return append(value);

            Node* newNode = new Node(value);

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
            Node* temp = get(index - 1);
            
            newNode->next = temp->next;
            temp->next = newNode;
            length++;
        }

        void deleteLast()
        {
            Node* temp = head;

            if(length == 1)
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

        void deleteNode(int index, int value)
        {
            if (index < 0 || index >= length) return;
            if (index == 0) return deleteFirst();
            if (index == length - 1) return deleteLast();

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
    LinkedList* list = new LinkedList();

    list->append(1);
    list->append(2);
    list->append(3);
    list->append(4);
    list->prepend(0);
    list->insert(1,89);
    list->deleteLast();
    list->deleteFirst();
    list->reverse();
    list->printList();
    list->getHead();
    list->getTail();
    list->getLength();
}