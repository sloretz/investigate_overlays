cmake_minimum_required(VERSION 3.0.2)
project(pkg_a)

find_package(catkin REQUIRED COMPONENTS)

###################################
## catkin specific configuration ##
###################################
catkin_package(
  INCLUDE_DIRS include
  LIBRARIES ${PROJECT_NAME}_library
)

###########
## Build ##
###########

include_directories(
 include
 ${catkin_INCLUDE_DIRS}
)

# Manually made static, but could have been static because of -DBUILD_SHARED_LIBS:=OFF
add_library(${PROJECT_NAME}_library STATIC
  a.cpp
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
