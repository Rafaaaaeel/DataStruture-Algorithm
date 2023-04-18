#include <iostream>

class Node 
{
    public:
        int value;
        Node* left;
        Node* right;

        Node(int value)
        {
            this->value = value;
            left = nullptr;
            right = nullptr;
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

            if(root == nullptr) 
            {
                root = newNode;
                return true;
            }

            Node* temp = root;

            while(true)
            {
                if(newNode->value == temp->value) return false;

                if(newNode->value < temp->value) 
                {
                    if(temp->left == nullptr) 
                    {
                        temp->left = newNode;
                        return true;
                    }

                    temp = temp->left;
                } else 
                {
                    if(temp->right == nullptr) 
                    {
                        temp->right = newNode;
                        return true;
                    }

                    temp = temp->right;
                }
                
            }
        }

};