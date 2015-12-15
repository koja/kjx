#ifndef KJX_FILTER_HPP_02437410153
#define KJX_FILTER_HPP_02437410153

#include <type_traits>

template<typename Tpredicate>
auto filter(Tpredicate _pred) {
    return [_pred](const auto& __input) {
        typedef typename std::remove_reference< decltype(__input) >::type Tconst_input;
        typedef typename std::remove_const< Tconst_input >::type Tbase_input;

        Tbase_input result;

        auto result_it = result.end();

        for(auto input_it = __input.begin(); input_it != __input.end(); ++input_it) {
            if( _pred(*input_it) ) {
                result.insert( result_it, *input_it );
                result_it = result.end();
            }
        }

        return result;
    };
}

#endif
