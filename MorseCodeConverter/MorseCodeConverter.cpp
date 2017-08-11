#include "MorseCodeConverter.h"
#include <sstream>

// constructor
MorseCodeConverter::MorseCodeConverter() : m_sText(""), m_sMorse(""), m_textToMorse(1)
{
  // initialize t2m and m2t maps
  m_mT2M.clear();
  m_mT2M['a'] = ".-";
  m_mT2M['b'] = "-...";
  m_mT2M['c'] = "-.-.";
  m_mT2M['d'] = "-..";
  m_mT2M['e'] = ".";
  m_mT2M['f'] = "..-.";
  m_mT2M['g'] = "--.";
  m_mT2M['h'] = "....";
  m_mT2M['i'] = "..";
  m_mT2M['j'] = ".---";
  m_mT2M['k'] = "-.-";
  m_mT2M['l'] = ".-..";
  m_mT2M['m'] = "--";
  m_mT2M['n'] = "-.";
  m_mT2M['o'] = "---";
  m_mT2M['p'] = ".--.";
  m_mT2M['q'] = "--.-";
  m_mT2M['r'] = ".-.";
  m_mT2M['s'] = "...";
  m_mT2M['t'] = "-";
  m_mT2M['u'] = "..-";
  m_mT2M['v'] = "...-";
  m_mT2M['w'] = ".--";
  m_mT2M['x'] = "-..-";
  m_mT2M['y'] = "-.--";
  m_mT2M['z'] = "--..";
  m_mT2M['1'] = ".----";
  m_mT2M['2'] = "..---";
  m_mT2M['3'] = "...--";
  m_mT2M['4'] = "....-";
  m_mT2M['5'] = ".....";
  m_mT2M['6'] = "-....";
  m_mT2M['7'] = "--...";
  m_mT2M['8'] = "---..";
  m_mT2M['9'] = "----.";
  m_mT2M['0'] = "-----";
  m_mT2M[' '] = " ";

  m_mM2T.clear();
  for (std::map<char, std::string>::iterator i = m_mT2M.begin(); i != m_mT2M.end(); i++)
    m_mM2T[i->second] = i->first;
  m_mM2T[" "] = '\0';
  m_mM2T["  "] = ' ';
}

// destructor
MorseCodeConverter::~MorseCodeConverter()
{
  m_mT2M.clear();
  m_mM2T.clear();

  m_sText = "";
  m_sMorse = "";
}

// protected
  int MorseCodeConverter::t2m()
  {
    // convert input to lowercase
    // split on spaces
    // convert and append
    m_sMorse = "";
    for (int i = 0; i < m_sText.size(); i++)
      m_sMorse += m_mT2M[m_sText[i]];
    return 0;
  }

  int MorseCodeConverter::m2t()
  {
    // split on double spaces

    // split on spaces
    std::vector<std::string> sParts = splitOnSpaces(m_sMorse);

    // convert and append
    m_sText = "";
    for (int i = 0; i < sParts.size(); i++)
      m_sText += m_mM2T[sParts[i]];
    return 0;
  }

  std::vector<std::string> MorseCodeConverter::splitOnSpaces(const std::string& inStr)
  {
    std::vector<std::string> splitStr; splitStr.clear();
    std::stringstream strStream(inStr);
    std::string currPart("");

    while (strStream >> currPart) splitStr.push_back(currPart);

    return splitStr;
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
