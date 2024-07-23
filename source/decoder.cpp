/**
 * @file decoder.cpp
 * @author JakeTheRealOne (jakelevrai@outlook.be)
 * @brief Source file for the morse Decoder
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
# include "../header/decoder.hpp"
# include "../header/settings.hpp"
# include "../header/encyclopedia.hpp"


const unordered_map<vector<bool>, wchar_t> morseToChar = buildMTC();
const static locale userLocal("");


wstring Decoder::convert(const wstring &morse,
                        const ConversionSettings &settings)
  {
  wstring convertedText;
  unsigned long n = morse.size(), offset;
  wchar_t character; 
  vector<bool> currentLetter;
  for (unsigned long i = 0; i < n; ++i)
  {
    character = morse[i];
    if (character == settings.shortSignal())
    {
      currentLetter.push_back(0);
    } else if (character == settings.longSignal())
    {
      currentLetter.push_back(1);
    } else
    {
      offset = endOfWord(morse, i, settings);
      if (offset or character == '\n')
      {
        i += (character == '\n' ? offset : offset - 1);
        const auto &pos = morseToChar.find(currentLetter);
        if (pos != morseToChar.end())
        {          convertedText.push_back(pos->second);
        } else
        {
          cout << "[WRN] ignoring [";
          for (const bool signal : currentLetter)
          {
            wcout << (signal ? settings.longSignal() : settings.shortSignal());
          }
          cout << "], is a not a morse letter" << endl;
        }
        currentLetter.clear();
        convertedText.push_back(character == '\n' ? '\n' : ' ');
        continue;
      }
      offset = endOfLetter(morse, i, settings);
      if (offset)
      {
        i += offset - 1;
        const auto &pos = morseToChar.find(currentLetter);
        if (pos != morseToChar.end())
        {
          convertedText.push_back(pos->second);
        } else
        {
          cout << "[WRN] ignoring [";
          for (const bool signal : currentLetter)
          {
            cout << (signal ? settings.longSignal() : settings.shortSignal());
          }
          cout << "], is a not a morse letter" << endl;
        }
        currentLetter.clear();
        continue;
      }
      cout << "[WRN] ignoring {" << character
           << "}, unlisted in conversion settings" << endl;
    }
  }
  if (currentLetter.size())
  {
    const auto &pos = morseToChar.find(currentLetter);
    if (pos != morseToChar.end())
    {
      convertedText.push_back(pos->second);
    } else
    {
      cout << "[WRN] ignoring [";
      for (const bool signal : currentLetter)
      {
        cout << (signal ? settings.longSignal() : settings.shortSignal());
      }
      cout << "], is a not a morse letter" << endl;
    }
    currentLetter.clear();
  }
  return convertedText;
}


int Decoder::endOfWord(const wstring &morse, int index,
                       const ConversionSettings &settings)
  {
  int n = morse.size(), offset = 0;
  for (const char character : settings.wordSep())
  {
    if (index < n and morse[index] == character)
    {
      ++index;
      ++offset;
    } else
    {
      return 0;
    }
  }
  return offset;
}


int Decoder::endOfLetter(const wstring &morse, int index,
                         const ConversionSettings &settings)
{
  int n = morse.size(), offset = 0;
  for (const char character : settings.letterSep())
  {
    if (index < n and morse[index] == character)
    {
      ++index;
      ++offset;
    } else
    {
      return 0;
    }
  }
  return offset;
}