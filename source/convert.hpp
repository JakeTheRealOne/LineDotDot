# ifndef CONVERT_HPP
# define CONVERT_HPP


# include <string>
# include <vector>
using namespace std;

# include "settings.hpp"

/**
 * @brief Convert an english text to morse code
 * 
 * @param text The text
 * @param shortSignal The representation for a short signal (base: .)
 * @param longSignal The representation for a long signal (base: -)
 * @param letterSep The string that split each letter (base: space)
 * @param wordSep The string that split each word (base: 2x space)
 * @return string The morse code corresponding to the text
 */
string convertText (const string& text, const char shortSignal, const char longSignal, const string& letterSep, const string& wordSep);

/**
 * @brief Split a word (morse code) into letters
 * 
 * @param word The word
 * @param letterSep The string that split each letter
 * @return vector<string> The vector of each letter (raw)
 */
vector<string> splitWord (const string& word, const string& letterSep);

/**
 * @brief Split a morse code into words
 * 
 * @param morse The morse code
 * @param letterSep The string that split each letter
 * @param wordSep The string that split each word
 * @return vector<vector<string>> The vector of words (vector of letters)
 */
vector<vector<string>> splitMorse (const string& morse, const string& letterSep, const string& wordSep);

/**
 * @brief Convert a letter (morse code) into a vector of booleans
 * 
 * @param morseLetter The letter
 * @param longSignal The representation for a long signal
 * @param shortSignal The representation for a short signal
 * @return vector<bool> The vector of bool (true: long signal, false: short signal)
 */
vector<bool> convertToBool (const string& morseLetter, const char longSignal, const char shortSignal);

/**
 * @brief Convert a morse text into an english text
 * 
 * @param morse The morse text
 * @param shortSignal The representation for a short signal (base: .)
 * @param longSignal The representation for a long signal (base: -)
 * @param letterSep The string that split each letter (base: space)
 * @param wordSep The string that split each word (base: 2x space)
 * @return string The english text
 */
string convertMorse (const string& morse, const char shortSignal = '.', const char longSignal = '-', const string& letterSep = " ", const string& wordSep = "  ");

/**
 * @brief Convert a morse text into an english text
 * 
 * @param morse The morse text
 * @param settings The settings of conversion
 * @return string The english text
 */
string convertMorse (const string& morse, const ConversionSettings& settings);


# endif