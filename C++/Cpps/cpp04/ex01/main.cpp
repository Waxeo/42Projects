#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
#include "WrongAnimal.hpp"

void	subjectTests()
{
	std::cout << GREEN << "////////////FIRST SUBJECT TEST////////////" << RESET << std::endl;

	Animal *tab[10];

	for (int i = 0; i < 10; i++)
	{
		if (!(i % 2))
			tab[i] = new Dog();
		else
			tab[i] = new Cat();
	}

	for (int i = 0; i < 10; i++)
		delete tab[i];

	return ;
}

void	CatShallowCopy()
{
	std::cout << GREEN << "////////////CATS BRAIN COPY TEST////////////" << RESET << std::endl;

	Cat *cat[2];

	cat[0] = new Cat();
	Brain* test1 = cat[0]->getBrain();
	if (test1)
		test1->setIdeas("miaou");
	
	cat[1] = new Cat(*cat[0]);

	Brain* test2 = cat[1]->getBrain();
	if (test2)
		test2->getIdeas();
	std::cout << std::endl;
	
	if (test1)
	{
		test1->setIdeas("pas miaou");
		test1->getIdeas();
		std::cout << std::endl;
	}
	if (test2)
		test2->getIdeas();
	std::cout << std::endl;

	delete cat[0];
	delete cat[1];

	return ;
}

void	DogShallowCopy()
{
	std::cout << GREEN << "////////////DOGS BRAIN COPY TEST////////////" << RESET << std::endl;

	Dog *dog[2];

	dog[0] = new Dog();
	Brain* test1 = dog[0]->getBrain();
	if (test1)
		test1->setIdeas("wouaf");
	
	dog[1] = new Dog(*dog[0]);

	Brain* test2 = dog[1]->getBrain();
	if (test2)
		test2->getIdeas();
	std::cout << std::endl;
	
	if (test1)
	{
		test1->setIdeas("pas wouaf");
		test1->getIdeas();
		std::cout << std::endl;
	}
	if (test2)
		test2->getIdeas();

	delete dog[0];
	delete dog[1];

	return ;
}


int main() 
{
	subjectTests();
	CatShallowCopy();
	DogShallowCopy();

    return 0;
}


/*
Une copie superficielle (shallow copy),
ne crée qu'une nouvelle référence à l'objet original, 
mais pas aux objets qu'il contient. 
Cela signifie que si l'objet original contient des références 
à d'autres objets (par exemple, des listes ou d'autres objets),
une copie superficielle ne copiera que ces références,
pas les objets réels. Ainsi, les modifications apportées à ces 
objets à travers la copie seront visibles dans l'objet original.

En revanche, une copie profonde (deep copy),
crée une nouvelle instance de l'objet original ainsi que
des copies indépendantes de tous les objets qu'il contient.
Ainsi, toute modification apportée à ces objets dans la copie
ne modifiera pas l'objet original.

/////Copie superficielle/////	
1.	Lorsque nous créons une copie d’un objet en copiant
les données de toutes les variables membres telles quelles,
cela s’appelle une copie superficielle 

2.	Une copie superficielle d’un objet copie toutes les
valeurs du champ membre.	

3.	En copie superficielle, les deux objets ne sont pas
indépendants	

4.	Il crée également une copie des objets alloués
dynamiquement	

/////Copie profonde//////
1.	Lorsque nous créons un objet en copiant les données d’un
autre objet avec les valeurs des ressources mémoire qui
résident en dehors de l’objet, cela s’appelle une copie profonde

2.  La copie en profondeur est effectuée en implémentant notre
propre constructeur de copie.

3.  Il copie tous les champs et fait des copies de la mémoire
allouée dynamiquement pointée par les champs

4.  Si nous ne créons pas la copie complète de manière légitime,
la copie pointera vers l’original, avec des conséquences
désastreuses.

*/