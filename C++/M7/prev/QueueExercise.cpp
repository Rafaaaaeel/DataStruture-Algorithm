#include <iostream>

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

class Queue 
{
    private:
        Node* first;
        Node* last;
        int length;

    public:
        Queue(int value)
        {
            Node* newNode = new Node(value);
            this->first = newNode;
            this->last = newNode;
            this->length = 1;
        }
        
        void printQueue()
        {
            Node* temp = first;

            while (temp) 
            {
                std::cout << temp->value << "\n";
                temp = temp->next;
            }
        }

        void enqueue(int value)
        {
            Node* newNode = new Node(value);

            if (length == 0)
            {
                first = newNode;
                last = newNode;
            } else {
                
                last->next = newNode;
                last = newNode;
            }

            length++;
        }

        int dequeue()
        {
            if (length == 0) return INT_MIN;
            
            Node* temp = first;
            int dequeuedValue = first->value;

            if (length == 1)
            {
                first = nullptr;
                last = nullptr;
            } else 
            {
                first = first->next;
            }
            delete temp;
            length--;
            return dequeuedValue;
        }
}; 

int main() 
{
    Queue* queue = new Queue(1);
    queue->enqueue(2);
    queue->enqueue(3);
    queue->printQueue();

    std::cout << "Dequeued Value ------> " << queue->dequeue() << "\n";
    queue->printQueue();
}