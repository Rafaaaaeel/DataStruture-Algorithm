#include <iostream>
#include <unordered_map>
#include <unordered_set>

class Graph 
{
    private: 
        std::unordered_map<std::string, std::unordered_set<std::string> > adjlist;

    public:

        void printGraph() 
        {
            for (auto [vertex, edges] : adjlist)
            {
                std::cout << vertex << ": [ ";
                for (auto edge : edges)
                {
                    std::cout << edge << " ";
                }
                std::cout << "]\n"; 
            }
        }

        bool addVertex(std::string vertex)
        {
            if (adjlist.count(vertex) == 0) {
                adjlist[vertex];
                return true;
            }
            return false;
        }
};

int main() 
{
    Graph* graph = new Graph();

    graph->addVertex("A");

    graph->printGraph();


}