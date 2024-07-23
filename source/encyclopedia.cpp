/**
 * @file encyclopedia.cpp
 * @author JakeTheRealOne (jakelevrai@outlook.be)
 * @brief Source file for the Morse dictionary
 * @version 0.1
 * @date 2024-07-17
 *
 * @copyright Copyright (c) 2024
 *
 */


# include <string>
# include <unordered_map>
# include <vector>
# include "../header/encyclopedia.hpp"
using namespace std;


const vector<bool> SOS = {0, 0, 0, 1, 1, 1, 0, 0, 0};


const unordered_map<char, vector<string>> ALPHABET = 
{
    {'a', {".-", "Alfa"}},      {'b', {"-...", "Bravo"}},
    {'c', {"-.-.", "Charlie"}}, {'d', {"-..", "Delta"}},
    {'e', {".", "Echo"}},       {'f', {"..-.", "Foxtrot"}},
    {'g', {"--.", "Golf"}},     {'h', {"....", "Hotel"}},
    {'i', {"..", "India"}},     {'j', {".---", "Juliett"}},

    {'k', {"-.-", "Kilo"}},     {'l', {".-..", "Lima"}},
    {'m', {"--", "Mike"}},      {'n', {"-.", "November"}},
    {'o', {"---", "Oscar"}},    {'p', {".--.", "Papa"}},
    {'q', {"--.-", "Quebec"}},  {'r', {".-.", "Romeo"}},
    {'s', {"...", "Sierra"}},   {'t', {"-", "Tango"}},

    {'u', {"..-", "Uniform"}},  {'v', {"...-", "Victor"}},
    {'w', {".--", "Whiskey"}},  {'x', {"-..-", "Xray"}},
    {'y', {"-.--", "Yankee"}},  {'z', {"--..", "Zulu"}},
};


const unordered_map<string, string> MAGIC =
{
  {"International distress call", "...---..."},
  {"Invitation to forward", "-.-"},
  {"Start of message", ".-.-"},
  {"Error by the message sender", "........"},
  {"Adjust your signal lights (Light transmission)", ".-...-."},
  {"Asking for a stronger light (Light transmission)", ".-...-.."},
  {"Asking for a less strong light (Light transmission)", ""},
  {"Asking to slow down", ".--..--."},
  {"Stop (new paragraph)", "....-.."},
  {"End of message (waiting for response)", ".-.-."},
  {"Not understood, please repeat", "..--.."},
  {"Understood", "...-."},
  {"Please wait", ".-..."},
  {"End of contact (leaving the post)", "...-.-"},

};


unordered_map<wchar_t, vector<bool>> buildCTM()
{
    const unordered_map<char, vector<bool>> alphaToMorse =
    {
      {'a', {0, 1}}, {'b', {1, 0, 0, 0}},
      {'c', {1, 0, 1, 0}}, {'d', {1, 0, 0}},
      {'e', {0}}, {'f', {0, 0, 1, 0}},
      {'g', {1, 1, 0}}, {'h', {0, 0, 0, 0}},
      {'i', {0, 0}}, {'j', {0, 1, 1, 1}}, 
      {'k', {1, 0, 1}}, {'l', {0, 1, 0, 0}},
      {'m', {1, 1}}, {'n', {1, 0}},
      {'o', {1, 1, 1}}, {'p', {0, 1, 1, 0}},
      {'q', {1, 1, 0, 1}}, {'r', {0, 1, 0}},
      {'s', {0, 0, 0}}, {'t', {1}},
      {'u', {0, 0, 1}}, {'v', {0, 0, 0, 1}},
      {'w', {0, 1, 1}}, {'x', {1, 0, 0, 1}},
      {'y', {1, 0, 1, 1}}, {'z', {1, 1, 0, 0}},
    };

    const unordered_map<char, vector<bool>> decimalToMorse =
    {
      {'0', {1, 1, 1, 1, 1}},
      {'1', {0, 1, 1, 1, 1}},
      {'2', {0, 0, 1, 1, 1}},
      {'3', {0, 0, 0, 1, 1}},
      {'4', {0, 0, 0, 0, 1}},
      {'5', {0, 0, 0, 0, 0}},
      {'6', {1, 0, 0, 0, 0}},
      {'7', {1, 1, 0, 0, 0}},
      {'8', {1, 1, 1, 0, 0}},
      {'9', {1, 1, 1, 1, 0}},
    };

    const unordered_map<char, vector<bool>> specharToMorse =
    {
      {',', {1, 1, 0, 0, 1, 1}}, {'.', {0, 1, 0, 1, 0, 1}},
      {'?', {0, 0, 1, 1, 0, 0}}, {';', {1, 0, 1, 0, 1, 0}},
      {':', {1, 1, 1, 0, 0, 0}}, {'/', {1, 0, 0, 1, 0}},
      {'-', {1, 0, 0, 0, 0, 1}}, {'\'', {0, 1, 1, 1, 1, 0}},
      {'(', {1, 0, 1, 1, 0}}, {')', {1, 0, 1, 1, 0, 1}},
      {'_', {0, 0, 1, 1, 0, 1}}, {'@', {0, 1, 1, 0, 1, 0}},
      {'!', {1, 0, 1, 0, 1, 1}}, {'&', {0, 1, 0, 0, 0}},
      {'=', {1, 0, 0, 0, 1}}, {'+', {0, 1, 0, 1, 0}},
      {'"', {0, 1, 0, 0, 1, 0}}, {'$', {0, 0, 0, 1, 0, 0, 1}},
    };

    const unordered_map<wchar_t, vector<bool>> acccharToMorse =
    {
      {L'ä', {0, 1, 0, 1}},
      {L'à', {0, 1, 1, 0, 1}},
      {L'ç', {1, 0, 1, 0, 0}},
      {L'ð', {0, 0, 1, 1, 0}},
      {L'è', {0, 1, 0, 0, 1}},
      {L'é', {0, 0, 1, 0, 0}},
      {L'ĝ', {1, 1, 0, 1, 0}},
      {L'ĥ', {1, 0, 1, 1, 0}},
      {L'ĵ', {0, 1, 1, 1, 0}},
      {L'ñ', {1, 1, 0, 1, 1}},
      {L'ö', {1, 1, 1, 0}},
      {L'ŝ', {0, 0, 0, 1, 0}},
      {L'þ', {0, 1, 1, 0, 0}},
      {L'ü', {0, 0, 1, 1}},
    };


    unordered_map<wchar_t, vector<bool>> characterToMorse;
    for (const auto& letter : alphaToMorse)
    {
        characterToMorse.insert(letter);
    } for (const auto& num : decimalToMorse)
    {
        characterToMorse.insert(num);
    } for (const auto& special : specharToMorse)
    {
        characterToMorse.insert(special);
    } for (const auto& accent : acccharToMorse)
    {
      characterToMorse.insert(accent);
    }

    return characterToMorse;
}


unordered_map<vector<bool>, wchar_t> buildMTC()
{
    const unordered_map<vector<bool>, char> morseToAlpha =
    {
        {{0,1,}, 'a'}, {{1,0,0,0,}, 'b'},
        {{1,0,1,0,}, 'c'}, {{1,0,0,}, 'd'},
        {{0,}, 'e'}, {{0,0,1,0,}, 'f'},
        {{1,1,0,}, 'g'}, {{0,0,0,0,}, 'h'},
        {{0,0,}, 'i'}, {{0,1,1,1,}, 'j'},
        {{1,0,1,}, 'k'}, {{0,1,0,0,}, 'l'},
        {{1,1,}, 'm'}, {{1,0,}, 'n'},
        {{1,1,1,}, 'o'}, {{0,1,1,0,}, 'p'},
        {{1,1,0,1,}, 'q'}, {{0,1,0,}, 'r'},
        {{0,0,0,}, 's'}, {{1,}, 't'},
        {{0,0,1,}, 'u'}, {{0,0,0,1,}, 'v'},
        {{0,1,1,}, 'w'}, {{1,0,0,1,}, 'x'},
        {{1,0,1,1,}, 'y'}, {{1,1,0,0,}, 'z'},
    };

    const unordered_map<vector<bool>, char> morseToDecimal =
    {
        {{1,1,1,1,1,}, '0'}, {{0,1,1,1,1,}, '1'},
        {{0,0,1,1,1,}, '2'}, {{0,0,0,1,1,}, '3'},
        {{0,0,0,0,1,}, '4'}, {{0,0,0,0,0,}, '5'},
        {{1,0,0,0,0,}, '6'}, {{1,1,0,0,0,}, '7'},
        {{1,1,1,0,0,}, '8'}, {{1,1,1,1,0,}, '9'},
    };

    const unordered_map<vector<bool>, char> morseToSpechar =
    {
        {{0, 0, 0, 1, 0, 0, 1}, '$'},
        {{0, 1, 0, 1, 0}, '+'},
        {{1, 0, 0, 0, 1}, '='},
        {{0, 1, 0, 0, 0}, '&'},
        {{1, 1, 0, 0, 1, 1}, ','},
        {{0, 1, 0, 1, 0, 1}, '.'},
        {{1, 0, 1, 0, 1, 0}, ';'},
        {{1, 0, 1, 0, 1, 1}, '!'},
        {{0, 1, 0, 0, 1, 0}, '"'},
        {{0, 0, 1, 1, 0, 0}, '?'},
        {{1, 1, 1, 0, 0, 0}, ':'},
        {{1, 0, 0, 0, 0, 1}, '-'},
        {{1, 0, 0, 1, 0}, '/'},
        {{0, 1, 1, 1, 1, 0}, '\''},
        {{1, 0, 1, 1, 0}, '('},
        {{1, 0, 1, 1, 0, 1}, ')'},
        {{0, 0, 1, 1, 0, 1}, '_'},
        {{0, 1, 1, 0, 1, 0}, '@'},
    };

    const unordered_map<vector<bool>, wchar_t> morseToAccchar =
    {
      {{0, 0, 1, 1, }, L'ü'},
      {{0, 1, 0, 1, }, L'ä'},
      {{1, 0, 1, 1, 0, }, L'ĥ'},
      {{1, 1, 0, 1, 1, }, L'ñ'},
      {{0, 1, 1, 0, 0, }, L'þ'},
      {{0, 1, 1, 0, 1, }, L'à'},
      {{1, 0, 1, 0, 0, }, L'ç'},
      {{0, 1, 1, 1, 0, }, L'ĵ'},
      {{0, 0, 1, 1, 0, }, L'ð'},
      {{0, 1, 0, 0, 1, }, L'è'},
      {{0, 0, 0, 1, 0, }, L'ŝ'},
      {{0, 0, 1, 0, 0, }, L'é'},
      {{1, 1, 0, 1, 0, }, L'ĝ'},
      {{1, 1, 1, 0, }, L'ö'},
    };

    unordered_map<vector<bool>, wchar_t> morseToCharacter;
    for (const auto& letter : morseToAlpha)
    {
        morseToCharacter.insert(letter);
    } for (const auto& num : morseToDecimal)
    {
        morseToCharacter.insert(num);
    } for (const auto& special : morseToSpechar)
    {
        morseToCharacter.insert(special);
    } for (const auto& accent : morseToAccchar)
    {
        morseToCharacter.insert(accent);
    }

    return morseToCharacter;
}
