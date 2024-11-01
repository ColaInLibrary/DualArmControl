/**
 ******************************************************************************
 * @Description   :
 * @author        : AN Hao
 * @Date          : 24-11-1
 * @Version       : 0.0.1
 * @File          : Factory.cpp
 ******************************************************************************
 */

#include "Dynamic.h"
#include "Factory.h"

namespace rl
{
namespace mdl
{
Factory::Factory()
{
}

Factory::~Factory()
{
}

::std::shared_ptr<Model>
Factory::create(const ::std::string& filename)
{
  ::std::shared_ptr<Model> model = ::std::make_shared<Dynamic>();
  this->load(filename, model.get());
  return model;
}
}
}
