#ifndef KJX_STRING_JOIN_HPP_9835415313
#define KJX_STRING_JOIN_HPP_9835415313

#include <string>
#include <boost/algorithm/string/join.hpp>

namespace string {

auto join(const std::string& _delim) {
    return [_delim](auto _seq)->std::string { return boost::algorithm::join(_seq, _delim); };
}

}

#endif
