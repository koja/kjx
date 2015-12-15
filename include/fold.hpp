#ifndef KJX_FOLD_HPP_43134356051
#define KJX_FOLD_HPP_43134356051

template<
    typename Tresult,
    typename Tfunctor
> auto fold(Tresult&& _initted_output, Tfunctor _f) {

    return [initted_output = _initted_output, _f](const auto& __input) mutable {
        for(auto it = __input.begin(); it != __input.end(); ++it) {
            initted_output = _f(initted_output, *it);
        }

        return initted_output;
    };
}

#endif
