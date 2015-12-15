#include <string>
#include <vector>
#include <experimental/optional>
#include <boost/algorithm/string/join.hpp>
#include <boost/lexical_cast.hpp>

#include "../include/foreach.hpp"
#include "../include/fold.hpp"
#include "../include/accum_to.hpp"
#include "../include/compose.hpp"
#include "../include/string/join.hpp"

#include <iostream>
#include <cstdlib>

int main() {

    std::vector<
        std::vector<
            std::experimental::optional<int>
        >
    > testdata = {{1, std::experimental::optional<int>()}, {std::experimental::optional<int>(), 2}};

    {
        std::string result;

        std::vector<std::string> converted_lines;

        for(const auto& line : testdata) {
            std::vector<std::string> converted_line_elems;
            for(const auto& el : line) {
                converted_line_elems.push_back(
                    el
                    ?   boost::lexical_cast<std::string>( el.value() )
                    :   " "
                );
            }
            converted_lines.push_back( boost::algorithm::join(converted_line_elems, " | ") );
        }

        result = "{" + boost::algorithm::join( converted_lines, "}\n{") + "}";

        std::cout << result << std::endl;
    }

    std::cout << std::endl;

    {
        const std::string result =
            "{" +
            string::join("}\n{")(
                fold(
                    std::vector<std::string>(),
                    [](auto& vec, auto row) {
                        vec.push_back(
                            string::join(" | ")(
                                foreach(
                                    accum_to(
                                        std::vector<std::string>(),
                                        [](const auto& el) { return el ? boost::lexical_cast<std::string>( el.value() ) : " "; }
                                    )
                                )(row)
                            )
                        );

                        return vec;
                    }
                )
                ( testdata )
            )
            + "}";

        std::cout << result << std::endl;
    }

    return 0;
}
