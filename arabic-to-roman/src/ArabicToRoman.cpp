/*
 * ArabicToRoman.cpp
 *
 *  Created on: 22 mrt. 2021
 *      Author: Eduardo Vieira Falcão
 */

#include "../includes/ArabicToRoman.h"

std::string ArabicToRoman::convertArabicNumberToRomanNumeral (unsigned int arabicNumber) {
	std::string romanNumeral;

	for (const auto& mapping : arabicToRomanMappings) {
		while (arabicNumber >= mapping.arabicNumber) {
			romanNumeral += mapping.romanNumeral;
			arabicNumber -= mapping.arabicNumber;
		}
	}

	return romanNumeral;
}

