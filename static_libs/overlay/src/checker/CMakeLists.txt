cmake_minimum_required(VERSION 3.0.2)
project(checker)

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

add_executable(check_overlay_2 main_2.cpp)

target_link_libraries(check_overlay_2
  ${pkg_a_LIBRARIES}
)

#############
## Install ##
#############

install(TARGETS check_overlay check_overlay_2
  RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)
