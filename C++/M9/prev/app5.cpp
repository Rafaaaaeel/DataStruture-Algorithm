#include <iostream>
#include <vector>

class Node 
{
    public:
        std::string key;
        int value;
        Node* next;

        Node(std::string key, int value)
        {
            this->key = key;
            this->value = value;
            next = nullptr;
        }
};

class HashTable 
{
    private: 
        static const int SIZE = 7; 
        Node* dataMap[SIZE];

    public:
        int hash(std::string key)
        {
            int hash = 0;
            for (int i = 0; i < key.size(); i++)
            {
                int asciiValue = int(key[i]);
                hash = (hash + asciiValue * 23) % SIZE;
            }
            return hash;
        }

        void printTable()
        {
            for (int i = 0; i < SIZE; i++)
            {
                std::cout << i << ":" << "\n";
                Node* temp = dataMap[i];

                while (temp)
                {
                    std::cout << "   {" << temp->key << ", " << temp->value << "} \n";
                    temp = temp->next; 
                }
            }
        }

        void insert(std::string key, int value)
        {
            Node* newNode = new Node(key, value);

            int index = hash(key);

            if (dataMap[index] == nullptr)
            {
                dataMap[index] = newNode;
            } else {
                Node* temp = dataMap[index];

                while(temp->next != nullptr)
                {
                    temp = temp->next;
                }
                
                temp->next = newNode;
            }
        }

        int get(std::string key)
        {
            int index = hash(key);

            Node* temp = dataMap[index];

            while (temp)
            {
                if(key == temp->key) return temp->value;
            }
            
            return 0;
        }
};

int main() 
{
    HashTable* lista = new HashTable();
    lista->insert("Rafael", 22);
    lista->insert("sasha", 4);
    lista->insert("leticia", 21);
    lista->insert("Wagner", 59);

    lista->printTable();

    std::cout << "Idade do usuario escolhido --------->" << lista->get("sasha") << "\n";
}