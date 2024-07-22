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


// #### Std inclusions: ####
# include <algorithm>
# include <iostream>
# include <string>
using namespace std;

// #### Intern inclusions: ####
# include "../header/settings.hpp"


ConversionSettings::ConversionSettings
(const wchar_t shortSignal, const wchar_t longSignal)
noexcept : _shortSignal(shortSignal), _longSignal(longSignal) {}


ConversionSettings::ConversionSettings(const wchar_t shortSignal,
const wchar_t longSignal, const wstring& letterSep, const wstring& wordSep) :
_shortSignal(shortSignal), _longSignal(longSignal), _letterSep(letterSep),
_wordSep(wordSep) {}


wchar_t ConversionSettings::shortSignal() const noexcept {return this->_shortSignal;}


wchar_t ConversionSettings::longSignal() const noexcept {return this->_longSignal;}


wstring ConversionSettings::letterSep() const noexcept {return this->_letterSep;}


wstring ConversionSettings::wordSep() const noexcept {return this->_wordSep;}


void ConversionSettings::setShortSignal(const wchar_t newShortSignal)
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


void ConversionSettings::setLongSignal(const wchar_t newLongSignal)
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


void ConversionSettings::setLetterSep(const wstring& newLetterSep)
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


void ConversionSettings::setWordSep(const wstring& newWordSep)
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
    _letterSep = L" ";
    _wordSep = L" ";
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


wostream& operator<<(wostream& stream, const ConversionSettings& me) noexcept
{
    stream << L"ConversionSettings({" << me._shortSignal << L"}, {" << me._longSignal << L"}, [" << me._letterSep << L"], [" << me._wordSep << L"]";
    return stream;
}