/**
 * @file encoder.cpp
 * @author JakeTheRealOne (jakelevrai@outlook.be)
 * @brief Source file for the morse Encoder
 * @version 0.1
 * @date 23-07-2024
 * 
 * @copyright Copyright (c) 2024
 * 
 */


// #### Std inclusions: ####
# include <string>
# include <vector>
# include <locale>
# include <iostream>

// #### Internal inclusions: ####
# include "../header/encoder.hpp"
# include "../header/settings.hpp"
# include "../header/encyclopedia.hpp"


const unordered_map<wchar_t, vector<bool>> charToMorse = buildCTM();
const static locale userLocal("");


wstring Encoder::convert(const wstring &text,
                        const ConversionSettings &settings)
  {
  wstring morseCode;
  wchar_t character;
  unsigned long n = text.size();
  for (unsigned long i = 0; i < n; ++i)
  {
    character = tolower(text[i], userLocal);
    if (character != ' ' and character != '\n')
    {
      const auto& pos = charToMorse.find(tolower(character));
      if (pos == charToMorse.end())
      {
        wcout << "[WRN] ignoring {" << wstring(1, character)
             << "}, which cannot be converted to Morse Code" << endl;
      } else
      {
        for (bool signal : pos->second)
        {
          signal ? morseCode.push_back(settings.longSignal())
                 : morseCode.push_back(settings.shortSignal());
        }
        if (i < text.size() - 1)
        {
          if (text[i + 1] == '\n')
          {
            morseCode += L'\n';
          } else if (text[i + 1] == ' ')
          {
            morseCode += settings.wordSep();
          } else
          {
            morseCode += settings.letterSep();
          }
        }
      }
    }
  }
  return morseCode;
}