#include "../include/identity.hpp"

#include <iostream>
#include <cstdlib>

int main() {
    {
        const std::string test = {"abc"};

        std::cout << identity(test) << std::endl;
    }
    {
        const std::string test = {"abc"};

        std::cout << identity(1 + 2 + 3) << std::endl;
    }
    return EXIT_SUCCESS;
}
