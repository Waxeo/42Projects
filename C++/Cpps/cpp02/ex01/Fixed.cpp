#include "Fixed.Class.hpp"


/*constructeurs / destructeurs*/

Fixed::Fixed( void ) : _Nb(0)
{
	std::cout << "Default constructor called" << std::endl;
    return ;
}

Fixed::Fixed( const int i ) : _Nb(i << _BitsNb)
{
	std::cout << "Int constructor called" << std::endl;
    return ;
}

Fixed::Fixed( const float f ) : _Nb(roundf((f * (1 << _BitsNb))))
{
	std::cout << "Float constructor called" << std::endl;
    return ;
}

Fixed::Fixed( Fixed const &src )
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;

    return ;
}

Fixed::~Fixed( void )
{
	std::cout << "Destructor called" << std::endl;

    return ;
}



/*surcharge d'operateur*/

Fixed	&	Fixed::operator=( Fixed const &rhs )
{
	std::cout << "Assignement operator called" << std::endl;
	
	if ( this != &rhs )
		this->_Nb = rhs.getRawBits();

	return *this;
}

std::ostream	&	operator<<( std::ostream & o, Fixed const &rhs)
{
	o << rhs.toFloat();
	return o;
}



/*accesseur*/

int Fixed::getRawBits( void ) const
{
	std::cout << "Geter called" << std::endl;

	return this->_Nb;
}

void Fixed::setRawBits( int const raw )
{
	std::cout << "Seter called" << std::endl;

	this->_Nb = raw;

	return ;
}



/*utils*/

float	Fixed::toFloat( void ) const
{
	float floatNbr = 0;

	floatNbr = static_cast<float>(this->_Nb) / (1 << this->_BitsNb);
	
	return (floatNbr);
}

int	Fixed::toInt( void ) const
{
	return (this->_Nb >> this->_BitsNb);
}



/*Conversion d'entier vers nombre à virgule fixe :

Pour convertir un entier (comme int) en un nombre à virgule fixe, 
vous pouvez utiliser le bit-shifting pour décaler la virgule de manière appropriée. 
Par exemple, si vous avez un entier int et que vous souhaitez le convertir en un nombre à virgule fixe
avec 8 bits pour la partie fractionnaire, vous pouvez faire un décalage vers la gauche de 8 positions
pour déplacer la virgule de 8 bits vers la droite.
Exemple : int integerNumber = 42; (en tant qu'entier) peut être converti en nombre à virgule fixe
avec 8 bits pour la partie fractionnaire comme ceci : int fixedPointNumber = integerNumber << 8;.



Conversion de nombre à virgule fixe vers entier :

Pour convertir un nombre à virgule fixe en un entier, vous pouvez effectuer un décalage vers la droite
en fonction du nombre de bits réservés pour la partie fractionnaire. Cela supprime la partie
fractionnaire et donne un entier.
Exemple : int integerNumber = fixedPointNumber >> 8; (avec 8 bits réservés pour la partie
fractionnaire) convertira fixedPointNumber (nombre à virgule fixe) en un entier integerNumber.



Conversion de nombre à virgule fixe vers nombre à virgule flottante :

Pour convertir un nombre à virgule fixe en un nombre à virgule flottante (comme float),
vous pouvez utiliser le bit-shifting pour déplacer la virgule vers la position appropriée,
puis effectuer une conversion explicite.
Exemple : float floatNumber = static_cast<float>(fixedPointNumber) / (1 << 8);
convertira fixedPointNumber en floatNumber. Dans cet exemple, nous décalons la virgule de 8 positions
vers la gauche avant la conversion en float.



Conversion de nombre à virgule flottante vers nombre à virgule fixe :

Pour convertir un nombre à virgule flottante en un nombre à virgule fixe,
vous pouvez utiliser le bit-shifting pour déplacer la virgule vers la position appropriée.
Exemple : int fixedPointNumber = static_cast<int>(floatNumber * (1 << 8));
convertira floatNumber en fixedPointNumber avec 8 bits pour la partie fractionnaire.
Ici, nous décalons la virgule de 8 positions vers la droite.



La fonction roundf en C++ est utilisée pour arrondir un nombre à virgule flottante (float)
au nombre entier le plus proche. Elle fait partie de la bibliothèque de fonctions standard C++
et est définie dans l'en-tête <cmath>. La lettre "f" dans le nom roundf indique spécifiquement
que cette fonction s'applique aux nombres à virgule flottante de type float.*/