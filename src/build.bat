

conan install . --build=missing -s build_type=Debug
cmake --preset conan-default -DCMAKE_BUILD_TYPE=Debug
cmake --build build --target tt --config Debug