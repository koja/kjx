#ifndef KJX_OPTIONAL_HPP_46813854140
#define KJX_OPTIONAL_HPP_46813854140

#include <boost/function.hpp>
#include <boost/bind.hpp>


namespace kjx {

struct ExceptionIsNull {};

template<typename T> class Optional {
    private:
        bool isnull_;
        boost::function<T()> value_provider_;

        template<typename T_> static T_ indirect_ctor_call(const T_& init) {
            return T_(init);
        }

    public:

        Optional()
        :   isnull_(true),
            value_provider_()
        {}

        Optional(const T& _value)
        :   isnull_(false),
            value_provider_(boost::bind(&indirect_ctor_call<T>, _value))
        { }

        Optional& operator=(const T& _value) {
            value_provider_ = boost::bind(&indirect_ctor_call<T>, _value);
            isnull_ = false;

            return *this;
        }

        bool isnull() const {
            return isnull_;
        }

        T get_value() const {
            if (isnull()) {
                throw ExceptionIsNull();
            }

            return value_provider_();
        }
};

}
#endif
