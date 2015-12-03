#ifndef KJX_FOR_EACH_HPP_9730456620
#define KJX_FOR_EACH_HPP_9730456620

#include <algorithm>

namespace kjx {

template<
    typename Tsequence,
    typename Tunary_function
> void for_each(Tsequence& _input, Tunary_function _f) {
    std::for_each(_input.begin(), _input.end(), _f);
}

}
#endif
