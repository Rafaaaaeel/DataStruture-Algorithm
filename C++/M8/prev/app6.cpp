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

            if (root == nullptr)
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

        void printRoot()
        {
            std::cout << "Root -> " << root->value << "\n";
        }

        void printLeft()
        {
            std::cout << "Left -> " << root->left->value << "\n";
        }

        void printRight()
        {
            std::cout << "Right -> " << root->right->value  << " left --> " << root->right->left->value << " Right --> " << root->right->right->value << "\n"; 
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


int main()
{
    BinarySearchTree* tree = new BinarySearchTree();

    tree->insert(20);
    tree->insert(10);
    tree->insert(30);

    tree->insert(23);
    tree->insert(33);
    tree->insert(5);
    tree->insert(11);

    tree->printRoot();
    tree->printLeft();
    tree->printRight();

    std::cout << "Contains ------> " << tree->contains(11) << "\n";
}

/*
            20
    10              30
5       11      23

*/