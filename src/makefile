# ███████╗████████╗███████╗██╗███╗   ██╗██████╗ ██████╗  ██████╗
# ██╔════╝╚══██╔══╝██╔════╝██║████╗  ██║██╔══██╗██╔══██╗██╔════╝
# ███████╗   ██║   █████╗  ██║██╔██╗ ██║██████╔╝██████╔╝██║
# ╚════██║   ██║   ██╔══╝  ██║██║╚██╗██║██╔══██╗██╔══██╗██║
# ███████║   ██║   ███████╗██║██║ ╚████║██████╔╝██║  ██║╚██████╗
# ╚══════╝   ╚═╝   ╚══════╝╚═╝╚═╝  ╚═══╝╚═════╝ ╚═╝  ╚═╝ ╚═════╝

# ███████╗███████╗ █████╗ ██████╗  █████╗ ███████╗███████╗██████╗ 
# ██╔════╝██╔════╝██╔══██╗██╔══██╗██╔══██╗██╔════╝██╔════╝██╔══██╗
# ███████╗█████╗  ███████║██████╔╝███████║███████╗███████╗██████╔╝
# ╚════██║██╔══╝  ██╔══██║██╔══██╗██╔══██║╚════██║╚════██║██╔══██╗
# ███████║███████╗██║  ██║██████╔╝██║  ██║███████║███████║██████╔╝
# ╚══════╝╚══════╝╚═╝  ╚═╝╚═════╝ ╚═╝  ╚═╝╚══════╝╚══════╝╚═════╝ 

.PHONY: all library debug deep_debug valgrind_debug test valgrind_test gcov_report clang_n clang_i clean

PROJECT_NAME := s21_BrickGame

#* BUILD
CMAKE_GENERATOR := Unix Makefiles
CMAKE_COMPILATOR := -DCMAKE_C_COMPILER=gcc -DCMAKE_CXX_COMPILER=g++
BUILD_DIR := build/Debug
CMAKE_BUILD := cmake -B ${BUILD_DIR} --preset conan-debug -DCMAKE_BUILD_TYPE=Debug
CMAKE_BUILD_TARGET := cmake --build ${BUILD_DIR} --target

MAIN_TARGET := ${PROJECT_NAME}
MAIN_EXE := ./${BUILD_DIR}/${MAIN_TARGET}


DEBUG_TARGET := debug
DEBUG_EXE := ./${BUILD_DIR}/${DEBUG_TARGET}

DEEP_DEBUG_TARGET := deep_debug
DEEP_DEBUG_EXE := ./${BUILD_DIR}/${DEEP_DEBUG_TARGET}

TEST_TARGET := test_cpp
TEST_DIR := ${BUILD_DIR}
TEST_EXE := ./${TEST_DIR}/test/cpp/${TEST_TARGET}

#* INSTALL 
INSTALL_DIR := ~/${PROJECT_NAME}
INSTALL_FILES := ${BUILD_DIR}/s21_BrickGame ${BUILD_DIR}/snake.so ${BUILD_DIR}/tetris.so ${BUILD_DIR}/cli.so ${BUILD_DIR}/desktop.so


#* TEST
TRF ?= default
CMAKE_TEST_RUN := ctest --rerun-failed --output-on-failure --test-dir ${TEST_DIR} 

#* VALGRIND
# --track-fds=yes
FLAG_VALGRIND := --trace-children=yes --tool=memcheck --leak-check=yes  --track-origins=yes -s


#* LCOV 
gcda_dirs=$(shell find . -type f -name "*.gcda" -exec dirname {} \; | sort | uniq)
lcov_dirs=$(shell for dir in $(gcda_dirs); do echo --directory $$dir; done | tr '\n' ' ')
COVERAGE_INFO := coverage.info
COVERAGE_REPORT := coverage_report


#* CLANG
FIND_DIR := .
FIND := find $(FIND_DIR) -regextype posix-extended -regex ".*\.(cpp|c|cc|h|hpp|inl)$$"
CLANG := clang-format -style=Google


all: s21_BrickGame

install: build 
	${CMAKE_BUILD_TARGET} ${MAIN_TARGET}
	mkdir -p ${INSTALL_DIR}
	cp ${INSTALL_FILES} ${INSTALL_DIR}
	mkdir -p ${INSTALL_DIR}/generators/
	cp ${BUILD_DIR}/generators/qt.conf ${INSTALL_DIR}/generators
	echo "Game installed"

uninstall:
	rm -rf ${INSTALL_DIR}

dist:
	make install INSTALL_DIR="dist/${PROJECT_NAME}"
	tar cf ${PROJECT_NAME}.tar -C dist .

dvi:
	doxygen

build:
	conan install . --build=missing -s build_type=Debug -c tools.system.package_manager:mode=install -c tools.system.package_manager:sudo=True
	${CMAKE_BUILD}

s21_BrickGame: build
	${CMAKE_BUILD_TARGET} ${MAIN_TARGET}
	${MAIN_EXE}

debug: build
	${CMAKE_BUILD_TARGET} ${DEBUG_TARGET}
	${DEBUG_EXE}

deep_debug: build
	${CMAKE_BUILD_TARGET} ${DEEP_DEBUG_TARGET}
	${DEEP_DEBUG_EXE}

valgrind_debug: build
	${CMAKE_BUILD_TARGET} ${DEBUG_TARGET}
	valgrind $(FLAG_VALGRIND) ${DEBUG_EXE}

test: build
	rm -rf ${COVERAGE_REPORT} ${COVERAGE_INFO}
	${CMAKE_BUILD_TARGET} ${TEST_TARGET}
ifeq (${TRF}, default)
		${TEST_EXE}
else 
		${CMAKE_TEST_RUN}
endif

valgrind_test: build
	${CMAKE_BUILD_TARGET} ${TEST_TARGET}
	valgrind $(FLAG_VALGRIND) ${TEST_EXE}

gcov_report: test
	lcov --gcov-tool gcov --capture ${lcov_dirs} --output-file ${COVERAGE_INFO} --base-directory . --no-external --rc lcov_branch_coverage=1 --include '*/src/*'
	genhtml ${COVERAGE_INFO} --output-directory ${COVERAGE_REPORT}

clang_check:
	@${FIND} -exec ${CLANG} -n {} \;

clang_format:
	@${FIND} -exec ${CLANG} -i {} \;

clean:
	rm -rf build ${BUILD_DIR} ${COVERAGE_REPORT} ${COVERAGE_INFO} doxygen dist s21_BrickGame.tar include db.sqlite CMakeUserPresets.json

mm:
	CONAN_VERBOSE_TRACEBACK=1 CONAN_LOGGING_LEVEL=10 conan install . --build=missing -s build_type=Debug -c tools.system.package_manager:mode=install -c tools.system.package_manager:sudo=True
	cmake --preset conan-debug -DCMAKE_BUILD_TYPE=Debug
	cmake --build build/Debug
	./build/Debug/s21_BrickGame

mr:
	cmake -B build -DCMAKE_BUILD_TYPE=Debug
	cmake --build build/
	./build/desktop


