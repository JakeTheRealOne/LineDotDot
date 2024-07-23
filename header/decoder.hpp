/**
 * @file decoder.hpp
 * @author JakeTheRealOne (jakelevrai@outlook.be)
 * @brief Header file for the morse Decoder
 * @version 0.1
 * @date 23-07-2024
 * 
 * @copyright Copyright (c) 2024
 * 
 */


# ifndef DECODER_HPP
# define DECODER_HPP


// #### Internal inclusions: ####
# include "../header/settings.hpp"

// #### Std inclusions: ####
# include <string>
# include <vector>


namespace Decoder {
/**
 * @brief Convert a morse text into an alhpa text
 * 
 * @param morse The morse text
 * @param settings The settings of conversion
 * @return string The alpha text
 */
wstring convert (const wstring& morse, const ConversionSettings& settings = ConversionSettings());

/**
 * @brief Search a letter in the encyclopedia and add it to the converted text if exists
 * 
 * @param convertedText The text issue from the conversion
 * @param letter A possible new letter to add to convertedText
 * @param settings The settings of conversion
 */
void addLetterTo(wstring& convertedText, vector<bool>& letter, const ConversionSettings& settings);

/**
 * @brief Check if morse[index:?] is the end of a letter
 * 
 * @param morse The morse text
 * @param index The current index
 * @param settings The conversion settings
 * @return int The offset of the end of letter (0 if no end)
 */
int endOfLetter(const wstring& morse, int index, const ConversionSettings& settings);

/**
 * @brief Check if morse[index:?] is the end of a word
 * 
 * @param morse The morse text
 * @param index The current index
 * @param settings The conversion settings
 * @return int The offset of the end of word (0 if no end)
 */
int endOfWord(const wstring& morse, int index, const ConversionSettings& settings);
}


# endif