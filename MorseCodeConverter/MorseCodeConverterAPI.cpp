#include <iostream>
#include <string>

#include "MorseCodeConverterAPI.h"

extern "C"
{
  const char* convertToMorse(const char* inText)
  {
    MorseCodeConverter *testConverter = new MorseCodeConverter();
    std::string outStr("");
    testConverter->setTextString(inText);
    testConverter->performConversion();
    testConverter->getConvertedString(outStr);
    delete testConverter;
    return outStr.c_str();
  }

  const char* convertToText(const char* inMorse)
  {
    MorseCodeConverter *testConverter = new MorseCodeConverter();
    std::string outStr("");
    testConverter->setMorseString(inMorse);
    testConverter->performConversion();
    testConverter->getConvertedString(outStr);
    delete testConverter;
    return outStr.c_str();
  }
}
