#ifndef KJX_FILTER_HPP_02437410153
#define KJX_FILTER_HPP_02437410153

namespace kjx {

template<
    typename Tsequence,
    typename Tpredicate
> Tsequence filter(const Tsequence& _input, Tpredicate _pred) {
    Tsequence result;

    typename Tsequence::iterator result_it = result.end();

    for(auto input_it =_input.begin(); input_it != _input.end(); ++input_it) {
        if( _pred(*input_it) ) {
            result.insert( result_it, *input_it );
            result_it = result.end();
        }
    }

    return result;
}

}
#endif
