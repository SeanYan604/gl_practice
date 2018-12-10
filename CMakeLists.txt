cmake_minimum_required(VERSION 3.0)
project(OpenGL_c)

set(CMAKE_CXX_STANDARD 11)

find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)
find_package(OpenCV 3.0.0 REQUIRED)
include_directories(library ${OPENGL_INCLUDE_DIRS} ${GLUT_INCLUDE_DIRS} ${OPENCV_INCLUDE_DIRS})

add_executable(opengl_first first.cpp)
target_link_libraries(opengl_first ${OPENGL_LIBRARIES} ${GLUT_LIBRARIES})

add_executable(triangle triangle.cpp)
target_link_libraries(triangle ${OPENGL_LIBRARIES} ${GLUT_LIBRARIES})

add_executable(texture texture.cpp)
target_link_libraries(texture ${OPENGL_LIBRARIES} ${GLUT_LIBRARIES})

add_executable(texture2 texture2.cpp)
target_link_libraries(texture2 ${OPENGL_LIBRARIES} ${GLUT_LIBRARIES})

add_executable(lookarround lookarround.cpp)
target_link_libraries(lookarround ${OPENGL_LIBRARIES} ${GLUT_LIBRARIES} ${OpenCV_LIBRARIES})
