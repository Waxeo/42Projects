#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include "HumanA.Class.hpp"
#include "HumanB.Class.hpp"
#include "Weapon.Class.hpp"

int main()
{
	{
		Weapon club = Weapon("crude spiked club");
		HumanA bob("Bob", club);
		bob.attack();
		club.setType("some other type of club");
		bob.attack();
	}
	{
		Weapon club = Weapon("crude spiked club");
		HumanB jim("Jim");
		jim.setWeapon(club);
		jim.attack();
		club.setType("some other type of club");
		jim.attack();
	}
	return 0;
}

/*

Maintenant, créez deux classes HumanA et HumanB. Toutes deux possèdent une Weapon
et un name, ainsi qu’une fonction membre attack() affichant (sans les chevrons bien sûr) :
	<name> attacks with their <weapon type>
HumanA et HumanB sont presque identiques, à l’exception de deux petits détails :

• Alors que le constructeur de HumanA prend une Weapon comme paramètre,
ce n’est pas le cas de celui de HumanB.

• HumanB n’aura pas toujours une Weapon,  ->pointeur car possiblement pas d'init
tandis que HumanA en aura forcément une.  ->ref car doit toujours etre init   */