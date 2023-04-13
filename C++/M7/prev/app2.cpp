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

class Queue {
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

        void getFirst()
        {
            cout << "First: " << first->value << endl; 
        }

        void getLast() 
        {
            cout << "Last: " << last->value << endl;
        }
        
        void getLength() 
        {
            cout << "Length: " << length << endl;
        }

        void printQueue() 
        {
            Node* temp = first; 

            while(temp) 
            {
                cout << temp->value << endl;
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
            } else 
            {
                last->next = newNode;
                last = newNode;
            }

            length++;
        } 

        int dequeue() 
        {
            if (length == 0) return INT_MIN; 
            Node* temp = first;
            int dequeuedValue = temp->value;
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

class Stack 
{
    private: 
        Node* top;
        int height;

    public:
        Stack(int value)
        {
            Node* newNode = new Node(value);
            this->top = newNode;
            this->height = 1;
        }

        void getTop() 
        {
            cout << "Top: " << top->value << endl;
        }

        void getHeight() 
        {
            cout << "Height: " << height << endl;
        }

        void printStack() 
        {
            Node* temp = top;

            while(temp)
            {
                cout << temp->value << endl;
                temp = temp->next;
            }
        }

        void push(int value) 
        {
            Node* newNode = new Node(value);
            newNode->next = top; 
            top = newNode;
            height++;
        }
        
        int pop() 
        {
            if (height == 0) return INT_MIN; 

            Node* temp = top;
            int poppedValue = top->value;
            top = top->next;
            delete temp;
            height--;
            
            return poppedValue;
        }
};

int main() 
{
    // Stack* stack = new Stack(3);
    // stack->push(2);
    // stack->push(1);
    // stack->pop();
    // stack->pop();
    // stack->getTop();
    // stack->getHeight();
    // stack->printStack(); 

    Queue* queue = new Queue(7);

    queue->getFirst();
    queue->getLast();
    queue->getLength();
    queue->printQueue();

}