#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
#include "WrongAnimal.hpp"

int main() 
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog("Snoop");
	const Animal* i = new Cat("Lopotichat");

	std::cout << std::endl << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl << std::endl;

	i->makeSound(); //will output the cat sound! 
	j->makeSound();
	meta->makeSound();

	std::cout << std::endl;

	const WrongAnimal* test2 = new WrongAnimal();
	const WrongAnimal* test = new WrongCat("ElGato");

	std::cout << std::endl << test->getType() << " " << std::endl << std::endl;

	test->makeSound(); //will output the wrongcat sound! 
	test2->makeSound(); 

	std::cout << std::endl;

	delete meta;
	delete i;
	delete j;
	delete test;
	delete test2;

	return 0;
}
