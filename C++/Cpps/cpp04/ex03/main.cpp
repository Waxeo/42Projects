#include "Ice.hpp"
#include "Cure.hpp"
#include "MateriaSource.hpp"
#include "Character.hpp"

int school_test()
{
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    std::cout << std::endl;

    ICharacter* me = new Character("joe");
    AMateria* tmp;
    tmp = src->createMateria("ice");
    std::cout << std::endl;

    me->equip(tmp);
    tmp = src->createMateria("cure");
    std::cout << std::endl;

    me->equip(tmp);
    ICharacter* bob = new Character("bob");
    std::cout << std::endl;

    me->use(0, *bob);
    me->use(1, *bob);
    delete bob;
    delete me;
    delete src;
    return 0;
}

void	testMateriaSource(void)
{
	std::cout << std::endl << GREEN << "-------------------------------" << std::endl
		<< "\tMATERIA SOURCE TEST" << std::endl
		<<  "-------------------------------" << RESET << std::endl;
	std::cout << std::endl << "-- MATERIA SOURCE CREATION" << std::endl;
	MateriaSource * source = new MateriaSource();
	source->displayModels();

	std::cout << std::endl << GREEN << "-- MATERIA SOURCE LEARNING RECIPES" << RESET << std::endl;
	source->learnMateria(NULL);
	source->learnMateria(new Cure());
	source->learnMateria(new Ice());
	source->displayModels();

	std::cout << std::endl << GREEN << "-- MATERIA SOURCE DEEP COPY" << RESET << std::endl;
	MateriaSource * copySource = new MateriaSource(*source);
	std::cout << "Original ";
	source->displayModels();
	std::cout << "Copy ";
	copySource->displayModels();
	std::cout << "Original Materia Source learns another recipe:" << std::endl;
	source->learnMateria(new Cure());
	std::cout << "Original ";
	source->displayModels();
	std::cout << "Copy ";
	copySource->displayModels();
	std::cout << "Deleting Copy Materia Source:" << std::endl;
	delete copySource;

	std::cout << std::endl << GREEN << "-- MATERIA SOURCE LEARNING TOO MANY RECIPES" << RESET << std::endl;
	source->displayModels();
	source->learnMateria(new Ice());
	source->learnMateria(new Cure());
	source->displayModels();

	std::cout << std::endl << GREEN << "-- MATERIA SOURCE CREATING MATERIA FROM RECIPES" << RESET << std::endl;
	AMateria *	m1 = NULL;
	AMateria *	m2 = NULL;
	AMateria *	m3 = NULL;
	
	m1 = source->createMateria("ice");
	if (m1 == NULL)
		std::cout << "Materia was not created." << std::endl;
	else
		std::cout << "Created materia is " << m1->getType() << std::endl;
	m2 = source->createMateria("cure");
	if (m2 == NULL)
		std::cout << "Materia was not created." << std::endl;
	else
		std::cout << "Created materia is " << m2->getType() << std::endl;
	m3 = source->createMateria("rock");
	if (m3 == NULL)
		std::cout << "Materia was not created." << std::endl;
	else
		std::cout << "Created materia is " << m2->getType() << std::endl;
	if (m1 != NULL)
		delete m1;
	if (m2 != NULL)
		delete m2;
	if (m3 != NULL)
		delete m3;

	std::cout << std::endl << GREEN << "-- MATERIA SOURCE DELETION" << RESET << std::endl;
	delete source;
}

void	testCharacters(void)
{
	std::cout << GREEN << std::endl <<  "-------------------------------" << std::endl
		<< "\tCHARACTER TEST" << std::endl
		<<  "-------------------------------" << RESET << std::endl;
	std::cout << std::endl << "-- MATERIA CREATION" << std::endl;
	AMateria *	m1 = new Cure();
	AMateria *	m2 = new Cure();
	AMateria *	m3 = new Cure();
	AMateria *	m4 = new Ice();
	AMateria *	m5 = new Ice();
	AMateria *	m6 = new Ice();

	std::cout << std::endl << GREEN << "-- CHARACTER CREATION" << RESET << std::endl;
	Character *	cloud = new Character("Cloud");
	cloud->displayInventory();

	std::cout << std::endl << GREEN << "-- CHARACTER EQUIPPING ITEMS" << RESET << std::endl;
	cloud->equip(NULL);
	cloud->equip(m1);
	cloud->equip(m2);
	cloud->displayInventory();

	std::cout << std::endl << GREEN << "-- CHARACTER DEEP COPY" << RESET << std::endl;
	Character *	cloudCopy = new Character(*cloud);
	cloud->displayInventory();
	std::cout << "Copy ";
    cloudCopy->displayInventory();
	cloud->equip(m3);
	cloud->displayInventory();
	std::cout << "Copy ";
	cloudCopy->displayInventory();
	std::cout << "Deleting copy character:" << std::endl;
	delete cloudCopy;

	std::cout << std::endl << GREEN << "-- CHARACTER EQUIPPING TOO MANY ITEMS" << RESET << std::endl;
	cloud->displayInventory();
	cloud->equip(m4);
	cloud->equip(m5);
	cloud->equip(m6);
	cloud->displayInventory();

	std::cout << std::endl << GREEN << "-- CHARACTER UNEQUIPPING ITEMS" << RESET << std::endl;
	cloud->unequip(-1);
	cloud->unequip(10000);
	cloud->unequip(4);
	cloud->unequip(2);
	cloud->displayInventory();
	cloud->equip(m5);
	cloud->displayInventory();
	cloud->unequip(1);
	cloud->unequip(2);
	cloud->displayInventory();
	cloud->unequip(2);

	std::cout << std::endl << GREEN <<  "-- CHARACTER UNEQUIPPING ITEM DOES NOT DELETE IT" << RESET << std::endl;
	std::cout << "- Creating a tmp materia of type cure:" << std::endl;
	AMateria * tmp = new Cure();
	std::cout << "- Equipping the tmp materia:" << std::endl;
	cloud->equip(tmp);
	std::cout << "- Unequipping the tmp materia:" << std::endl;
	cloud->unequip(1);
	std::cout << "- Deleting the tmp materia:" << std::endl;
	delete tmp;

	std::cout << std::endl << GREEN << "-- CHARACTER DELETION" << RESET << std::endl;
	delete cloud;

	std::cout << std::endl << GREEN <<  "-- CLEANING UP UNEQUIPPED MATERIA" << RESET << std::endl;
	delete m2;
	delete m3;
	delete m5;
	delete m6;
}

void	testMateriaDuelBetweenTwoCharacters(void)
{
	std::cout << GREEN << std::endl <<  "-------------------------------" << std::endl
		<< "    WELCOME TO THE EPIC DUEL" << RESET << std::endl
		<<  "-------------------------------" << std::endl;
	std::cout << std::endl << "-- CREATING MATERIA SOURCE" << std::endl;
	MateriaSource * source = new MateriaSource();
	source->learnMateria(new Cure());
	source->learnMateria(new Ice());

	std::cout << std::endl << GREEN << "-- MATERIA SOURCE CREATES ITEMS ON THE FLOOR" << RESET << std::endl;
	int const	nb_items = 6;
	AMateria * materias[nb_items + 1];
	materias[nb_items] = NULL;

	std::cout << "-- Creating an array of " << nb_items << " materias." << std::endl;
	for (int i = 0; i < nb_items; i++)
	{
		if (i % 2)
			materias[i] = source->createMateria("ice");
		else
			materias[i] = source->createMateria("cure");
	}
	std::cout << std::endl;

	std::cout << std::endl << GREEN << "-- CREATING CHARACTERS" << RESET << std::endl;
	ICharacter * tifa = new Character("Tifa");
	Character *	barret = new Character("Barret");

	std::cout << std::endl << GREEN << "-- EQUIPPING CHARACTERS" << RESET << std::endl;
	for (int i = 0; i < nb_items / 2; i++)
		tifa->equip(materias[i]);
	for (int i = nb_items / 2; i < nb_items; i++)
		barret->equip(materias[i]);

	std::cout << std::endl << "-- 3, 2, 1, 0! FIGHT!" << std::endl;
	tifa->use(-1, *tifa);
	tifa->use(4, *tifa);
	barret->use(3, *tifa);
	tifa->use(2, *tifa);
	tifa->use(1, *barret);
	tifa->use(1, *barret);
	barret->use(1, *barret);
	barret->use(2, *tifa);
	barret->use(1, *tifa);
	tifa->use(0, *barret);

	std::cout << std::endl << GREEN <<  "-- CHARACTER DELETION" << RESET << std::endl;
	delete tifa;
	delete barret;

	std::cout << std::endl << GREEN << "-- MATERIA SOURCE DELETION" << RESET << std::endl;
	delete source;
}

int	main(void)
{

	testMateriaSource();
	testCharacters();
	testMateriaDuelBetweenTwoCharacters();
    school_test();
	return (0);
}