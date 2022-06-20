#include "Animal.h"

class Goose : public Animal
{
public:
	Goose(unsigned char age);
	Goose(unsigned char age, const std::string& name);
	~Goose() {}

	void Speak() const noexcept;
};