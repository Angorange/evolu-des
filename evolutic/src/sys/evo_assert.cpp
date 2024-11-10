#include "sys/evo_assert.h"
#include <Arduino.h>

namespace evolutic::details {

#if !EVO_NOASSERT

void handleAssertionFailure(const char *condition, const char *file, int line,
                            const char *function, const char *format, ...) {
  Serial.print("Assertion failed: (");
  Serial.print(condition);
  Serial.print("), function ");
  Serial.print(function);
  Serial.print(", file ");
  Serial.print(file);
  Serial.print(", line ");
  Serial.print(line);
  Serial.println(".");

  if (format) { // If a format string is provided
    char _assert_buffer[256];
    va_list args;
    va_start(args, format);
    vsnprintf(_assert_buffer, sizeof(_assert_buffer), format, args);
    va_end(args);
    Serial.print("Message: ");
    Serial.println(_assert_buffer);
  }
  abort(); // Stop the program
}
#endif
} // namespace evolutic::details
