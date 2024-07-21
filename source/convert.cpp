# include <string>
# include <unordered_map>
# include <vector>
# include <iostream>
using namespace std;

# include "encyclopedia.hpp"
# include "settings.hpp"


const unordered_map<char, vector<bool>> charToMorse = buildCTM();
const unordered_map<vector<bool>, char> morseToChar = buildMTC();

class Encoder {};

class Decoder {};

string convertText (const string& text, const ConversionSettings& settings = ConversionSettings()) {
    string morseCode;
    char character;
    unordered_map<char, vector<bool>>::const_iterator pos;
    for (int i = 0; i < text.size(); ++ i)
    {
        character = text[i];
        if (character != ' ' and character != '\n') {
            pos = charToMorse.find(tolower(character));
            if (pos == charToMorse.end()){
                cout << "[WRN] ignoring {" << string(1, character) << "}, which cannot be converted to Morse Code" << endl;
            } else {
                for (bool signal : pos->second){
                    signal ? morseCode.push_back(settings.longSignal()) : morseCode.push_back(settings.shortSignal());
                }
                if (i < text.size() - 1){
                    if (text[i + 1] == '\n')
                    {
                        morseCode += '\n';
                    }
                    else if (text[i + 1] == ' ')
                    {
                        morseCode += settings.wordSep();
                    } else {
                        morseCode += settings.letterSep();
                    }
                }
            }
        }
    }
    return morseCode;
}

int endOfLetter(const string& morse, int index, const ConversionSettings& settings)
{
    int n = morse.size(), offset = 0;
    for (const char character : settings.letterSep())
    {
        if (index < n and morse[index] == character)
        {
            ++ index;
            ++ offset;
        } else
        {
            return 0;
        }
    }
    return offset;
}


int endOfWord(const string& morse, int index, const ConversionSettings& settings)
{
    int n = morse.size(), offset = 0;
    for (const char character : settings.wordSep())
    {
        if (index < n and morse[index] == character)
        {
            ++ index;
            ++ offset;
        } else
        {
            return 0;
        }
    }
    return offset;
}


string convertMorse (const string& morse, const ConversionSettings& settings = ConversionSettings()) {
    string convertedText;
    int n = morse.size(), offset;
    vector<bool> currentLetter;
    for (int i = 0; i < n; ++ i)
    {
        if (morse[i] == settings.shortSignal())
        {
            currentLetter.push_back(0);
        } else if (morse[i] == settings.longSignal())
        {
            currentLetter.push_back(1);
        } else {
            offset = endOfWord(morse, i, settings);
            if (offset or morse[i] == '\n')
            {
                i += (morse[i] == '\n' ? offset : offset - 1);
                const auto& pos = morseToChar.find(currentLetter);
                if (pos != morseToChar.end())
                {
                    convertedText.push_back(pos->second);
                } else {
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
                const auto& pos = morseToChar.find(currentLetter);
                if (pos != morseToChar.end())
                {
                    convertedText.push_back(pos->second);
                } else {
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
            cout << "[WRN] ignoring {" << morse[i] << "}, unlisted in conversion settings" << endl;
        }
    } if (currentLetter.size()) 
    {
        const auto& pos = morseToChar.find(currentLetter);
        if (pos != morseToChar.end())
        {
            convertedText.push_back(pos->second);
        } else {
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
