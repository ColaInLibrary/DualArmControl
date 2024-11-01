/**
 ******************************************************************************
 * @Description   :
 * @author        : AN Hao
 * @Date          : 24-11-1
 * @Version       : 0.0.1
 * @File          : UrdfFactory.h
 ******************************************************************************
 */

#ifndef RL_SRC_RL_MDL_URDFFACTORY_H_
#define RL_SRC_RL_MDL_URDFFACTORY_H_

#include "Factory.h"

namespace rl {
namespace mdl {
class RL_MDL_EXPORT UrdfFactory : public Factory {
 public:
  UrdfFactory();

  virtual ~UrdfFactory();

  void load(const ::std::string& filename, Model* model);

 protected:
 private:
};
}  // namespace mdl
}  // namespace rl

#endif  // RL_SRC_RL_MDL_URDFFACTORY_H_
