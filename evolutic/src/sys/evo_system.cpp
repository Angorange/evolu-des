#include "sys/evo_system.h"
#include <Arduino.h>

namespace evolutic {
void init() {
  Serial.begin(115200);
  Serial.println("Evolutic System Initialized!");
}
} // namespace evolutic
