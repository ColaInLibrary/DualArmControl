/**
 ******************************************************************************
 * @Description   :
 * @author        : AN Hao
 * @Date          : 24-11-1
 * @Version       : 0.0.1
 * @File          : Factory.h
 ******************************************************************************
 */

#ifndef RL_SRC_RL_MDL_FACTORY_H_
#define RL_SRC_RL_MDL_FACTORY_H_

#include <rl/mdl/export.h>

#include <memory>
#include <string>

namespace rl {
namespace mdl {
class Model;

class RL_MDL_EXPORT Factory {
 public:
  Factory();

  virtual ~Factory();

  virtual ::std::shared_ptr<Model> create(const ::std::string& filename);

  virtual void load(const ::std::string& filename, Model* model) = 0;

 protected:
 private:
};
}  // namespace mdl
}  // namespace rl

#endif  // RL_SRC_RL_MDL_FACTORY_H_
