# include <string>
# include <unordered_map>
# include <vector>
# include <iostream>
# include "encyclopedia.hpp"
using namespace std;


const unordered_map<char, vector<bool>> charToMorse = buildCTM();
const unordered_map<vector<bool>, char> morseToChar = buildMTC();

class Encoder {};

class Decoder {};

string convertText (const string& text, const char shortSignal = '.', const char longSignal = '-', const string& letterSep = " ", const string& wordSep = "  ") {
    string morseCode;
    char character;
    unordered_map<char, vector<bool>>::const_iterator pos;
    for (int i = 0; i < text.size(); ++ i) {
        character = text[i];
        if (character == '\n'){
            morseCode.push_back(character);
        } else if (character != ' ') {
            pos = charToMorse.find(tolower(character));
            if (pos == charToMorse.end()){
                cout << "[WRN] ignoring {" << string(1, character) << "}, which cannot be converted to Morse Code" << endl;
            } else {
                for (bool signal : pos->second){
                    signal ? morseCode.push_back(longSignal) : morseCode.push_back(shortSignal);
                }
                if (i < text.size() - 1){
                    if (text[i + 1] == ' '){
                        morseCode += wordSep;
                    } else {
                        morseCode += letterSep;
                    }
                }
            }
        }
    }
    return morseCode;
}

vector<string> splitWord(const string& word, const string& letterSep) {
    vector<string> splitted;
    string letter;
    int i = 0, j = word.find(letterSep, i), n = word.size(), m = letterSep.size();
    while (j != -1) {
        // separe letters of morse[i:j]
        letter = word.substr(i, j - i);
        splitted.push_back(letter);
        i = j + m;
        j = word.find(letterSep, i);

    } if (i != n) {
        letter = word.substr(i, j - i);
        splitted.push_back(letter);
    }
    return splitted;
}

vector<vector<string>> splitMorse(const string& morse, const string& letterSep, const string& wordSep) {
    vector<vector<string>> splitted;
    int i = 0, j = morse.find(wordSep, 0), n = morse.size(), m = wordSep.size();
    string word;
    while (j != -1) {
        // separe letters of morse[i:j]
        word = morse.substr(i, j - i);
        splitted.push_back(splitWord(word, letterSep));
        i = j + m;
        j = morse.find(wordSep, i);

    } if (i != n) {
        word = morse.substr(i, j - i);
        splitted.push_back(splitWord(word, letterSep));
    }
    return splitted;
};

vector<bool> convertToBool(const string& morseLetter, const char longSignal, const char shortSignal) {
    vector<bool> letter;
    letter.reserve(morseLetter.size());
    for (const char signal : morseLetter) {
        if (signal == longSignal) {
                letter.push_back(true);
        } else if (signal == shortSignal) {
                letter.push_back(false);
        } else {
                cout << "[WRN] ignoring {" << string(1, signal) << "}, which is unlisted in the conversion settings" << endl;
        }
    }
    return letter;
}

string convertMorse (const string& morse, const char shortSignal = '.', const char longSignal = '-', const string& letterSep = " ", const string& wordSep = "  ") {
    string translatedText;
    char character;
    unordered_map<vector<bool>, char>::const_iterator pos;
    vector<vector<string>> morseWords = splitMorse(morse, letterSep, wordSep);
    vector<bool> morseLetter;
    for (const vector<string>& word : morseWords) {
        for (const string& letter : word) {
            morseLetter = convertToBool(letter, longSignal, shortSignal);
            pos = morseToChar.find(morseLetter);
            if (pos == morseToChar.end()) {
                cout << "[WRN] ignoring {" << letter << "}, which is not a morse character" << endl;
            } else {
                translatedText.push_back(pos->second);
            }
        }
        translatedText.push_back(' ');
    }
    translatedText.pop_back();
    return translatedText;
}