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
    ConversionSettings (const wchar_t shortSignal, const wchar_t longSignal) noexcept;

    /**
     * @brief Construct a new ConversionSettings object (full constructor)
     * 
     * @param shortSignal The character representing the short signal
     * @param longSignal The character representing the long signal
     * @param letterSep The string that will separe each letter
     * @param wordSep The string that will separe each word
     */
    ConversionSettings (const wchar_t shortSignal, const wchar_t longSignal, const wstring& letterSep, const wstring& wordSep);

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
    wchar_t shortSignal () const noexcept;

    /**
     * @brief Get the Long signal
     * 
     */
    wchar_t longSignal () const noexcept;

    /**
     * @brief Get the Letter separator
     * 
     */
    wstring letterSep () const noexcept;

    /**
     * @brief Get the Word separator
     * 
     */
    wstring wordSep () const noexcept;

    // #### setters: ####

    /**
     * @brief Set the Short Signal object
     * 
     * @param newShortSignal The new short signal
     */
    void setShortSignal (const wchar_t newShortSignal);

    /**
     * @brief Set the Long Signal object
     * 
     * @param newLongSignal The new long signal
     */
    void setLongSignal (const wchar_t newLongSignal);

    /**
     * @brief Set the Letter Sep object
     * 
     * @param newLetterSep The new letter separator
     */
    void setLetterSep (const wstring& newLetterSep);

    /**
     * @brief Set the Word Sep object
     * 
     * @param newWordSep The new word separator
     */
    void setWordSep (const wstring& newWordSep);

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
    friend wostream& operator<< (wostream& stream, const ConversionSettings& me) noexcept;

private:
    wchar_t _shortSignal = '.', _longSignal = '-';
    wstring _letterSep = L" ", _wordSep = L"  ";
};


# endif