#ifndef KJX_FOREACH_HPP_9730456620
#define KJX_FOREACH_HPP_9730456620

#include <utility>
#include <type_traits>

struct ExceptionEmptySequence {
    const char* const what() const { return "ExceptionEmptySequence"; }
};

template<typename Tunary_function>
auto foreach(Tunary_function _f) {
    return [_f](const auto& __seq) mutable {

        for(
            auto it = __seq.cbegin();
            it != __seq.cend();
            ++it
        ) {
            if(it+1 != __seq.cend()) {
                _f(*it);
            } else {
                return _f(*it);
            }
        }

        /* in case sequence is empty i. e. when __seq.cbegin() == __seq.cend()
         * try to return default value of type returned by functor on sequence element
         * alas - there's no guarantee that type has default constructor...
         */

        typedef typename std::remove_reference< decltype(__seq) >::type::value_type T_seq_value;
        typedef decltype( _f(std::declval<T_seq_value>()) ) Tunary_function_return_value;

        return Tunary_function_return_value();
    };
}

#endif
