#ifndef __SURFACE_H__
#define __SURFACE_H__

#include <cstddef>

namespace s21 {
struct Surface {
 private:
  struct Node {
    std::size_t vertex_index;
  };

 public:
  std::array<Node, 3> nodes;
};

}  // namespace s21

#endif  // __SURFACE_H__