/**
 * @file settings.hpp
 * @author JakeTheRealOne (jakelevrai@outlook.be)
 * @brief Header file for the ConversionSettings class
 * @version 0.1
 * @date 2024-07-19
 * 
 * @copyright Copyright (c) 2024
 * 
 */


# ifndef SETTINGS_HPP
# define SETTINGS_HPP


# include <string>
using namespace std;


class ConversionSettings {
public:
    // #### constructors and destructor: ####

    /**
     * @brief Construct a new ConversionSettings object (default constructor)
     * 
     */
    ConversionSettings () noexcept = default;

    /**
     * @brief Construct a new ConversionSettings object (signal constructor)
     * 
     * @param shortSignal The character representing the short signal
     * @param longSignal The character representing the long signal
     */
    ConversionSettings (const char shortSignal, const char longSignal) noexcept;

    /**
     * @brief Construct a new ConversionSettings object (full constructor)
     * 
     * @param shortSignal The character representing the short signal
     * @param longSignal The character representing the long signal
     * @param letterSep The string that will separe each letter
     * @param wordSep The string that will separe each word
     */
    ConversionSettings (const char shortSignal, const char longSignal, const string& letterSep, const string& wordSep);

    /**
     * @brief Destroy the ConversionSettings object
     * 
     */
    ~ConversionSettings () = default;

    // #### getters: ####

    /**
     * @brief Get the Short signal
     * 
     */
    char shortSignal () const noexcept;

    /**
     * @brief Get the Long signal
     * 
     */
    char longSignal () const noexcept;

    /**
     * @brief Get the Letter separator
     * 
     */
    string letterSep () const noexcept;

    /**
     * @brief Get the Word separator
     * 
     */
    string wordSep () const noexcept;

    // #### setters: ####

    /**
     * @brief Set the Short Signal object
     * 
     * @param newShortSignal The new short signal
     */
    void setShortSignal (const char newShortSignal);

    /**
     * @brief Set the Long Signal object
     * 
     * @param newLongSignal The new long signal
     */
    void setLongSignal (const char newLongSignal);

    /**
     * @brief Set the Letter Sep object
     * 
     * @param newLetterSep The new letter separator
     */
    void setLetterSep (const string& newLetterSep);

    /**
     * @brief Set the Word Sep object
     * 
     * @param newWordSep The new word separator
     */
    void setWordSep (const string& newWordSep);

    // #### methods: ####

    /**
     * @brief Reset all attributes to their value bu default
     * 
     */
    void reset() noexcept;

    // #### operators: ####

    /**
     * @brief The equality operator
     * 
     * @param other The other ConversionSettings instance
     * @return true If this == other
     * @return false If this != other
     */
    bool operator== (const ConversionSettings& other) const noexcept;

    /**
     * @brief The extraction operator
     * 
     * @param stream The stream that will recieve the instance infos
     * @param me The current ConversionSettings instance
     * @return ostream& The modified stream with the instance infos
     */
    friend ostream& operator<< (ostream& stream, const ConversionSettings& me) noexcept;

private:
    char _shortSignal = '.', _longSignal = '-';
    string _letterSep = " ", _wordSep = "  ";
};


# endif