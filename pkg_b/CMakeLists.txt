cmake_minimum_required(VERSION 3.0.2)
project(pkg_b)

find_package(catkin REQUIRED pkg_a)

###################################
## catkin specific configuration ##
###################################
catkin_package(
  INCLUDE_DIRS include
  LIBRARIES pkg_b
  CATKIN_DEPENDS pkg_a
)

###########
## Build ##
###########

include_directories(
 include
 ${catkin_INCLUDE_DIRS}
)

add_library(pkg_b
  pkg_b.cpp
)

target_link_libraries(pkg_b
  ${catkin_LIBRARIES}
)

#############
## Install ##
#############
install(TARGETS pkg_b
  ARCHIVE DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
  LIBRARY DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
  RUNTIME DESTINATION ${CATKIN_GLOBAL_BIN_DESTINATION}
)

install(DIRECTORY include/pkg_b/
  DESTINATION ${CATKIN_PACKAGE_INCLUDE_DESTINATION}
  FILES_MATCHING PATTERN "*.h"
  PATTERN ".svn" EXCLUDE
)
