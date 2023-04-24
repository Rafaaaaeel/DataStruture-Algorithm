#include <iostream>

class Node 
{
    public: 
        Node* left;
        Node* right;
        int value;

        Node(int value)
        {
            left = nullptr;
            right = nullptr;
            this->value = value;
        }
        
};

class BinarySearchTree 
{
    private: 
        Node* root;
    
    public:
        BinarySearchTree()
        {
            root = nullptr;
        }

        bool insert(int value)
        {
            Node* newNode = new Node(value);

            if (root == nullptr)
            {
                root = newNode;
                return true;
            }

            Node* temp = root;

            while(true)
            {
                if (value == temp->value) return false;

                if (value < temp->value)
                {
                    if (temp->left == nullptr)
                    {
                        temp->left = newNode;
                        return true;
                    }

                    temp = temp->left;
                } else 
                {
                    if (temp->right == nullptr)
                    {
                        temp->right = newNode;
                        return true;
                    }

                    temp = temp->right;
                }
            }
        }

        bool contains(int value)
        {
            Node* temp = root;

            while(temp)
            {
                if (value < temp->value)
                {
                    temp = temp->left;
                } else if (value > temp->value)
                {
                    temp = temp->right;
                } else 
                {
                    return true;
                }
            }

            return false;
        }
        
};