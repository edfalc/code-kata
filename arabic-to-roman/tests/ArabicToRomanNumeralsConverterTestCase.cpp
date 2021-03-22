/*
 * ArabicToRomanNumeralsConverterTestCase.cpp
 *
 *  Created on: 19 mrt. 2021
 *      Author: Eduardo Vieira Falcão
 */

#include <gtest/gtest.h>

#include "../includes/ArabicToRoman.h"

class RomanNumeralAssert {
public:
	RomanNumeralAssert() = delete;
	explicit RomanNumeralAssert(const unsigned int arabicNumber) : arabicNumberToConvert(arabicNumber) {}
	void isConvertedToRomanNumeral (const std::string& expectedRomanNumeral) const {
		ArabicToRoman testConversion { arabicNumberToConvert };
		ASSERT_EQ(expectedRomanNumeral, testConversion.convertArabicNumberToRomanNumeral(arabicNumberToConvert));
	}
private:
	const unsigned int arabicNumberToConvert;
};

RomanNumeralAssert assertThat(const unsigned int arabicNumber) {
	RomanNumeralAssert assert { arabicNumber };
	return assert;
}

TEST(ArabicToRomanNumeralsConverterTestCase, ConversionOfArabicNumbersToRomanNumerals_works) {
	assertThat(1).isConvertedToRomanNumeral("I");
	assertThat(2).isConvertedToRomanNumeral("II");
	assertThat(3).isConvertedToRomanNumeral("III");
	assertThat(4).isConvertedToRomanNumeral("IV");
	assertThat(5).isConvertedToRomanNumeral("V");
	assertThat(6).isConvertedToRomanNumeral("VI");
	assertThat(9).isConvertedToRomanNumeral("IX");
	assertThat(10).isConvertedToRomanNumeral("X");
	assertThat(20).isConvertedToRomanNumeral("XX");
	assertThat(30).isConvertedToRomanNumeral("XXX");
	assertThat(33).isConvertedToRomanNumeral("XXXIII");
	assertThat(37).isConvertedToRomanNumeral("XXXVII");
	assertThat(50).isConvertedToRomanNumeral("L");
	assertThat(99).isConvertedToRomanNumeral("XCIX");
	assertThat(100).isConvertedToRomanNumeral("C");
	assertThat(200).isConvertedToRomanNumeral("CC");
	assertThat(300).isConvertedToRomanNumeral("CCC");
	assertThat(499).isConvertedToRomanNumeral("CDXCIX");
	assertThat(500).isConvertedToRomanNumeral("D");
	assertThat(1000).isConvertedToRomanNumeral("M");
	assertThat(2000).isConvertedToRomanNumeral("MM");
	assertThat(2017).isConvertedToRomanNumeral("MMXVII");
	assertThat(3000).isConvertedToRomanNumeral("MMM");
	assertThat(3333).isConvertedToRomanNumeral("MMMCCCXXXIII");
	assertThat(3999).isConvertedToRomanNumeral("MMMCMXCIX");
}
