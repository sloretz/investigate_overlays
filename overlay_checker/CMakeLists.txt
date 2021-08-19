cmake_minimum_required(VERSION 3.0.2)
project(overlay_checker)

find_package(catkin REQUIRED pkg_a pkg_b)

###################################
## catkin specific configuration ##
###################################
catkin_package(
)

###########
## Build ##
###########

include_directories(
  ${catkin_INCLUDE_DIRS}
)

add_executable(check_overlay main.cpp)

target_link_libraries(check_overlay
  ${catkin_LIBRARIES}
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
