cmake_minimum_required(VERSION 3.8)
project(pronto_ros2)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  # add_compile_options(-Wall -Wextra -Wpedantic)
  add_compile_options(-Wall)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(ament_cmake_ros REQUIRED)
find_package(Eigen3 REQUIRED)
find_package(pronto_msgs REQUIRED)
find_package(pronto_core REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(tf2)
find_package(tf2_ros REQUIRED)
find_package(tf2_eigen REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(tf2_geometry_msgs REQUIRED)
find_package(rclcpp REQUIRED)
find_package(nav_msgs REQUIRED)
find_package(Boost REQUIRED)

add_library(pronto_ros2  SHARED  src/pronto_ros2_node.cpp                                
                                src/ins_ros_handler.cpp
                                # src/index_meas_ros_handler.cpp
                                # src/init_message_ros_handler.cpp
                                # src/scan_matcher_ros_handler.cpp
                                # src/ros_frontend.cpp
                                # src/pose_msg_ros_handler.cpp
                                src/pronto_ros_conversions.cpp
                                # src/visual_odometry_ros_handler.cpp
                                # src/lidar_odometry_ros_handler.cpp
                                # src/vicon_ros_handler.cpp
                                # src/gps_ros_handler.cpp
                                src/entrypoint.cpp
)

target_compile_features(pronto_ros2 PUBLIC c_std_99 cxx_std_17 cxx_std_20)  # Require C99 and C++17
target_include_directories(pronto_ros2 PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>)
ament_target_dependencies(
  pronto_ros2
  "Eigen3"
  "pronto_msgs"
  "pronto_core"
  "sensor_msgs"
  "tf2_ros"
  "geometry_msgs"
  "tf2_geometry_msgs" 
  "rclcpp"
  "nav_msgs"
  "Boost"
  "tf2_eigen"
)

set(LIBS ${Eigen3_LIBRARIES} ${ament_cmake_LIBRARIES}
  ${sensor_msgs_LIBRARIES} ${rclcpp_LIBRARIES} 
  ${tf2_LIBRARIES} 
  ${pronto_msgs_LIBRARIES}
  ${geometry_msgs_LIBRARIES} ${pronto_core_LIBRARIES} 
  ${tf2_ros_LIBRARIES} ${nav_msgs_LIBRARIES}
  ${tf2_geometry_msgs_LIBRARIES} ${tf2_eigen_LIBRARIES})

# Causes the visibility macros to use dllexport rather than dllimport,
# which is appropriate when building the dll but not consuming it.
target_compile_definitions(pronto_ros2 PRIVATE "PRONTO_ROS2_BUILDING_LIBRARY")

install(
  DIRECTORY include/
  DESTINATION include
)
install(
  DIRECTORY config/
  DESTINATION share/${PROJECT_NAME}/config
)
install(
  TARGETS pronto_ros2
  EXPORT export_${PROJECT_NAME}
  ARCHIVE DESTINATION lib
  LIBRARY DESTINATION lib
  RUNTIME DESTINATION bin
)

ament_export_include_directories(include)
ament_export_libraries(${PROJECT_NAME})
ament_export_dependencies(  
"Eigen3"
"pronto_msgs"
"pronto_core"
"sensor_msgs"
"tf2_ros"
"geometry_msgs"
"tf2_geometry_msgs" 
"rclcpp"
"nav_msgs"
"Boost"
"tf2_eigen"
)

add_executable(${PROJECT_NAME}_node src/entrypoint.cpp)
target_include_directories(${PROJECT_NAME}_node PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>)
#this is for ament packages dependancies
ament_target_dependencies(${PROJECT_NAME}_node
  nav_msgs
  sensor_msgs
  pronto_core
  pronto_msgs
  rclcpp
  tf2_ros
)

target_link_libraries(${PROJECT_NAME}_node ${PROJECT_NAME} ${LIBS})

install(TARGETS ${PROJECT_NAME}_node
  DESTINATION lib/${PROJECT_NAME})
  



# add_executable(joint_state_with_acceleration_republisher src/joint_state_with_acceleration_republisher.cpp)
# target_include_directories(joint_state_with_acceleration_republisher PUBLIC
#   $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
#   $<INSTALL_INTERFACE:include>)
# target_link_libraries(joint_state_with_acceleration_republisher
#   ${PROJECT_NAME} ${LIBS})

# install(TARGETS joint_state_with_acceleration_republisher pronto_ros_node
#   DESTINATION lib/${PROJECT_NAME})

# Install launch files.
install(DIRECTORY
  launch
  DESTINATION share/${PROJECT_NAME}/
)


if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # the following line skips the linter which checks for copyrights
  # comment the line when a copyright and license is added to all source files
  set(ament_cmake_copyright_FOUND TRUE)
  # the following line skips cpplint (only works in a git repo)
  # comment the line when this package is in a git repo and when
  # a copyright and license is added to all source files
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

ament_export_include_directories(
  include
)
ament_export_libraries(
  pronto_ros2
)
ament_export_targets(
  export_${PROJECT_NAME}
)

ament_package()
