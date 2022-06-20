#pragma once
#include <string>

class Animal
{
public:
	Animal(const std::pair<unsigned char, std::string>& pair) : m_Age(pair.first), m_Name(pair.second) {}
	virtual ~Animal() {}
	virtual void Speak() const noexcept = 0;

	unsigned char GetAge() const noexcept { return m_Age; }
	std::string GetName() const noexcept { return m_Name; }
protected:
	unsigned char m_Age;
	std::string   m_Name;
};