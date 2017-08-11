#include <iostream>
#include <string>

#include "MorseCodeConverter.h"

extern "C"
{
  const char* convertToMorse(const char* inText);

  const char* convertToText(const char* inMorse);
}
