#include <iostream>

class Node 
{
    public:
        Node* next;
        Node* prev;
        int value;

        Node(int value)
        {
            next = nullptr;
            prev = nullptr;
            this->value = value;
        }
};

class DoublyLinkedList 
{
    private:
        Node* head;
        Node* tail;
        int length;

    public:
        DoublyLinkedList()
        {
            head = nullptr;
            tail = nullptr;
            length = 0;
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

        void printList()
        {
            Node* temp = head;

            while (temp)
            {
                std::cout << temp->value << "\n";
                temp = temp->next;
            }
            
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

                for (int i = length; i > index; i--)
                {
                    temp = temp->prev;
                }

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
                newNode->prev = tail;
                tail = newNode;
            }

            length++;
        }

        void prepend(int value)
        {
            Node* newNode = new Node(value);

            if (length == 0) return append(value);

            head->prev = newNode;
            newNode->next = head;
            head = newNode;
            length++;
        }

        void insert(int index, int value)
        {
            if (index < 0 || index >= length) return;
            if (index == 0) return prepend(value);
            if (index == length -1) return append(value);

            Node* newNode = new Node(value);
            Node* temp = get(index - 1);

            newNode->next = temp->next;
            newNode->prev = temp;

            temp->next->prev = newNode;
            temp->next = newNode;
            length++;
        }

};

int main()
{
    DoublyLinkedList* list = new DoublyLinkedList();

    list->append(1);
    list->append(2);
    list->append(3);
    list->append(4);
    list->append(5);
    list->append(6);
    list->prepend(0);

    list->insert(3, 89);
    // std::cout << "Getted value: " << list->get(5)->value << "\n";

    // Print stack
    list->printList();
    list->getHead();
    list->getTail();
    list->getLength();

}