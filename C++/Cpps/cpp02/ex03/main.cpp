#include "Point.Class.hpp"

int main ( void )
{
    /*Inside*/
    if ( bsp( Point(0, 0), Point(10, 30), Point(20, 0), Point(10, 15) ) == true )
        std::cout << BLUE << "Point is in the triangle" << RESET << std::endl;
    else
        std::cout << RED << "Point is not in the triangle" << RESET << std::endl;
    
    
    /*Outside*/
    if ( bsp( Point(0, 0), Point(10, 30), Point(20, 0), Point(30, 15) ) == true )
        std::cout << BLUE << "Point is in the triangle" << RESET << std::endl;
    else
        std::cout << RED << "Point is not in the triangle" << RESET << std::endl;
    
     /*Sur un point ou un segment*/
    if ( bsp( Point(0, 0), Point(10, 30), Point(20, 0), Point(10, 0) ) == true )
        std::cout << BLUE << "Point is in the triangle" << RESET << std::endl;
    else
        std::cout << RED << "Point is not in the triangle" << RESET << std::endl;
    
    return 0;
}

/*

Input: A = (0, 0), B = (10, 30), C = (20, 0), P(10, 15)
Output: Inside
Explanation:
              B(10,30)
                / \
               /   \
              /     \
             /   P   \      P'
            /         \
     A(0,0) ----------- C(20,0) 

Input: A = (0, 0), B = (10, 30), C = (20, 0), P(30, 15)
Output: Outside
Explanation:
              B(10,30)
                / \
               /   \
              /     \
             /       \      P
            /         \
     A(0,0) ----------- C(20,0)

Input: A = (0, 0), B = (10, 30), C = (20, 0), P(10, 0)
Output: Outside
Explanation:
              B(10,30)
                / \
               /   \
              /     \
             /       \      
            /         \
     A(0,0) -----P----- C(20,0)  */