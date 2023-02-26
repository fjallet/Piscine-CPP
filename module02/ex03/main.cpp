#include "bsp.hpp"

int main( void ) {
Point	A(2.5f , 1.7f);
Point	B(4, 6.2f);
Point	C(0.3f, 3.8f);
Point	P1(3, 3);
Point	P2(1, 2);
Point	P3(2, 5);
Point	P4(4, 4);
Point	P5(2.8f, 2.5f);
Point	P6(3.5f, 3.5f);
Point	P7(0.5f, 1.5f);
Point	P8(5, 5);
Point	P9(2, 0.5f);
Point	P10(2.5f, 6);

if (bsp(A, B, C, P1))
	std::cout << "P1 est a l'interieur du triangle" << std::endl;
else
	std::cout << "P1 est a l'exterieur du triangle" << std::endl;
if (bsp(A, B, C, P2))
	std::cout << "P2 est a l'interieur du triangle" << std::endl;
else
	std::cout << "P1 est a l'exterieur du triangle" << std::endl;
if (bsp(A, B, C, P3))
	std::cout << "P3 est a l'interieur du triangle" << std::endl;
else
	std::cout << "P1 est a l'exterieur du triangle" << std::endl;
if (bsp(A, B, C, P4))
	std::cout << "P4 est a l'interieur du triangle" << std::endl;
else
	std::cout << "P1 est a l'exterieur du triangle" << std::endl;
if (bsp(A, B, C, P5))
	std::cout << "P5 est a l'interieur du triangle" << std::endl;
else
	std::cout << "P1 est a l'exterieur du triangle" << std::endl;
if (bsp(A, B, C, P6))
	std::cout << "P6 est a l'interieur du triangle" << std::endl;
else
	std::cout << "P1 est a l'exterieur du triangle" << std::endl;
if (bsp(A, B, C, P7))
	std::cout << "P7 est a l'interieur du triangle" << std::endl;
else
	std::cout << "P1 est a l'exterieur du triangle" << std::endl;
if (bsp(A, B, C, P8))
	std::cout << "P8 est a l'interieur du triangle" << std::endl;
else
	std::cout << "P1 est a l'exterieur du triangle" << std::endl;
if (bsp(A, B, C, P9))
	std::cout << "P9 est a l'interieur du triangle" << std::endl;
else
	std::cout << "P1 est a l'exterieur du triangle" << std::endl;
if (bsp(A, B, C, P10))
	std::cout << "P10 est a l'interieur du triangle" << std::endl;
else
	std::cout << "P1 est a l'exterieur du triangle" << std::endl;
return 0;
}