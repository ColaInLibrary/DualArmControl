//
// Copyright (c) 2009, Markus Rickert
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
//
// * Redistributions of source code must retain the above copyright notice,
//   this list of conditions and the following disclaimer.
// * Redistributions in binary form must reproduce the above copyright notice,
//   this list of conditions and the following disclaimer in the documentation
//   and/or other materials provided with the distribution.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
// ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
// LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
// CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
// SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
// INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
// CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
// ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
// POSSIBILITY OF SUCH DAMAGE.
//

#include <rl/mdl/Kinematic.h>
#include <rl/mdl/UrdfFactory.h>
#include <rl/mdl/XmlFactory.h>

#include <boost/lexical_cast.hpp>
#include <iostream>
#include <memory>
#include <stdexcept>
#include <chrono>
using std::chrono::duration_cast;
using std::chrono::system_clock;
using std::chrono::milliseconds;
using std::chrono::seconds;

int main(int argc, char** argv) {
  if (argc < 2) {
    std::cout << "Usage: rlJacobianDemo KINEMATICSFILE Q1 ... Qn QD1 ... QDn"
              << std::endl;
//    return EXIT_FAILURE;
  }
  char *argv2[] = {"rlJacobianDemo",
                   "/home/ah/Documents/example_code/robot_models/NavigatorDualArmV1/urdf/NavigatorDualArmV1_Left_no_collision.urdf",
                   "0", "0", "0", "0", "0", "0", "0",
                   "0", "0", "0", "0", "0", "0", "0"};

  try {
    std::string filename(argv2[1]);
    std::shared_ptr<rl::mdl::Kinematic> kinematic;

    if ("urdf" == filename.substr(filename.length() - 4, 4)) {
      rl::mdl::UrdfFactory factory;
      kinematic = std::dynamic_pointer_cast<rl::mdl::Kinematic>(
          factory.create(filename));
    } else {
      rl::mdl::XmlFactory factory;
      kinematic = std::dynamic_pointer_cast<rl::mdl::Kinematic>(
          factory.create(filename));
    }

    rl::math::Vector q(kinematic->getDofPosition());

    for (std::ptrdiff_t i = 0; i < q.size(); ++i) {
      q(i) = boost::lexical_cast<rl::math::Real>(argv2[i + 2]);
    }

    rl::math::Vector qdot(kinematic->getDof());

    for (std::ptrdiff_t i = 0; i < qdot.size(); ++i) {
      qdot(i) = boost::lexical_cast<rl::math::Real>(argv2[q.size() + i + 2]);
    }
    double time = 0;
    for (int i = 0; i < 10000; ++i) {
      auto now = std::chrono::high_resolution_clock::now(); // 获取当前时间点
      auto now_ns = std::chrono::duration_cast<std::chrono::nanoseconds>(now.time_since_epoch()).count(); // 转换为纳秒
      kinematic->setPosition(q);
      kinematic->forwardPosition();
      kinematic->calculateJacobian();
      now = std::chrono::high_resolution_clock::now(); // 获取当前时间点
      auto now_ns2 = std::chrono::duration_cast<std::chrono::nanoseconds>(now.time_since_epoch()).count(); // 转换为纳秒
      time += now_ns2 - now_ns;
    }
    std::cout << "Jacobian time: " << time/10000.0 << " ns" << std::endl;

    std::cout << "J=" << std::endl << kinematic->getJacobian() << std::endl;

    rl::math::Vector xdot = kinematic->getJacobian() * qdot;

    std::cout << "xdot=" << std::endl;

    for (std::size_t i = 0; i < kinematic->getOperationalDof(); ++i) {
      std::cout << i << " " << xdot.transpose() << std::endl;
    }

    kinematic->calculateJacobianInverse();

    std::cout << "invJ=" << std::endl
              << kinematic->getJacobianInverse() << std::endl;

    rl::math::Vector qdot2 = kinematic->getJacobianInverse() * xdot;

    std::cout << "qdot=" << std::endl << qdot2.transpose() << std::endl;
  } catch (const std::exception& e) {
    std::cout << e.what() << std::endl;
    return EXIT_FAILURE;
  }

  return EXIT_SUCCESS;
}
