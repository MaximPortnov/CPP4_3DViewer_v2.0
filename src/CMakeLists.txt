cmake_minimum_required(VERSION 3.22)

project(
    3DViewer_v2
    VERSION 2.0
)

set (CMAKE_MODULE_PATH "${CMAKE_MODULE_PATH};${CMAKE_CURRENT_SOURCE_DIR}/cmake")

include(utils)

file(COPY ${CMAKE_SOURCE_DIR}/obj_files/ DESTINATION ${CMAKE_BINARY_DIR}/obj_files)

include_directories("include")
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_C_STANDARD 11)
set(BUILD_SHARED_LIBS YES)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)

if(WIN32)
    add_compile_options(/permissive-)
endif()

find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)

# LIBS
if(WIN32)
    find_package(Qt6 )
    SET(DESKTOP_LIB qt::qt )
elseif(UNIX)
    find_package(Qt6 COMPONENTS Widgets OpenGL OpenGLWidgets REQUIRED)
    SET(DESKTOP_LIB Qt6::Widgets Qt6::OpenGL Qt6::OpenGLWidgets)
endif()




SET(MAIN_LIB ${MAIN_LIB} )
SET(TEST_LIB ${MAIN_LIB} core)

# FLAGS
SET(MAIN_FLAGS -Wall)
IF(UNIX)
    SET(MAIN_FLAGS ${MAIN_FLAGS} -Wextra)
endif()

SET(TEST_FLAGS ${MAIN_FLAGS} -fprofile-arcs -ftest-coverage)

message(
    STATUS
    "FLAGS
  MAIN_FLAGS        : ${MAIN_FLAGS}
  TEST_FLAGS        : ${TEST_FLAGS}
    "
)


# FILES
# file(GLOB_RECURSE TETRIS_LOGICAL_FILES "brick_game/tetris/*.c")
file(GLOB_RECURSE CORE_FILES "core/*.cpp")

file(GLOB_RECURSE DESKTOP_FILES "gui/*.cpp" "gui/*.h" "gui/*.ui")

# file(GLOB_RECURSE CONTROL_FILES "control/main.cpp")



####################################
# create_library(tetris FILES ${TETRIS_LOGICAL_FILES} FLAGS ${MAIN_FLAGS} LIBS ${MAIN_LIB})
# create_library(tetris_test FILES ${TETRIS_LOGICAL_FILES} FLAGS ${TEST_FLAGS} LIBS ${TEST_LIB} DEFS MYDEBUG)
# create_library(snake FILES ${SNAKE_LOGICAL_FILES} FLAGS ${MAIN_FLAGS} LIBS ${MAIN_LIB})
# create_library(snake_test FILES ${SNAKE_LOGICAL_FILES} FLAGS ${TEST_FLAGS} LIBS ${TEST_LIB} DEFS MYDEBUG)

create_library(core FILES ${CORE_FILES} FLAGS ${MAIN_FLAGS} LIBS ${MAIN_LIB} )


create_target(${PROJECT_NAME} FILES ${DESKTOP_FILES} FLAGS ${MAIN_FLAGS} LIBS ${DESKTOP_LIB})

# create_target(s21_BrickGame FILES ${CONTROL_FILES} ${MOC_SOURCES} ${UI_HEADERS}  FLAGS ${MAIN_FLAGS} LIBS ${MAIN_LIB} tetris snake cli desktop)

add_subdirectory("test")
