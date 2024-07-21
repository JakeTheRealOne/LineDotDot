# ifndef CONVERT_HPP
# define CONVERT_HPP


# include <string>
# include "settings.hpp"
using namespace std;


/**
 * @brief Convert an alpha text (A-Z | a-z | 0-9 | ASCII special char) 
 * 
 * @param text The alpha text
 * @param settings The settings of conversion
 * @return string The morse text
 */
string convertText (const string& text, const ConversionSettings& settings = ConversionSettings());


/**
 * @brief Convert a morse text into an alhpa text
 * 
 * @param morse The morse text
 * @param settings The settings of conversion
 * @return string The alpha text
 */
string convertMorse (const string& morse, const ConversionSettings& settings = ConversionSettings());



# endif