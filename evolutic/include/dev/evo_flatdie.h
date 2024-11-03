#pragma once

#include "sys/evo_types.h"

namespace evolutic
{

class FlatDie
{
protected:
    struct InternalData
    {
        u8 value_ : 3;
        u8 unused_ : 5;

        // Constructor to initialize bit fields
        InternalData() : value_(1), unused_(0) {}
    };

    RGB* led_buffer_ = nullptr;
    RGB value_color_ = {64, 64, 64};
    RGB backlight_color_ = {64, 0, 0};

    InternalData data_;

public:
    void init(void* led_buffer);

    void setValue(u8 value);

    void updateLed();
};

} // namespace evolutic
