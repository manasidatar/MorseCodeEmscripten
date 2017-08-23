#ifndef __MORSECODECONVERTER_H__
#define __MORSECODECONVERTER_H__

#include <string>
#include <map>
#include <vector>

#ifdef __EMSCRIPTEN__
#include <emscripten/bind.h>

using namespace emscripten;
#endif

#ifndef __EMSCRIPTEN__
// DLL import/export definitions
#ifdef MORSECODECONVERTER_EXPORTS
#define MORSECODECONVERTER_API __declspec(dllexport)
#else
#define MORSECODECONVERTER_API __declspec(dllimport)
#endif

//! Main class for MorseCodeConverter.
class MORSECODECONVERTER_API MorseCodeConverter
#else
class MorseCodeConverter
#endif
{
public:
  MorseCodeConverter();
  ~MorseCodeConverter();

  virtual int setInputString(const std::string& inStr);

  virtual int performConversion();

  virtual std::string getConvertedString();

protected:
  std::string m_sText;
  std::string m_sMorse;
  bool m_textToMorse;

  std::map<char, std::string> m_mT2M;
  std::map<std::string, char> m_mM2T;


  int t2m(); // convert text string to Morse string
  int m2t(); // convert Morse string to text string

  // utility function
  std::vector<std::string> splitStringOnDelim(const std::string& inStr, const std::string& delim);

private:
  MorseCodeConverter(const MorseCodeConverter&); //! Copy constructor, **not implemented**!
  MorseCodeConverter& operator=(const MorseCodeConverter&); //! Assignment operator, **not implemented**!
};

#ifdef __EMSCRIPTEN__
EMSCRIPTEN_BINDINGS(my_class_example) {
  class_<MorseCodeConverter>("MorseCodeConverter")
    .constructor<>()
    .function("setInputString", &MorseCodeConverter::setInputString)
    .function("performConversion", &MorseCodeConverter::performConversion)
    .function("getConvertedString", &MorseCodeConverter::getConvertedString)
    //.class_function("getStringFromInstance", &MyClass::getStringFromInstance)
    ;
}
#endif

#endif
