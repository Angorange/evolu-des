#include <Arduino.h>
#include "sys/evo_assert.h"
#include "sys/evo_utils.h"
#include "dev/evo_flatdie.h"

// Here is the LED order for a FlatDie

// [6]   [2]
// [5][3][1]
// [4]   [0]

// Backlight: 7

namespace evolutic
{

    static constexpr u8 gs_dieNumber[] =
    {
        setBit8(3),
        setBit8(4) | setBit8(2),
        setBit8(6) | setBit8(3) | setBit8(0),
        setBit8(6) | setBit8(2) | setBit8(0) | setBit8(4),
        setBit8(6) | setBit8(2) | setBit8(0) | setBit8(4) | setBit8(3),
        setBit8(6) | setBit8(2) | setBit8(0) | setBit8(4) | setBit8(5) | setBit8(1),
    };

    void FlatDie::init(void* led_buffer)
    {
        led_buffer_ = static_cast<RGB *>(led_buffer);
    }

    void FlatDie::setValue(u8 value)
    {
        ASSERT(value >= 1 && value <=6, "value is %u", value);
        data_.value_ = value - 1;
    }
    
    void FlatDie::updateLed()
    {
        u8 const bits = gs_dieNumber[data_.value_];

        // Serial.printf("value: %u -> 0x%x\n", data_.value_, bits);

        u8 mask = 1;
        for (u8 i = 0; i < 7; ++i)
        {
            led_buffer_[i] = ((bits & mask) != 0) ? value_color_ : RGB{0, 0, 0};
            mask <<= 1;
        }
    }

} // namespace evolutic
