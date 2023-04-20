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
            for (int i = 0; i < key.size();i++)
            {
                int asciiValue = key[i];
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
                    std::cout << "    {" << temp->key << ", " << temp->value << "}" << "\n";
                    temp = temp->next;
                }
                
            }
        }

        void set(std::string key, int value)
        {
            int index = hash(key);
            
            Node* newNode = new Node(key, value);
            if(dataMap[index] == nullptr) 
            {
                dataMap[index] = newNode;
            } else 
            {
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

            while(temp)
            {
                if (key == temp->key) return temp->value;
                temp = temp->next;
            }

            return 0;
        }

        std::vector<std::string> Keys () 
        {

            std::vector<std::string> allKeys;

            for (int i = 0; i < SIZE; i++)
            {
                Node* temp = dataMap[i];

                while(temp)
                {
                    allKeys.push_back(temp->key);
                    temp = temp->next;
                }
            }

            return allKeys;
        }
};

int main() 
{

    HashTable* table = new HashTable();
    table->set("nails", 100);
    table->set("tile", 50);
    table->set("lumber", 80);

    table->set("bolts", 200);
    table->set("screws", 140);
    table->printTable();

    std::vector<std::string> keys = table->Keys();

    for (int i = 0; i < keys.size(); i++)
    {
        std::cout << "Key: " << keys[i] << "\n";
    }

}