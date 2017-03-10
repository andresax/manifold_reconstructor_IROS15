cmake_minimum_required(VERSION 2.8.3)

project(manifoldReconstructor)  
   
#----------------------- CMAKE MODULES ------------------------ 

set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake/modules)  
  
# ----------------------- LIBRARIES ---------------------------

find_package(Boost COMPONENTS filesystem system REQUIRED)
find_package(OpenCV REQUIRED)
find_package(CGAL REQUIRED)
find_package(Eigen3 REQUIRED)

# ----------------------- INCLUDES ----------------------------
include_directories( ${EIGEN3_INCLUDE_DIR}
                      ${GMPXX_INCLUDE_DIR}
                      ${OpenCV_INCLUDE_DIRS} 
                      ${CGAL_INCLUDE_DIRS}
                      external/
                      include/
                      ) 

# ----------------------- GCC FLAGS ----------------------------

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -fpermissive")

# ------------------------ MESSAGES ----------------------------

# ------------------------ BUILD -------------------------------

file(GLOB_RECURSE meshlib_SOURCE 
                  src/*.cpp
                  src/cam_parsers/*.cpp
                  src/utilities/*.cpp )



add_library(manifoldReconstructor SHARED ${meshlib_SOURCE})

# ------------------------ INSTALLATION ------------------------

install(TARGETS manifoldReconstructor DESTINATION lib)
install(DIRECTORY external/glm/glm/ DESTINATION include/glm)
install(DIRECTORY include/manifoldReconstructor/ DESTINATION include/manifoldReconstructor )
install(DIRECTORY external/rapidjson/ DESTINATION include/rapidjson/)

# --------------------------------------------------------------
