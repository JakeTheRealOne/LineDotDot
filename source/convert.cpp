/**
 * @file convert.cpp
 * @author JakeTheRealOne (jakelevrai@outlook.be)
 * @brief Source file of Encoder and Decoder namespaces
 * @version 0.1
 * @date 21-07-2024
 * 
 * @copyright Copyright (c) 2024
 * 
 */
// #### Std inclusions: ####
# include <cctype>
# include <iostream>
# include <locale>
# include <string>
# include <unordered_map>
# include <vector>
using namespace std;

// #### Intern inclusions: ####
# include "../header/convert.hpp"
# include "../header/encyclopedia.hpp"
# include "../header/settings.hpp"


const unordered_map<wchar_t, vector<bool>> charToMorse = buildCTM();
const unordered_map<vector<bool>, wchar_t> morseToChar = buildMTC();
const locale userLocal("");

wstring Encoder::convert(const wstring &text,
                        const ConversionSettings &settings)
  {
  wstring morseCode;
  wchar_t character;
  for (int i = 0; i < text.size(); ++i)
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


wstring Decoder::convert(const wstring &morse,
                        const ConversionSettings &settings)
  {
  wstring convertedText;
  int n = morse.size(), offset;
  vector<bool> currentLetter;
  for (int i = 0; i < n; ++i)
  {
    if (morse[i] == settings.shortSignal())
    {
      currentLetter.push_back(0);
    } else if (morse[i] == settings.longSignal())
    {
      currentLetter.push_back(1);
    } else
    {
      offset = endOfWord(morse, i, settings);
      if (offset or morse[i] == '\n')
      {
        i += (morse[i] == '\n' ? offset : offset - 1);
        const auto &pos = morseToChar.find(currentLetter);
        if (pos != morseToChar.end())
        {          convertedText.push_back(pos->second);
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
        convertedText.push_back(morse[i] == '\n' ? '\n' : ' ');
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
      cout << "[WRN] ignoring {" << morse[i]
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