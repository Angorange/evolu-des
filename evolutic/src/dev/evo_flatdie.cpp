#include "dev/evo_flatdie.h"
#include "sys/evo_assert.h"
#include "sys/evo_utils.h"
#include <Arduino.h>

// Here is the LED order for a FlatDie

// [6]   [2]
// [5][3][1]
// [4]   [0]

// Backlight: 7

namespace evolutic {

static constexpr u8 DieNumber[] = {
    setBit8(3),
    setBit8(4) | setBit8(2),
    setBit8(6) | setBit8(3) | setBit8(0),
    setBit8(6) | setBit8(2) | setBit8(0) | setBit8(4),
    setBit8(6) | setBit8(2) | setBit8(0) | setBit8(4) | setBit8(3),
    setBit8(6) | setBit8(2) | setBit8(0) | setBit8(4) | setBit8(5) | setBit8(1),
};

void FlatDie::init(void *led_buffer) {
  this->led_buffer = static_cast<RGB *>(led_buffer);
}

void FlatDie::setValue(u8 value) {
  ASSERT(value >= 1 && value <= 6, "value is %u", value);
  data.value = value - 1;
}

void FlatDie::updateLed() {
  u8 const Bits = DieNumber[data.value];

  u8 mask = 1;
  for (u8 i = 0; i < 7; ++i) {
    led_buffer[i] = ((Bits & mask) != 0) ? value_color : RGB{0, 0, 0};
    mask <<= 1;
  }
}

} // namespace evolutic
