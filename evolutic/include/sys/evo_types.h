#pragma once

namespace evolutic
{
    using u8 = unsigned char;

    struct RGB
    {
        union
        {
            struct
            {
                u8 r_;
                u8 g_;
                u8 b_;
            };
            u8 rgb[3];
        };
    };
}
