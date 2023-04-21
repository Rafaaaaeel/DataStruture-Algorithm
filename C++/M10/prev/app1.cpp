#include <iostream>
#include <unordered_map>
#include <unordered_set>

class Graph 
{
    private: 
        std::unordered_map<std::string, std::unordered_set<std::string> > adjlist;

    public:

        // void printGraph() 
        // {
        //     for (auto [vertex, edges] : adjlist)
        //     {
        //         std::cout << vertex << ": [ ";
        //         for (auto edge : edges)
        //         {
        //             std::cout << edge << " ";
        //         }
        //         std::cout << "]\n"; 
        //     }
        // }
};


int main() 
{
    std::unordered_map<std::string, std::unordered_set<std::string> > adjlist;
    std::unordered_map<std::string, std::string> test;

}