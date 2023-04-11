#include <iostream>

using namespace std;

class Node 
{
    public:
        int value; 
        Node* next;

        Node (int value) 
        {
            this->value = value;
            this->next = nullptr;
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
    Stack* stack = new Stack(3);
    stack->push(2);
    stack->push(1);
    stack->printStack();

    cout << "First pop: "<< stack->pop() << endl;
    cout << "Second pop: "<< stack->pop() << endl;
    stack->printStack();
}