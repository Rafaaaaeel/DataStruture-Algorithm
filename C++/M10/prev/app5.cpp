#include <iostream>
#include <unordered_map>
#include <unordered_set>


class Graph 
{
    private:
        std::unordered_map<std::string, std::unordered_set<std::string>> adjlist;

    public:
        void printGraph()
        {
            for (auto [vertex, edges] : adjlist) 
            {
                std::cout << vertex << ": [";

                for (auto edge : edges) 
                {
                    std::cout << edge << ", ";
                }

                std::cout << "]\n";
            }   
        }

        bool addVertex(std::string vertex) 
        {
            if(adjlist.count(vertex) == 0)
            {
                adjlist[vertex];
                return true;
            }

            return false;
        }

        bool addEdge(std::string vertex1, std::string vertex2) 
        {
            if(adjlist.count(vertex1) != 0 && adjlist.count(vertex2) != 0)
            {
                adjlist.at(vertex1).insert(vertex2);
                adjlist.at(vertex2).insert(vertex1);
                return true;
            }

            return false;
        } 

        bool removeEdge(std::string vertex1, std::string vertex2) 
        {
            if (adjlist.count(vertex1) != 0 && adjlist.count(vertex2) != 0) 
            {
                adjlist.at(vertex1).erase(vertex2);
                adjlist.at(vertex2).erase(vertex1);
                return true;
            }

            return false;
        }

        bool removeVertex(std::string vertex)
        {
            if (adjlist.count(vertex) == 0 ) return false;

            for (auto othersEdges : adjlist.at(vertex)) 
            {
                adjlist.at(othersEdges).erase(vertex);
            }
            adjlist.erase(vertex);
            return true;
        }

};