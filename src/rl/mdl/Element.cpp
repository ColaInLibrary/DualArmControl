/**
 ******************************************************************************
 * @Description   :
 * @author        : AN Hao
 * @Date          : 24-11-1
 * @Version       : 0.0.1
 * @File          : Element.cpp
 ******************************************************************************
 */
#include "Element.h"

namespace rl {
namespace mdl {
Element::Element() : name() {}

Element::~Element() {}

const ::std::string& Element::getName() const { return this->name; }

void Element::setName(const ::std::string& name) { this->name = name; }
}  // namespace mdl
}  // namespace rl
