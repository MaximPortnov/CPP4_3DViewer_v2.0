cmake_minimum_required(VERSION 3.22)

project(
    s21_BrickGame
    VERSION 1.0
)


include_directories("include")
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_C_STANDARD 11)
set(BUILD_SHARED_LIBS YES)


if(WIN32)
    add_compile_options(/permissive-)
endif()

# find_package(Qt6 REQUIRED)
find_package(Qt6 COMPONENTS Widgets REQUIRED)
# find_package(SQLite3)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)

if(WIN32)
endif()
if(UNIX)
endif()

SET(DESKTOP_LIB Qt6::Widgets)

SET(MAIN_LIB ${MAIN_LIB} )

SET(TEST_LIB ${MAIN_LIB} -lm -lcheck -pthread -lsubunit -lgcov)


SET(MAIN_FLAGS -Wall)
IF(UNIX)
    SET(MAIN_FLAGS ${MAIN_FLAGS} -Wextra)
endif()

SET(TEST_FLAGS ${MAIN_FLAGS} -fprofile-arcs -ftest-coverage)

message(
    STATUS
    "FLAGS
  MAIN_FLAGS             : ${MAIN_FLAGS}
  DEBUG_FLAGS       : ${DEBUG_FLAGS}
  DEEP_DEBUG_FLAGS  : ${DEEP_DEBUG_FLAGS}
  TEST_FLAGS        : ${TEST_FLAGS}
    "
)


file(GLOB_RECURSE TETRIS_LOGICAL_FILES "brick_game/tetris/*.c")
file(GLOB_RECURSE SNAKE_LOGICAL_FILES "brick_game/snake/*.cpp")

file(GLOB_RECURSE CLI_FILES "gui/cli/*.c")
file(GLOB_RECURSE DESKTOP_FILES "gui/desktop/*.cpp")
file(GLOB_RECURSE UI_FILES "gui/desktop/desktop.ui")

file(GLOB_RECURSE CONTROL_FILES "control/main.cpp")

file(GLOB_RECURSE TEST_FILES "test/c/*.cpp" "test/c/*.c" "test/c/*.h")

qt_wrap_ui(UI_HEADERS ${UI_FILES})
message(STATUS "lakjsbflasjkdbflkjadshhf ${UI_HEADERS}")


function(create_library target_name)
    set(multiArgs FILES FLAGS LIBS DEFS)
    cmake_parse_arguments(TARGET "" "" "${multiArgs}" ${ARGN})
    if (NOT DEFINED TARGET_FILES)
        message(ERROR "NOT DEFINED TARGET_FILES")
        return()
    endif()
    add_library(
        ${target_name}
        ${TARGET_FILES}
    )

    set_target_properties(${target_name} PROPERTIES OUTPUT_NAME ${target_name} PREFIX "")

    if(DEFINED TARGET_FLAGS)
        target_compile_options(${target_name} PRIVATE ${TARGET_FLAGS})
    endif()
    if (DEFINED TARGET_LIBS)
        target_link_libraries(${target_name} ${TARGET_LIBS})
    endif()
    if (DEFINED TARGET_DEFS)
        target_compile_definitions(${target_name} PRIVATE ${TARGET_DEFS})
    endif()

endfunction(create_library)

function(create_target target_name)
    set(multiArgs FILES FLAGS LIBS DEFS)
    cmake_parse_arguments(TARGET "" "NAME"
                          "${multiArgs}" ${ARGN} )
    message(
        "
        target_name: ${target_name}
        TARGET_FILES: ${TARGET_FILES}
        TARGET_FLAGS: ${TARGET_FLAGS}
        TARGET_LIBS: ${TARGET_LIBS}
        TARGET_DEFS: ${TARGET_DEFS}
        "
    )

    if (NOT DEFINED TARGET_FILES)
        message(ERROR "NOT DEFINED TARGET_FILES")
        return()
    endif()

    add_executable(${target_name} ${TARGET_FILES})
    if(DEFINED TARGET_FLAGS)
        target_compile_options(${target_name} PRIVATE ${TARGET_FLAGS})
    endif()
    if (DEFINED TARGET_LIBS)
        target_link_libraries(${target_name} ${TARGET_LIBS})
    endif()
    if (DEFINED TARGET_DEFS)
        target_compile_definitions(${target_name} PRIVATE ${TARGET_DEFS})
    endif()
endfunction()

####################################
# create_library(tetris FILES ${TETRIS_LOGICAL_FILES} FLAGS ${MAIN_FLAGS} LIBS ${MAIN_LIB})
# create_library(tetris_test FILES ${TETRIS_LOGICAL_FILES} FLAGS ${TEST_FLAGS} LIBS ${TEST_LIB} DEFS MYDEBUG)
# create_library(snake FILES ${SNAKE_LOGICAL_FILES} FLAGS ${MAIN_FLAGS} LIBS ${MAIN_LIB})
# create_library(snake_test FILES ${SNAKE_LOGICAL_FILES} FLAGS ${TEST_FLAGS} LIBS ${TEST_LIB} DEFS MYDEBUG)

# create_library(cli FILES ${CLI_FILES} FLAGS ${MAIN_FLAGS} LIBS ${CLI_LIB} )

# create_target(MOC_SOURCES  "gui/desktop/desktop.h")
create_target(desktop FILES ${DESKTOP_FILES} ${MOC_SOURCES} ${UI_HEADERS} FLAGS ${MAIN_FLAGS} LIBS ${DESKTOP_LIB})
target_include_directories(desktop PRIVATE ${CMAKE_CURRENT_BINARY_DIR})

# create_target(test_c FILES ${TEST_FILES} FLAGS ${TEST_FLAGS} LIBS ${TEST_LIB} tetris_test DEFS MYDEBUG)

# create_target(s21_BrickGame FILES ${CONTROL_FILES} ${MOC_SOURCES} ${UI_HEADERS}  FLAGS ${MAIN_FLAGS} LIBS ${MAIN_LIB} tetris snake cli desktop)

# add_subdirectory("test")
