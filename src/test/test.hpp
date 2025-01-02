#ifndef __TEST_H__
#define __TEST_H__


#include <filesystem>

#include <gtest/gtest.h>

#define private public
#include "../core/Object.hpp"
#include "../core/Settings.hpp"
#include "../core/TransformMatrix.hpp"
#undef private


extern std::string path;


#endif // __TEST_H__