#ifndef __TEST_H__
#define __TEST_H__


#include <filesystem>

#include <gtest/gtest.h>

#define private public
#include "../core/Object.hpp"
#undef private

#include "../core/Settings.hpp"

extern std::string path;


#endif // __TEST_H__