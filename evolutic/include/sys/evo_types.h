#ifndef SYS_EVO_TYPES_H
#define SYS_EVO_TYPES_H

#pragma once

namespace evolutic {
using u8 = unsigned char;

struct RGB {
  union {
    struct {
      u8 r;
      u8 g;
      u8 b;
    };
    u8 rgb[3];
  };
};
} // namespace evolutic

#endif
