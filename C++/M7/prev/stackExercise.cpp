#include <iostream>

class Node {
    public:
        int value;
        Node* next;

        Node(int value) 
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

        void getTop()
        {
            std::cout << "Top: " << top->value << "\n";
        }

        void getHeight()
        {
            std::cout << "Height: " << height << "\n";
        }

        void printStack()
        {
            Node* temp = top; 
            while (temp)
            {
                std::cout << temp->value << "\n";
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
            if(height == 0) return INT_MIN;

            Node* temp = top; 
            int poppedValue = temp->value;
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
    stack->getTop();
    stack->getHeight();

    std::cout << "Popped value: "  << stack->pop() << "\n";
    stack->printStack();
    stack->getTop();
    stack->getHeight();
}