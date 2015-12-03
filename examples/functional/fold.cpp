#include "../../include/functional/fold.hpp"

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

        int sum = kjx::fold( raw, 0, std::plus<int>() );

        std::cout << sum << std::endl;
    }
    {
        std::vector<int> raw = {0, 1, 2, 3};

        std::string digits =
            kjx::fold(
            raw,
            std::string(),
            [](auto target, auto elem)->auto{ return target + boost::lexical_cast<std::string>(elem); }
        );

        std::cout << digits << std::endl;
    }
    {
        for(auto a :
            kjx::fold(
                std::vector<int>{0, 1, 2, 3, 0, 1, 2, 3},
                std::set<int>(),
                [](auto target, auto elem)->auto{ target.insert(elem); return target; }
            )
        ) {
            std::cout << a << " ";
        }

        std::cout << std::endl;
    }

    return EXIT_SUCCESS;
}
