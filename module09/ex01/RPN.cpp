#include "RPN.hpp"

#include <fstream>
#include <sstream>
#include <iostream>
#include <algorithm>

RPN::RPN(std::string input){
	size_t	i = 0;
	std::string	str;
	this->parsing(input);
	int	n;
	//int	res;
	for (; i < input.size(); i++){
		if (std::isdigit(input[i])){
			str = input.substr(i,1);
			std::istringstream str_stream(str);
			str_stream >> n;
			_stack.push(n);
		}
		if (input[i] == '+'){
			this->sum();
		}
		if (input[i] == '-'){
			this->sub();
		}
		if (input[i] == '*'){
			this->mul();
		}
		if (input[i] == '/'){
			this->div();
		}
	}
	(void)input;
}

RPN::~RPN(){}

void	RPN::parsing(std::string str){
	size_t	i = 0;
	int		n = 2;
	int		o = 0;
	if (!std::isdigit(str[i++]))
		throw RPN::WrongInputFormaException();
	if (str[i++] != ' ')
		throw RPN::WrongInputFormaException();
	if (!std::isdigit(str[i++]))
		throw RPN::WrongInputFormaException();
	for (; i < str.size(); i++){
		if (i % 2 == 1 && str[i] != ' ')
			throw RPN::WrongInputFormaException();
		else if (i % 2 == 0 && (std::isdigit(str[i]) || str[i] == '+' \
		|| str[i] == '-' || str[i] == '*' || str[i] == '/')){
		}
		else if (i % 2 == 0)
			throw RPN::WrongInputFormaException();
		if (std::isdigit(str[i]))
			n++;
		if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/')
			o++;
		if (o >= n)
			throw RPN::WrongInputFormaException();
	}
	//std::cout << o << " " << n << std::endl;
	if (o + 1 != n)
		throw RPN::WrongInputFormaException();
	(void)str;
}

void	RPN::sum(){
	int	res;
	int	t = _stack.top();
	_stack.pop();
	int	n = _stack.top();
	_stack.pop();
	res = t + n;
	_stack.push(res);
}

void	RPN::sub(){
	int	res;
	int	t = _stack.top();
	_stack.pop();
	int	n = _stack.top();
	_stack.pop();
	res = n - t;
	_stack.push(res);
}

void RPN::mul(){
	int	res;
	int	t = _stack.top();
	_stack.pop();
	int	n = _stack.top();
	_stack.pop();
	res = n * t;
	_stack.push(res);
}

void RPN::div(){
	int	res;
	int	t = _stack.top();
	_stack.pop();
	int	n = _stack.top();
	_stack.pop();
	res = n / t;
	_stack.push(res);
}

void	RPN::print(){
	std::cout << _stack.top() << std::endl;
}


const char*			RPN::WrongInputFormaException::what() const throw(){
	return ("invald format of input text");
}