#include "Point.Class.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
// A = (0, 0), B = (10, 30), C = (20, 0), P(10, 15)

/*		calcul vecteurs cotes des triangles		*/

    Point	AB(b.getX() - a.getX(), b.getY() - a.getY());
    Point	BC(c.getX() - b.getX(), c.getY() - b.getY());
    Point	CA(a.getX() - c.getX(), a.getY() - c.getY());

/*		calcul vecteurs entre P et sommets		*/

	Point	AP(point.getX() - a.getX(), point.getY() - a.getY());
    Point	BP(point.getX() - b.getX(), point.getY() - b.getY());
    Point	CP(point.getX() - c.getX(), point.getY() - c.getY());

/*		calcul des produtis vectoriels		*/

	float	ABAP = (AB.getX() * AP.getY()) - (AB.getY() * AP.getX());
	float 	BCBP = (BC.getX() * BP.getY()) - (BC.getY() * BP.getX());
	float 	CACP = (CA.getX() * CP.getY()) - (CA.getY() * CP.getX());

/*	verif	*/

	if (ABAP == 0 || BCBP == 0 || CACP == 0)
		return false;
	if ((ABAP > 0) && (BCBP < 0 || CACP < 0))
		return false;
	if ((ABAP < 0) && (BCBP > 0 || CACP > 0))
		return false;
	return true;
}
