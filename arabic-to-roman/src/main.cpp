/*
 * main.cpp
 *
 *  Created on: 22 mrt. 2021
 *      Author: Eduardo Vieira Falcão
 */

#include <gtest/gtest.h>
#include <iostream>
#include "../includes/ArabicToRoman.h"

using namespace std;

int main(int argc, char** argv) {
	/*testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
	*/


	unsigned int arabicNumber;

	cout << "Enter Arabic number to be converted: ";
	cin >> arabicNumber;

	ArabicToRoman number { arabicNumber };
	cout << "The correspondent number in Roman is " << number.convertArabicNumberToRomanNumeral(arabicNumber) << endl;

	return 0;
}


