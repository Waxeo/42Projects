#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base * generate(void)
{
	Base *child;

	std::srand(std::time(NULL));
	int x = std::rand() % 3;

	switch (x)
	{
		case 0:
			child = new A();
			break;

		case 1:
			child = new B();
			break;
		case 2:
			child = new C();
			break;
	}
	
	return child;
}


void identify(Base* p)
{
	A	*test = dynamic_cast<A *>(p);
	if (test)
	{
		std::cout << "This class is identified as A class." << std::endl;
		return ;
	}

	B	*test2 = dynamic_cast<B *>(p);
	if (test2)
	{
		std::cout << "This class is identified as B class." << std::endl;
		return ;
	}

	C	*test3 = dynamic_cast<C *>(p);
	if (test3)
	{
		std::cout << "This class is identified as C class." << std::endl;
		return ;
	}
}


void identify(Base& p)
{
	try
	{
		A& ARef = dynamic_cast<A&>(p);

		std::cout << "This class is identified as A class." << std::endl;
		(void)ARef;
		return ;
	}
	catch(...)
	{
		std::cerr << "Conversion to A failed" << std::endl;
	}
	

	try
	{
		B& BRef = dynamic_cast<B&>(p);

		std::cout << "This class is identified as B class." << std::endl;
		(void)BRef;
		return ;
	}
	catch(...)
	{
		std::cerr << "Conversion to B failed" << std::endl;
	}


	try
	{
		C& CRef = dynamic_cast<C&>(p);

		std::cout << "This class is identified as C class." << std::endl;
		(void)CRef;
		return ;
	}
	catch(...)
	{
		std::cerr << "Conversion to C failed" << std::endl;
	}
}


int main()
{
	std::cout << GREEN << "/////Test Pointeur/////" << RESET << std::endl;

	Base* basePtr = generate();
	identify(basePtr);

	delete basePtr;

	std::cout << GREEN << "/////Test Reference/////" << RESET << std::endl;

	A objRef = A();
	Base& baseRef = objRef;
	identify(baseRef);

	return 0;
}

//Sans le bloc try-catch pour la fonction identify(Base& p), cette exception serait propagée dans la pile d'appels du programme, et si elle n'était pas capturée, elle pourrait provoquer un arrêt inattendu du programme.