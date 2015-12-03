#include "../../include/functional/filter.hpp"

#include <vector>
#include <set>
#include <map>
#include <iostream>
#include <cstdlib>

int main() {
    {
        std::vector<int> raw = {0, 1, 2, 3};

        std::vector<int> odd = kjx::filter( raw, [](int a)->bool{ return a % 2 == 1;} );

        for(auto a : odd) {
            std::cout << a << " ";
        }

        std::cout << std::endl;
    }
    {
        std::set<int> raw = {0, 1, 2, 3};

        std::set<int> odd = kjx::filter( raw, [](int a)->bool{ return a % 2 == 1;} );

        for(auto a : odd) {
            std::cout << a << " ";
        }

        std::cout << std::endl;
    }
    {
        for(auto a :
            kjx::filter(
                std::map<int, int>{ {0,0}, {1,1}, {2,2}, {3,3} },
                [](auto a)->bool{ return a.second % 2 == 1;}
            )
        ) {
            std::cout << a.first << ":" << a.second << " ";
        }

        std::cout << std::endl;
    }

    return EXIT_SUCCESS;
}
