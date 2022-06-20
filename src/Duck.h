#include "Animal.h"
#include <utility>

class Duck : public Animal
{
public:
	Duck();
	Duck(unsigned char age, const std::string& name);
	~Duck(){}

	void Speak() const noexcept;
private:
	static std::pair<unsigned char, std::string> GenerateRamdomAgeAndName();
};