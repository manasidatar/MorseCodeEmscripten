#include <iostream>
#include <string>
#include "MorseCodeConverter.h"

int main(int argc, char** argv)
{
  // check if string is given
  if (argc != 2)
  {
    std::cout << "Enter regular text or Morse code" << std::endl <<
      "Morse code rule: single space separating alphabets, double space separating words." <<
      std::endl;

    return -1;
  }

  // initialize
  MorseCodeConverter *testConverter = new MorseCodeConverter();
  std::string outStr("");

  std::string inStr(argv[1]);

  // perform conversion
  if (inStr[0] == '.' || inStr[0] == '-')
    testConverter->setMorseString(inStr);
  else
    testConverter->setTextString(inStr);

  testConverter->performConversion();
  outStr = testConverter->getConvertedString();
  std::cout << inStr << " --> " << outStr << std::endl;

  // clean up
  delete testConverter;

  return 0;
}
