/**
 * @file settings.cpp
 * @author JakeTheRealOne (jakelevrai@outlook.be)
 * @brief Source file for the Settings class
 * @version 0.1
 * @date 2024-07-19
 * 
 * @copyright Copyright (c) 2024
 * 
 */



# include <algorithm>
# include <iostream>
# include <string>
# include "settings.hpp"
using namespace std;


ConversionSettings::ConversionSettings
(const char shortSignal, const char longSignal)
noexcept : _shortSignal(shortSignal), _longSignal(longSignal) {}


ConversionSettings::ConversionSettings(const char shortSignal,
const char longSignal, const string& letterSep, const string& wordSep) :
_shortSignal(shortSignal), _longSignal(longSignal), _letterSep(letterSep),
_wordSep(wordSep) {}


char ConversionSettings::shortSignal() const noexcept {return this->_shortSignal;}


char ConversionSettings::longSignal() const noexcept {return this->_longSignal;}


string ConversionSettings::letterSep() const noexcept {return this->_letterSep;}


string ConversionSettings::wordSep() const noexcept {return this->_wordSep;}


void ConversionSettings::setShortSignal(const char newShortSignal)
{
    if (
        find(_letterSep.begin(), _letterSep.end(), newShortSignal) != _letterSep.end()
        or 
        find(_wordSep.begin(), _wordSep.end(), newShortSignal) != _wordSep.end()
    )
    {
        cout << "[ERR] the new short signal is part of the word or letter separator" << endl;
    } else if (newShortSignal == _longSignal)
    {
        cout << "[ERR] the new short signal is identical to the long signal" << endl;
    } else
    {
        _shortSignal = newShortSignal;
    }
}


void ConversionSettings::setLongSignal(const char newLongSignal)
{
    if (
        find(_letterSep.begin(), _letterSep.end(), newLongSignal) != _letterSep.end()
        or 
        find(_wordSep.begin(), _wordSep.end(), newLongSignal) != _wordSep.end()
    )
    {
        cout << "[ERR] the new long signal is part of the word or letter separator" << endl;
    } else if (newLongSignal == _shortSignal)
    {
        cout << "[ERR] the new long signal is identical to the short signal" << endl;
    } else
    {
        _longSignal = newLongSignal;
    }
}


void ConversionSettings::setLetterSep(const string& newLetterSep)
{
    if (newLetterSep.empty() or newLetterSep.size() > 16)
    {
        cout << "[ERR] word separator size must be between 1 and 16 characters" << endl;
    } else if (newLetterSep == _wordSep)
    {
        cout << "[ERR] the new letter separator is identical to the word separator" << endl;
    } else if (
        find(newLetterSep.begin(), newLetterSep.end(), _shortSignal) != newLetterSep.end()
        or
        find(newLetterSep.begin(), newLetterSep.end(), _longSignal) != newLetterSep.end()
    )
    {
        cout << "[ERR] the new word separator contains long or short signal" << endl;
    }  else {
        _wordSep = newLetterSep;
    }
}


void ConversionSettings::setWordSep(const string& newWordSep)
{
    if (newWordSep.empty() or newWordSep.size() > 32)
    {
        cout << "[ERR] word separator size must be between 1 and 32" << endl;
    } else if (newWordSep == _letterSep)
    {
        cout << "[ERR] the new word separator is identical to the letter separator" << endl;
    } else if (
        find(newWordSep.begin(), newWordSep.end(), _shortSignal) != newWordSep.end()
        or
        find(newWordSep.begin(), newWordSep.end(), _longSignal) != newWordSep.end()
    )
    {
        cout << "[ERR] the new word separator contains long or short signal" << endl;
    }  else {
        _wordSep = newWordSep;
    }
}


void ConversionSettings::reset() noexcept
{
    _shortSignal = '.';
    _longSignal = '-';
    _letterSep = " ";
    _wordSep = " ";
}


bool ConversionSettings::operator==(const ConversionSettings& other) const noexcept {
    return (
        _shortSignal == other._shortSignal
        and
        _longSignal == other._longSignal
        and
        _letterSep == other._letterSep
        and
        _wordSep == other._wordSep
    );
}


ostream& operator<<(ostream& stream, const ConversionSettings& me) noexcept
{
    stream << "ConversionSettings({" << me._shortSignal << "}, {" << me._longSignal << "}, [" << me._letterSep << "], [" << me._wordSep << "]";
    return stream;
}