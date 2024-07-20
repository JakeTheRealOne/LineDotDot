/**
 * @file settings.hpp
 * @author JakeTheRealOne (jakelevrai@outlook.be)
 * @brief Header file for the Settings class
 * @version 0.1
 * @date 2024-07-19
 * 
 * @copyright Copyright (c) 2024
 * 
 */


# ifndef SETTINGS_HPP
# define SETTINGS_HPP


# include <vector>
# include <string>
using namespace std;


class Settings {
public:
    // #### constructors and destructor: ####

    /**
     * @brief Construct a new Settings object (default constructor)
     * 
     */
    Settings () noexcept = default;

    /**
     * @brief Construct a new Settings object (signal constructor)
     * 
     * @param shortSignal The character representing the short signal
     * @param longSignal The character representing the long signal
     */
    Settings (const char shortSignal = '.', const char longSignal = '-') noexcept;

    /**
     * @brief Construct a new Settings object (full constructor)
     * 
     * @param shortSignal The character representing the short signal
     * @param longSignal The character representing the long signal
     * @param letterSep The string that will separe each letter
     * @param wordSep The string that will separe each word
     */
    Settings (const char shortSignal = '.', const char longSignal = '-', const string& letterSep = " ", const string& wordSep = "  ");

    /**
     * @brief Destroy the Settings object
     * 
     */
    ~Settings () = default;

    // #### getters: ####

    /**
     * @brief The shortSignal getter
     * 
     */
    char shortSignal () const noexcept;

    /**
     * @brief The longSignal getter
     * 
     */
    char longSignal () const noexcept;

    /**
     * @brief The letterSep getter
     * 
     */
    string letterSep () const noexcept;

    /**
     * @brief The wordSep getter
     * 
     */
    string wordSep () const noexcept;

    // #### setters: ####

    void setShortSignal (const char newShortSignal);

    void setLongSignal (const char newLongSignal);

    void setLetterSep (const string& newLetterSep);

    void setWordSep (const string& newWordSep);

    // #### methods: ####

    // #### operators: ####

    /**
     * @brief The equality operator
     * 
     * @param other The other Settings instance
     * @return true If this == other
     * @return false If this != other
     */
    bool operator== (const Settings& other) const noexcept;

    /**
     * @brief The extraction operator
     * 
     * @param stream The stream that will recieve the instance infos
     * @param me The current Settings instance
     * @return ostream& The modified stream with the instance infos
     */
    friend ostream& operator<< (ostream& stream, const Settings& me) noexcept;

private:
    char _shortSignal = '.', _longSignal = '-';
    string _letterSep = " ", _wordSep = "  ";
};


# endif