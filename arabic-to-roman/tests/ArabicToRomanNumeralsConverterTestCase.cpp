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

struct ArabicToRomanMapping {
	unsigned int arabicNumber;
	std::string romanNumeral;
};

const std::size_t numberOfMappings { 3 };
using ArabicToRomanMappings = std::array<ArabicToRomanMapping, numberOfMappings>;
const ArabicToRomanMappings arabicToRomanMappings = { {
		{100, "C"},
		{ 10, "X"},
		{  1, "I"}
} };

std::string convertArabicNumberToRomanNumeral (unsigned int arabicNumber) {
	std::string romanNumeral;

	for (const auto& mapping : arabicToRomanMappings) {
		while (arabicNumber >= mapping.arabicNumber) {
			romanNumeral += mapping.romanNumeral;
			arabicNumber -= mapping.arabicNumber;
		}
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
	assertThat(100).isConvertedToRomanNumeral("C");
	assertThat(200).isConvertedToRomanNumeral("CC");
	assertThat(300).isConvertedToRomanNumeral("CCC");
}
