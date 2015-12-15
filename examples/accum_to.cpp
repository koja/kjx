#include "../include/accum_to.hpp"
#include "../include/foreach.hpp"
#include "../include/string/join.hpp"

#include <vector>
#include <string>
#include <boost/lexical_cast.hpp>

#include <iostream>
#include <cstdlib>

int main() {
    {
        auto accumulator = accum_to(
                std::string(),
                [](auto elem) { return boost::lexical_cast<std::string>(elem); }
            );

        accumulator(1);
        accumulator(2);
        accumulator(3);

        std::cout << accumulator(".") << std::endl;
    }
    {
        std::vector<std::string> raw = {"a", "b", "c"};

        std::cout <<
            accum_to(
                std::string(),
                string::join(" | ")
            )(raw)
            << std::endl;
    }
    {
        std::vector<std::string> raw = {"a", "b", "c"};

        std::cout <<
            foreach(
                accum_to( std::string() )
            )( raw );

        std::cout << std::endl;
    }

    return EXIT_SUCCESS;
}
