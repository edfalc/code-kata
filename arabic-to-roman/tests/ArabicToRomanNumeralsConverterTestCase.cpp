/*
 * ArabicToRomanNumeralsConverterTestCase.cpp
 *
 *  Created on: 19 mrt. 2021
 *      Author: Eduardo Vieira Falcão
 */

#include <gtest/gtest.h>

int main(int argc, char** argv) {
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}

std::string convertArabicNumberToRomanNumeral (unsigned int arabicNumber) {
	std::string romanNumeral;

	while (arabicNumber >= 10) {
		romanNumeral += "X";
		arabicNumber -= 10;
	}
	while(arabicNumber >= 1){
		romanNumeral += "I";
		--arabicNumber;
	}

	return romanNumeral;
}

class RomanNumeralAssert {
public:
	RomanNumeralAssert() = delete;
	explicit RomanNumeralAssert(const unsigned int arabicNumber) : arabicNumberToConvert(arabicNumber) {}
	void isConvertedToRomanNumeral (const std::string& expectedRomanNumeral) const {
		ASSERT_EQ(expectedRomanNumeral, convertArabicNumberToRomanNumeral(arabicNumberToConvert));
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
	assertThat(10).isConvertedToRomanNumeral("X");
	assertThat(20).isConvertedToRomanNumeral("XX");
	assertThat(30).isConvertedToRomanNumeral("XXX");
	assertThat(33).isConvertedToRomanNumeral("XXXIII");
}
