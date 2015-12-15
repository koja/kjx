#ifndef KJX_COMPOSE_HPP_83358878916
#define KJX_COMPOSE_HPP_83358878916

/** function composition - compose(_f1, f_2)(x) := _f1( f_2(x) )
 */
template<typename Tfunc1, typename Tfunc2>
auto compose(Tfunc1 _f1, Tfunc2 _f2) {
    return [_f1, _f2](auto __input) mutable { return _f1(_f2(__input)); };
}

#endif
