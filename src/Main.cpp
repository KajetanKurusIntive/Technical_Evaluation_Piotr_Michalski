
#include "Duck.h"
#include "Goose.h"
#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>
#include <fstream>
#include <type_traits>

void findAndRemoveOldestDuck(std::vector<std::unique_ptr<Animal>>& collection)
{
	if (collection.empty())
	{
		std::cout << "Collection is empty" << std::endl;
		return;
	}

	// determine the age of oldest duck
	unsigned char maxAge = 0;
	for (const auto& animal : collection)
		if (animal)
			if (auto duck = dynamic_cast<Duck*>(animal.get())) // select ducks only, there might be other animals in collection
				if (duck->GetAge() > maxAge)
					maxAge = duck->GetAge();

	std::cout << "Removing oldest ducks (age of " << static_cast<unsigned short>(maxAge) << ")" << std::endl;

	size_t counterOfRemoved = 0;

	for (auto it = collection.begin(); it != collection.end(); ) {
		if (*it && (*it)->GetAge() == maxAge) {
			it = collection.erase(it);
			counterOfRemoved++;
		}
		else {
			++it;
		}
	}

	std::cout << "Removed " << counterOfRemoved << " duck" << ((counterOfRemoved > 1) ? "s" : "") << std::endl;
}

void sortByAge(std::vector<std::unique_ptr<Animal>>& collection)
{
	if (collection.size() > 1)
		std::sort(collection.begin(), collection.end(),
			[](std::unique_ptr<Animal>& a, std::unique_ptr<Animal>& b)
			{ return (a ? a->GetAge() : 0) > (b ? b->GetAge() : 0); });
}

void printAges(const std::vector<std::unique_ptr<Animal>>& collection)
{
	std::cout << "Age of animals in collection:" << std::endl;
	for (auto&& animal : collection)
		std::cout << static_cast<unsigned int>(animal->GetAge()) << std::endl;
}

void printTotalAge(const std::vector<std::unique_ptr<Animal>>& collection)
{
	if (collection.empty())
	{
		std::cout << "Collection is empty" << std::endl;
	}

	unsigned int total = 0;
	for (auto&& animal : collection)
		if (animal)
			total += animal->GetAge();

	std::cout << "Total age of all animals in collection: " << total << std::endl;
}

void printOutNamesToFile(const std::vector<std::unique_ptr<Animal>>& collection, const std::string& fileName)
{
	std::ofstream ostrm(fileName, std::ios::trunc);
	ostrm << "Animal names:" << std::endl;
	for (auto&& animal : collection)
		if (animal)
			ostrm << animal->GetName() << std::endl;
}
void initDuckCollection(std::vector<std::unique_ptr<Animal>>& DuckCollection, unsigned int numberOfDucks)
{
	for (unsigned int i = 0; i < numberOfDucks; i++)
		DuckCollection.push_back(std::make_unique<Duck>());
}

void initAnimalCollection(std::vector<std::unique_ptr<Animal>>& AnimalCollection, unsigned int numberOfAnimalsInGroup)
{
	for (unsigned int i = 0; i < numberOfAnimalsInGroup; i++)
	{
		AnimalCollection.push_back(std::make_unique<Duck>());
		AnimalCollection.push_back(std::make_unique<Goose>(i));
	}
}

void animalCollectionSpeech(const std::vector<std::unique_ptr<Animal>>& AnimalCollection)
{
	std::cout << "AnimalCollection speaks:" << std::endl;

	for (auto&& animal : AnimalCollection)
		if (animal)
			animal->Speak();
}

int main()
{
	std::vector<std::unique_ptr<Animal>> DuckCollection;
	initDuckCollection(DuckCollection, 13);

	for (char i = 0; i < 21; i++)
		findAndRemoveOldestDuck(DuckCollection);

	std::vector<std::unique_ptr<Animal>> AnimalCollection;
	initAnimalCollection(AnimalCollection, 10);

	animalCollectionSpeech(AnimalCollection);

	std::cout << "AnimalCollection before sort:" << std::endl;
	printAges(AnimalCollection);

	sortByAge(AnimalCollection);

	std::cout << "AnimalCollection after sort:" << std::endl;
	printAges(AnimalCollection);

	printTotalAge(AnimalCollection);

	printOutNamesToFile(AnimalCollection, "AnimalNames.txt");

	return 0;
}
