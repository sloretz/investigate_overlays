cmake_minimum_required(VERSION 3.0.2)
project(pkg_a)

find_package(catkin REQUIRED COMPONENTS)

###################################
## catkin specific configuration ##
###################################
catkin_package(
  INCLUDE_DIRS include
  LIBRARIES ${PROJECT_NAME}_library_underlay
)

###########
## Build ##
###########

include_directories(
 include
 ${catkin_INCLUDE_DIRS}
)

add_library(${PROJECT_NAME}_library_underlay
  a.cpp
)

target_link_libraries(${PROJECT_NAME}_library_underlay
  ${catkin_LIBRARIES}
)

#############
## Install ##
#############
install(TARGETS ${PROJECT_NAME}_library_underlay
  LIBRARY DESTINATION lib
)

install(DIRECTORY include/
  DESTINATION include
)
