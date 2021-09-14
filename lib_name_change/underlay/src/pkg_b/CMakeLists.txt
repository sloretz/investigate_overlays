cmake_minimum_required(VERSION 3.0.2)
project(pkg_b)

find_package(catkin REQUIRED
  pkg_a
)

###################################
## catkin specific configuration ##
###################################
catkin_package(
  INCLUDE_DIRS include
  LIBRARIES ${PROJECT_NAME}_library
  CATKIN_DEPENDS
    pkg_a
)

###########
## Build ##
###########

include_directories(
 include
 ${catkin_INCLUDE_DIRS}
)

add_library(${PROJECT_NAME}_library
  b.cpp
)

target_link_libraries(${PROJECT_NAME}_library
  ${catkin_LIBRARIES}
)

#############
## Install ##
#############
install(TARGETS ${PROJECT_NAME}_library
  LIBRARY DESTINATION lib
)

install(DIRECTORY include/
  DESTINATION include
)
