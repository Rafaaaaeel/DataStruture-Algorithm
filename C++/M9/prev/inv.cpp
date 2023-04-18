#include <iostream>
#include <vector>
#include <unordered_map>


bool itemInCommon(std::vector<int> vect1, std::vector<int> vect2)
{
    std::unordered_map<int, bool> map; 

    for (int i = 0; i < vect1.size(); i++) {
        map.insert({vect1[i], true});
    }

    for (int j = 0; j < vect2.size(); j++)
    {
        if (map[j]) return true;
    }

    return false;
}

int main ()
{
    std::vector<int> vect1 {1, 3, 5};
    std::vector<int> vect2 {2, 4, 5};

    std::cout << itemInCommon(vect1, vect2) << "\n";
}