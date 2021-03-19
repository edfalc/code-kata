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
	while(arabicNumber >= 1){
		romanNumeral += "I";
		--arabicNumber;
	}
	return romanNumeral;
}

TEST(ArabicToRomanNumeralsConverterTestCase, 1_isConvertedTo_I) {
	ASSERT_EQ("I", convertArabicNumberToRomanNumeral(1));
}

TEST(ArabicToRomanNumeralsConverterTestCase, 2_isConvertedTo_II) {
	ASSERT_EQ("II", convertArabicNumberToRomanNumeral(2));
}

TEST(ArabicToRomanNumeralsConverterTestCase, 3_isConvertedTo_III) {
	ASSERT_EQ("III", convertArabicNumberToRomanNumeral(3));
}
