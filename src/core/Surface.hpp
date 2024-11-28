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
  Node first;
  Node second;
  Node third;
};

}  // namespace s21

#endif  // __SURFACE_H__