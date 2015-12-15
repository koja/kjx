#include "../include/foreach.hpp"

#include <functional>   // std::plus
#include <vector>
#include <set>
#include <string>
#include <boost/lexical_cast.hpp>
#include <boost/algorithm/string/join.hpp>

#include <iostream>
#include <cstdlib>

int main() {
    {
        std::vector<int> raw = {0, 1, 2, 3};

        int sum =
            foreach(
                [](auto i) { std::cout << i << "\t"; return i; }
            )(raw);

        std::cout << std::endl;
    }

    return EXIT_SUCCESS;
}
