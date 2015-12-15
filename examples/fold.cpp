#include "../include/fold.hpp"

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
            fold(
                0,
                std::plus<int>()
            )(raw );

        std::cout << sum << std::endl;
    }
    {
        std::vector<int> raw = {0, 1, 2, 3};

        std::string digits =
            fold(
                std::string(),
                [](auto target, auto elem) { return target + boost::lexical_cast<std::string>(elem); }
            )(raw);

        std::cout << digits << std::endl;
    }
    {
        for(auto a :
            fold(
                std::set<int>(),
                [](auto target, auto elem) { target.insert(elem); return target; }
            )( std::vector<int>{0, 1, 2, 3, 0, 1, 2, 3} )
        ) {
            std::cout << a << " ";
        }

        std::cout << std::endl;
    }

    return EXIT_SUCCESS;
}
