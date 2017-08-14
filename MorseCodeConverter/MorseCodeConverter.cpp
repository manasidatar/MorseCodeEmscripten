#include "MorseCodeConverter.h"

#include <sstream>
#include <iostream>
#include <algorithm>

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

// function to convert text to Morse code
  int MorseCodeConverter::t2m()
  {
    // convert input text to lowercase
    std::string tmpStr(m_sText);
    std::transform(tmpStr.begin(), tmpStr.end(), tmpStr.begin(), ::tolower);

    // convert and append
    m_sMorse = "";
    for (int i = 0; i < tmpStr.size(); i++) m_sMorse += m_mT2M[tmpStr[i]] + " ";

    tmpStr = "";
    return 0;
  }

  // function to convert Morse code to text
  int MorseCodeConverter::m2t()
  {
    // split words on double spaces
    std::vector<std::string> morseWords = splitStringOnDelim(m_sMorse, "  ");

    // split letters on single spaces
    std::vector<std::string> morseLetters; morseLetters.clear();
    std::vector<std::string> cWordVec;
    for (int w = 0; w < morseWords.size(); w++)
    {
      cWordVec.clear();
      cWordVec = splitStringOnDelim(morseWords[w], " ");
      morseLetters.insert(morseLetters.end(), cWordVec.begin(), cWordVec.end());
      morseLetters.push_back(" ");
    }
    morseLetters.pop_back(); // remove extra blank space after last word

    // convert and append
    m_sText = "";
    for (int i = 0; i < morseLetters.size(); i++) m_sText += m_mM2T[morseLetters[i]];

    return 0;
  }

  // function to split string based on a given delimiter
  std::vector<std::string> MorseCodeConverter::splitStringOnDelim(const std::string& inStr,
    const std::string& delim)
  {
    std::string tmpStr(inStr);
    std::vector<std::string> splitStr; splitStr.clear();
    std::size_t pos = 0;

    while (pos != std::string::npos)
    {
      pos = tmpStr.find(delim);
      splitStr.push_back(tmpStr.substr(0, pos));
      tmpStr.erase(0, pos + delim.length());
    }

    return splitStr;
  }

// public
int MorseCodeConverter::setTextString(const std::string inStr)
{
  m_sText = inStr;
  m_sMorse = "";
  m_textToMorse = 1;
  return 0;
}

int MorseCodeConverter::setMorseString(const std::string inStr)
{
  m_sMorse = inStr;
  m_sText = "";
  m_textToMorse = 0;
  return 0;
}

int MorseCodeConverter::performConversion()
{
  return (m_textToMorse) ? t2m() : m2t();
}

std::string MorseCodeConverter::getConvertedString()
{
  return (m_textToMorse) ? m_sMorse : m_sText;
}
