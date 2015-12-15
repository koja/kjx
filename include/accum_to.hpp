#ifndef KJX_ACCUM_TO_HPP_98743512102
#define KJX_ACCUM_TO_HPP_98743512102

#include "identity.hpp"
#include <string>
#include <vector>

template<typename T_functor = decltype(identity) >
auto accum_to(const std::string& _str, T_functor _f = identity) {

    return [local_str = _str, _f] (const auto& __value) mutable {
        local_str += _f(__value);
        return local_str;
    };
}

template<typename T_elem, typename T_functor = decltype(identity) >
auto accum_to(const std::vector<T_elem>& _vec, T_functor _f = identity) {

    return [local_vec = _vec, _f] (const auto& __value) mutable {
        local_vec.push_back( _f(__value) );
        return local_vec;
    };
}

#endif
