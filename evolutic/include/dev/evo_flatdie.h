#pragma once

#include "sys/evo_types.h"

namespace evolutic {

class FlatDie {
protected:
  struct InternalData {
    u8 value : 3;
    u8 unused : 5;

    // Constructor to initialize bit fields
    InternalData() : value(1), unused(0) {}
  };

  RGB *led_buffer = nullptr;
  RGB value_color = {64, 64, 64};
  RGB backlight_color = {64, 0, 0};

  InternalData data;

public:
  void init(void *led_buffer);

  void setValue(u8 value);

  void updateLed();
};

} // namespace evolutic
