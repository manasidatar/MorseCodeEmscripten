//#include <iostream>
//#include <string>
//
//#include "MorseCodeConverterAPI.cpp"
//
//int main(int argc, char** argv)
//{
//  //// initialize
//  //MorseCodeConverter *testConverter = new MorseCodeConverter();
//  //std::string outStr("");
//
//  //// perform conversion
//  //testConverter->setTextString("dummy");
//  //testConverter->performConversion();
//  //testConverter->getConvertedString(outStr);
//  //std::cout << outStr << std::endl;
//
//  //// clean up
//  //delete testConverter;
//
//  std::cout << convertToMorse(std::string("dummy").c_str());
//
//  return 0;
//}

#include <iostream>
#include <string>

#include "MorseCodeConverter.h"

int main(int argc, char** argv)
{
  // initialize
  MorseCodeConverter *testConverter = new MorseCodeConverter();
  std::string outStr("");

  // perform conversion
  testConverter->setTextString("dummy");
  testConverter->performConversion();
  testConverter->getConvertedString(outStr);
  std::cout << outStr << std::endl;

  // clean up
  delete testConverter;

  return 0;
}

