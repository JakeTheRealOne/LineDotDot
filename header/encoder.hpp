/**
 * @file encoder.hpp
 * @author JakeTheRealOne (jakelevrai@outlook.be)
 * @brief Header file for the morse Encoder
 * @version 0.1
 * @date 23-07-2024
 * 
 * @copyright Copyright (c) 2024
 * 
 */



# ifndef ENCODER_HPP
# define ENCODER_HPP


// #### Internal inclusions: ####
# include "../header/settings.hpp"

// #### Std inclusions: ####
# include <string>


namespace Encoder {
/**
 * @brief Convert an alpha text (A-Z | a-z | 0-9 | ASCII special char) 
 * 
 * @param text The alpha text
 * @param settings The settings of conversion
 * @return string The morse text
 */
wstring convert (const wstring& text, const ConversionSettings& settings = ConversionSettings());
}


# endif