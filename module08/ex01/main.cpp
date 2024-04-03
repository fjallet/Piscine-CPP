#include "Span.hpp"

int main()
{
Span sp = Span(5);
try{
	std::cout << sp.shortestSpan() << std::endl;
}
catch (std::exception& e){
	std::cout << e.what() << std::endl;
}
try{
	std::cout << sp.longestSpan() << std::endl;
}
catch (std::exception& e){
	std::cout << e.what() << std::endl;
}
sp.addNumber(6);
try{
	std::cout << sp.shortestSpan() << std::endl;
}
catch (std::exception& e){
	std::cout << e.what() << std::endl;
}
try{
	std::cout << sp.longestSpan() << std::endl;
}
catch (std::exception& e){
	std::cout << e.what() << std::endl;
}
sp.addNumber(3);
sp.addNumber(17);
sp.addNumber(9);
sp.addNumber(11);
std::cout << sp << std::endl;
std::cout << sp.shortestSpan() << std::endl;
std::cout << sp.longestSpan() << std::endl;
try{
	sp.addNumber(11);
}
catch (std::exception& e){
	std::cout << e.what() << std::endl;
}
Span sp2 = Span(5);
sp2.fill(5);
std::cout << sp2 << std::endl;
std::cout << sp2.shortestSpan() << std::endl;
std::cout << sp2.longestSpan() << std::endl;
return (0);
}