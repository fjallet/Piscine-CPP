#include "BitcoinExchange.hpp"

#include <fstream>
#include <sstream>
#include <iostream>
#include <algorithm>

BitcoinExchange::BitcoinExchange(std::string const & data){
	std::ifstream db(data.c_str());
	try{
	if (!db.is_open()) {
		throw BitcoinExchange::AccessFileException();
	}
	std::string line;
	std::getline(db, line);
	while (std::getline(db, line)) {
		std::string::size_type pos = line.find(',');
		if (pos == std::string::npos) {
			throw BitcoinExchange::WrongDataFormaException();
			continue;
		}
		std::string date = line.substr(0, 10);
		std::string str = line.substr(11);
		double rate;
		std::istringstream rate_stream(str);
		if (!(rate_stream >> rate)) {
			throw BitcoinExchange::WrongDataFormaException();
		}
		if (date == "2011-01-03")
			std::cout << rate << std::endl;
		_data[date] = rate;
	}
	}
	catch (const BitcoinExchange::WrongDataFormaException& e) {
			std::cerr << "Error: " << e.what() << std::endl;
	}
	catch (const BitcoinExchange::AccessFileException& e) {
			std::cerr << "Error: " << e.what() << std::endl;
	}
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const & rhs){
	*this = rhs;
}

BitcoinExchange&	BitcoinExchange::operator=(BitcoinExchange const & rhs){
	_data = rhs.getMap();
	return (*this);
}

BitcoinExchange::~BitcoinExchange(){}

void	BitcoinExchange::btc(std::string input){
	std::ifstream	inp(input.c_str());
	try{
	if (!inp.is_open()) {
		throw BitcoinExchange::AccessFileException();
	}
	std::string		line;
	std::getline(inp, line);
	int i = 0;
	std::string	date;
	float	value;
	while (std::getline(inp, line)) {
		i = 0;
		try{
		if (line.size() < 14)
			throw BitcoinExchange::WrongInputFormaException();
		for	(; i < 4; i++){
			if (!std::isdigit(line[i]))
				throw BitcoinExchange::WrongInputFormaException();
		}
		if (line[i++] != '-')
			throw BitcoinExchange::WrongInputFormaException();
		for	(; i < 7; i++){
			if (!std::isdigit(line[i]))
				throw BitcoinExchange::WrongInputFormaException();
		}
		if (line[i++] != '-')
			throw BitcoinExchange::WrongInputFormaException();
		for	(; i < 10; i++){
			if (!std::isdigit(line[i]))
				throw BitcoinExchange::WrongInputFormaException();
		}
		i++;
		if (line[i] != '|')
			throw BitcoinExchange::WrongInputFormaException();
		date = line.substr(0,10);
		std::string	v_str = line.substr(13);
		std::istringstream v_stream(v_str);
		if (!(v_stream >> value))
			throw BitcoinExchange::WrongInputFormaException();
		if (value < 0)
			throw BitcoinExchange::NegativeNumberException();
		if (value > 1000)
			throw BitcoinExchange::TooLargeException();
		checkDate(date);
		findData(date, value);
		}
		catch (const BitcoinExchange::WrongInputFormaException& e) {
			std::cerr << "Error: " << e.what() << " => " << line << std::endl;
		}
		catch (const BitcoinExchange::NegativeNumberException& e) {
			std::cerr << "Error: " << e.what() << std::endl;
		}
		catch (const BitcoinExchange::WrongDateException& e) {
			std::cerr << "Error: " << e.what() << std::endl;
		}
		catch (const std::out_of_range& e) {
			std::cerr << "Error: " << e.what() << std::endl;
		}
		catch (const BitcoinExchange::TooLargeException& e) {
			std::cerr << "Error: " << e.what() << std::endl;
		}
	}
	}
	catch (const BitcoinExchange::AccessFileException& e) {
			std::cerr << "Error: " << e.what() << std::endl;
		}
}

void	BitcoinExchange::checkDate(std::string date){
	int	year;
	int	month;
	int	day;
	std::string	y = date.substr(0,4);
	std::string	m = date.substr(5,2);
	std::string	d = date.substr(8,2);
	std::istringstream y_stream(y);
	std::istringstream m_stream(m);
	std::istringstream d_stream(d);
	if (!(y_stream >> year))
		throw BitcoinExchange::WrongDateException();
	if (year > 2022 || year < 2009)
		throw BitcoinExchange::WrongDateException();
	if (!(m_stream >> month))
		throw BitcoinExchange::WrongDateException();
	if (month > 12 || month < 1)
		throw BitcoinExchange::WrongDateException();
	if (!(d_stream >> day))
		throw BitcoinExchange::WrongDateException();
	if (day > 31 || day < 1)
		throw BitcoinExchange::WrongDateException();
}

void	BitcoinExchange::findData(std::string date, float value){
	std::map<std::string, float>::iterator witness = _data.end();
	int	d;
	int	md;
	for(std::map<std::string, float>::iterator it =_data.begin(); it != witness; it++){
		if (date.substr(0,4) == it->first.substr(0,4)){
			if (date.substr(5,2) == it->first.substr(5,2)){
				if (date.substr(8,2) == it->first.substr(8,2)){
					std::cout << date << " => " << value << " = " << it->second * value << std::endl;
					return ;
				}
				std::string	day = date.substr(8,2);
				std::istringstream d_stream(day);
				d_stream >> day;
				std::string	mday = it->first.substr(8,2);
				std::istringstream md_stream(mday);
				md_stream >> mday;
				//std::cout << day << "  " << mday << std::endl;
				if (day <= mday){
					it--;
					std::cout << date << " => " << value << " = " << (it)->second * value << std::endl;
					return;
				}
			}
		}
	}
	(void)d;
	(void)md;
}

std::map<std::string, float>	BitcoinExchange::getMap() const{
	return (_data);
}


const char*			BitcoinExchange::WrongDataFormaException::what() const throw(){
	return ("invald format of database");
}

const char*			BitcoinExchange::WrongInputFormaException::what() const throw(){
	return ("invald format of input text");
}

const char*			BitcoinExchange::AccessFileException::what() const throw(){
	return ("could not open file");
}

const char*			BitcoinExchange::NegativeNumberException::what() const throw(){
	return ("not a positive number");
}

const char*			BitcoinExchange::WrongDateException::what() const throw(){
	return ("Wrong date input");
}

const char*			BitcoinExchange::TooLargeException::what() const throw(){
	return ("too large a number");
}



