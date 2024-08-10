#ifndef POINT_CLASS_HPP
# define POINT_CLASS_HPP

#include "Fixed.Class.hpp"

class Point
{
	public:

		Point( void );
		Point( const float X, const float Y );
		Point( Point const &src );
		~Point( void );

		Point	&operator=( Point const &src );

		float getX( void ) const;
		float getY( void ) const;

		void setX( Fixed vec );
		void setY( Fixed vec );


	private:

        const Fixed   _x;
        const Fixed   _y;

};

bool bsp( Point const a, Point const b, Point const c, Point const point);
#endif