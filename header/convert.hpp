/**
 * @file convert.hpp
 * @author JakeTheRealOne (jakelevrai@outlook.be)
 * @brief Header file of Encoder and Decoder namespaces
 * @version 0.1
 * @date 21-07-2024
 * 
 * @copyright Copyright (c) 2024
 * 
 */

# ifndef CONVERT_HPP
# define CONVERT_HPP


# include <string>
# include "settings.hpp"
using namespace std;


namespace Encoder {
/**
 * @brief Convert an alpha text (A-Z | a-z | 0-9 | ASCII special char) 
 * 
 * @param text The alpha text
 * @param settings The settings of conversion
 * @return string The morse text
 */
string convert (const string& text, const ConversionSettings& settings = ConversionSettings());
}



namespace Decoder {
/**
 * @brief Convert a morse text into an alhpa text
 * 
 * @param morse The morse text
 * @param settings The settings of conversion
 * @return string The alpha text
 */
string convert (const string& morse, const ConversionSettings& settings = ConversionSettings());

/**
 * @brief Check if morse[index:?] is the end of a letter
 * 
 * @param morse The morse text
 * @param index The current index
 * @param settings The conversion settings
 * @return int The offset of the end of letter (0 if no end)
 */
int endOfLetter(const string& morse, int index, const ConversionSettings& settings);

/**
 * @brief Check if morse[index:?] is the end of a word
 * 
 * @param morse The morse text
 * @param index The current index
 * @param settings The conversion settings
 * @return int The offset of the end of word (0 if no end)
 */
int endOfWord(const string& morse, int index, const ConversionSettings& settings);
}




# endif