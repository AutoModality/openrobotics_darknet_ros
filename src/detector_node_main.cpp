// Copyright 2019 Open Source Robotics Foundation, Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include <memory>

#include "openrobotics_darknet_ros/detector_node.hpp"
#include <am_utils/am_ros2_utility.h>

std::string NODE_NAME_ ("detector_node");


std::shared_ptr<am::AMLifeCycle> am::Node::node;

int main(int argc, char ** argv)
{
  rclcpp::init(argc, argv);


  am::Node::node = std::make_shared<am::AMLifeCycle>(NODE_NAME_);
  auto detector_node = std::make_shared<openrobotics::darknet_ros::DetectorNode>();

  rclcpp::spin(am::Node::node);

  rclcpp::shutdown();
  return 0;
}
