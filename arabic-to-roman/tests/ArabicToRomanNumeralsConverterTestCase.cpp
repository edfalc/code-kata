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

std::string convertArabicNumberToRomanNumeral(const unsigned int arabicNumber) {
	return "I";
}

TEST(ArabicToRomanNumeralsConverterTestCase, 1_isConvertedTo_I) {
	ASSERT_EQ("I", convertArabicNumberToRomanNumeral(1));
}
