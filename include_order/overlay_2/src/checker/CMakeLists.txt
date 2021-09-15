cmake_minimum_required(VERSION 3.0.2)
project(checker)

find_package(catkin REQUIRED)
find_package(pkg_a REQUIRED)
find_package(pkg_b REQUIRED)

###################################
## catkin specific configuration ##
###################################
catkin_package(
)

###########
## Build ##
###########

include_directories(
  ${pkg_b_INCLUDE_DIRS}
  ${pkg_a_INCLUDE_DIRS}
)

add_executable(check_overlay main.cpp)

target_link_libraries(check_overlay
  ${pkg_a_LIBRARIES}
  ${pkg_b_LIBRARIES}
)

#############
## Install ##
#############

install(TARGETS check_overlay
  RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)

#############
## Testing ##
#############
