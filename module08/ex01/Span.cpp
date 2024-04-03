#include "Span.hpp"

Span::Span() : _n(0), _vect(std::vector<int>()){
	_long = 0;
	_short = 0;
	_it = _vect.begin();
}

Span::Span(unsigned int n) : _n(n), _vect(std::vector<int>(n)){
	_long = 0;
	_short = 0;
	_it = _vect.begin();
}

Span::Span(Span const & rhs){
	*this = rhs;
}

Span& Span::operator=(Span const & rhs){
	_n = rhs.getSize();
	_vect = rhs.getVect();
	_short = rhs.shortestSpan();
	_long = rhs.longestSpan();
	_it = rhs.getIt();
	return *this;
}

Span::~Span(){}

int							Span::getSize() const{
	return (_n);
}

std::vector<int>			Span::getVect() const{
	return (_vect);
}

std::vector<int>::iterator	Span::getIt() const{
	return (_it);
}

void	Span::addNumber(int a){

	if (_it == _vect.end()){
		throw Span::SpanFullException();
	}
	if (_it == _vect.begin()){
		*_it = a;
		_it++;
		return;
	}
	std::vector<int>::iterator	temp = _it;
	temp--;
	if (temp == _vect.begin()){
		*_it = a;
		if (*_it >= *temp){
			_long = *_it - *temp;
			_short = *_it - *temp;
		}
		else{
			_long = *temp - *_it;
			_short = *temp - *_it;
		}
		_it++;
		return;
	}
	int	l;
	int	s;
	if (_it != _vect.end()){
		int res;
		res = findShort(a);
		if (res < _short)
			_short = res;
		res = findLong(a);
		if (res > _long)
			_long = res;
		*_it = a;
		_it++;
	}
}

void	Span::fill(int n){
	std::srand(static_cast<unsigned int>(std::time(0)));
	for(int i = 0; i < n; i++){
		this->addNumber(std::rand() % 1000);
	}
}

int		Span::shortestSpan() const{
	if (_it == _vect.begin()){
		throw Span::SpanEmptyException();
	}
	std::vector<int>::iterator	temp = _it;
	temp--;
	if (temp == _vect.begin()){
		throw Span::SpanEmptyException();
	}
	return (_short);
}

int		Span::longestSpan() const{
	if (_it == _vect.begin()){
		throw Span::SpanEmptyException();
	}
	std::vector<int>::iterator	temp = _it;
	temp--;
	if (temp == _vect.begin()){
		throw Span::SpanEmptyException();
	}
	return (_long);
}

int		Span::findShort(int a){
	int	res;
	int	temp;
	std::vector<int>::iterator it = _vect.begin();
	if (a >= *it)
		res = a - *it;
	else
		res = *it - a;
	for (; it <= _it; it++) {
		if (a >= *it)
			temp = a - *it;
		else
			temp = *it - a;
		if (temp < res)
			res = temp;
	}
	return (res);
}

int		Span::findLong(int a){
	int	res;
	int	temp;
	std::vector<int>::iterator it = _vect.begin();
	if (a >= *it)
		res = a - *it;
	else
		res = *it - a;
	for (; it < _it; ++it) {
		if (a >= *it)
			temp = a - *it;
		else
			temp = *it - a;
		if (temp > res)
			res = temp;
	}
	return (res);
}

const char*			Span::SpanFullException::what() const throw(){
	return ("Span is full!");
}

const char*			Span::SpanEmptyException::what() const throw(){
	return ("Not enought numbers in Span!");
}

std::ostream &		operator<<(std::ostream & o, Span const & i){
	const std::vector<int>& vect = i.getVect();
	//std::vector<int>::iterator it = vect.begin();
	std::cout << "[";
	for (auto it = vect.begin(); it < vect.end(); ++it) {
		std::cout << " " << *it << " ";
	}
	std::cout << "]";
	return (o);
}