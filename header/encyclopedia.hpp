/**
 * @file encyclopedia.hpp
 * @author JakeTheRealOne (jakelevrai@outlook.be)
 * @brief Header file of Encyclopedia class
 * @version 0.1
 * @date 21-07-2024
 * 
 * @copyright Copyright (c) 2024
 * 
 */


// #### Std inclusions: ####
# include <vector>
# include <unordered_map>
using namespace std;


# ifndef ENCYCLOPEDIA_HPP
# define ENCYCLOPEDIA_HPP


/**
 * @brief Return the map of all characters and their morse translation
 * 
 * @return unordered_map<char, vector<bool>> {character:morse}
 */
unordered_map<char, vector<bool>> buildCTM ();


/**
 * @brief Return the map of all morse character and their english translation
 * 
 * @return unordered_map<vector<bool>, char> {morse:character}
 */
unordered_map<vector<bool>, char> buildMTC ();


# endif