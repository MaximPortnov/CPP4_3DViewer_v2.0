#include "test.hpp"

std::string path;

int main(int argc, char **argv) {
  path = std::filesystem::absolute(argv[0]).string();
  path = path.substr(0, path.rfind('/')+1);
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}