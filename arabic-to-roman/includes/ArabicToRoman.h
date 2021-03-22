/*
 * ArabicToRoman.hpp
 *
 *  Created on: 22 mrt. 2021
 *      Author: Eduardo Vieira Falcão
 */

#ifndef INCLUDES_ARABICTOROMAN_HPP_
#define INCLUDES_ARABICTOROMAN_HPP_

#include <string>
#include <array>

class ArabicToRoman {
	public:
		ArabicToRoman() = delete;
		explicit ArabicToRoman(const unsigned int number) : arabicNumber(number) {};
		std::string convertArabicNumberToRomanNumeral(unsigned int arabicNumber);
	private:
		const unsigned int arabicNumber;
};

struct ArabicToRomanMapping {
	unsigned int arabicNumber;
	std::string romanNumeral;
};

const std::size_t numberOfMappings { 13 };
using ArabicToRomanMappings = std::array<ArabicToRomanMapping, numberOfMappings>;
const ArabicToRomanMappings arabicToRomanMappings = { {
		{ 1000, "M" },
		{ 900, "CM" },
		{ 500, "D" },
		{ 400, "CD" },
		{ 100, "C" },
		{ 90, "XC" },
		{ 50, "L" },
		{ 40, "XL" },
		{ 10, "X" },
		{ 9, "IX" },
		{ 5, "V" },
		{ 4, "IV" },
		{ 1, "I" }
} };

#endif /* INCLUDES_ARABICTOROMAN_HPP_ */
