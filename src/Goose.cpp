#include "Goose.h"
#include <iostream>
#include <string>

Goose::Goose(unsigned char age) : Animal(std::pair<unsigned char, std::string>(age, age%2 ? "Bertram" : "Mother Goose"))
{
}

Goose::Goose(unsigned char age, const std::string& name) : Animal(std::pair<unsigned char, std::string>(age, name))
{
}

void Goose::Speak() const noexcept
{
	std::string sound("HONK");
	sound.insert(1, m_Age, 'O');
	std::cout << sound << std::endl;
}
