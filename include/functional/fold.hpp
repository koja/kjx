#ifndef KJX_FOLD_HPP_43134356051
#define KJX_FOLD_HPP_43134356051

namespace kjx {

template<
    typename Tsequence,
    typename Tresult,
    typename Tfunctor
> Tresult fold(const Tsequence& _input, Tresult&& _initted_output, Tfunctor _f) {

    for(auto it =_input.begin(); it != _input.end(); ++it) {
        _initted_output = _f(_initted_output, *it);
    }

    return _initted_output;
}

}
#endif
