#include "../include/compose.hpp"

#include <boost/lexical_cast.hpp>

#include <iostream>
#include <cstdlib>

int main() {
    {

        std::cout <<
            compose(
                [](auto a) { return a * 2;},
                [](auto a) { return a + 5;}
            )(1) << std::endl;
    }
    {
        std::cout <<
            compose(
                [](auto a) { return boost::lexical_cast<std::string>(a);},
                [](auto a) { return a + 5;}
            )(42) << std::endl;
    }

    return EXIT_SUCCESS;
}
