#include "Duck.h"
#include <iostream>
#include <random>

Duck::Duck() : Animal(GenerateRamdomAgeAndName())
{
}

Duck::Duck(unsigned char age, const std::string& name) : Animal(std::pair<unsigned char, std::string>(age, name))
{
}

void Duck::Speak() const noexcept
{
	std::cout << "Quack" << std::endl;
}

std::pair<unsigned char, std::string> Duck::GenerateRamdomAgeAndName()
{
	std::random_device rd;
	std::mt19937 gen(rd());  // seed mersenne twister.
	std::uniform_int_distribution<> dist(0, 10); // distribute results between 0 and 10 inclusive.

	auto age = dist(gen);


	return std::make_pair<unsigned char, std::string>(static_cast<unsigned char>(age), age % 2 ? "Earl" : "Lady Luck");
}
