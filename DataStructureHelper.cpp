#include "DataStructureHelper.h"
#include <iostream>
#include <random>

int DataStructureHelper::GenerateRandomNumber(int from, int to)
{
	if (from > to)
	{
		std::cout << "UnitTest::GenerateRandomNumber() from > to" << '\n';
		return 0;
	}

	static std::random_device randomDevice;  //Will be used to obtain a seed for the random number engine
	static std::mt19937 generatorOfRandomNumbers(randomDevice()); //Standard mersenne_twister_engine seeded with rd()

	std::uniform_int_distribution<> generatedRandomNumbers(from, to);

	return generatedRandomNumbers(generatorOfRandomNumbers);
}
