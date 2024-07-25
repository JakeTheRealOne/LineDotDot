/**
 * @file fromfile.hpp
 * @author JakeTheRealOne (jakelevrai@outlook.be)
 * @brief Header file for extraction of Morse code of a file
 * @version 0.1
 * @date 21-07-2024
 * 
 * @copyright Copyright (c) 2024
 * 
 */


# ifndef FROMFILE_HPP
# define FROMFILE_HPP


// #### Std inclusions: ####
# include <string>
# include <vector>
using namespace std;


// #### Internal inclusions: ####
# include "../header/settings.hpp"

namespace Decoder
{
  /**
   * @brief Convert the morse content of a file into text
   * 
   * @param path The path of the file
   * @param settings The conversion settings
   * @return string The converted text
   */
  string convert(const string& path, const ConversionSettings& settings = ConversionSettings());
}


namespace Encoder
{
  /**
   * @brief Convert the text content of a file into morse
   * 
   * @param path The path of the file
   * @param settings The conversion settings
   * @return string The converted morse
   */
  string convert(const string& path, const ConversionSettings& settings = ConversionSettings());
}


# endif