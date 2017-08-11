#include "MorseCodeConverter.h"

// constructor
MorseCodeConverter::MorseCodeConverter() : m_sText(""), m_sMorse(""), m_textToMorse(1) {}

// destructor
MorseCodeConverter::~MorseCodeConverter()
{
  // delete map object
  m_sText = "";
  m_sMorse = "";
}

// protected
  int MorseCodeConverter::t2m()
  {
    m_sMorse = "dummy";
    return 0;
  }

  int MorseCodeConverter::m2t()
  {
    m_sText = "dummy";
    return 0;
  }

// public
int MorseCodeConverter::setTextString(const std::string inStr)
{
  m_sText = inStr;   // set text string
  m_sMorse = "";     // clear Morse string
  m_textToMorse = 1; // set boolean for correct conversion
  return 0;
}

int MorseCodeConverter::setMorseString(const std::string inStr)
{
  m_sMorse = inStr;  // set Morse string
  m_sText = "";      // clear text string
  m_textToMorse = 0; // set boolean for correct conversion
  return 0;
}

int MorseCodeConverter::performConversion()
{
  return (m_textToMorse) ? t2m() : m2t();
}

int MorseCodeConverter::getConvertedString(std::string &outString)
{
  outString = (m_textToMorse) ? m_sMorse : m_sText;
  return 0;
}
