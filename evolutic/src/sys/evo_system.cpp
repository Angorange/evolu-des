#include <Arduino.h>
#include "sys/evo_system.h"

namespace evolutic
{
    void init()
    {
        Serial.begin(115200);
        Serial.println("Evolutic System Initialized!");
    }
}
