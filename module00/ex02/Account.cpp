#include "Account.hpp"
#include <time.h>
#include <iostream>


int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit){
	this->_amount = initial_deposit;
	this->_accountIndex = Account::_nbAccounts;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount << ";created"<< std::endl;
	Account::_nbAccounts++;
	Account::_totalAmount += initial_deposit;
	return;
}

Account::Account(void){
	this->_amount = 0;
	this->_accountIndex = Account::_nbAccounts;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount << ";created"<< std::endl;
	Account::_nbAccounts++;
	Account::_totalAmount += 0;
	return;
}

Account::~Account(void){
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount << ";closed"<< std::endl;
	return;
}

int	Account::getNbAccounts(void){
	return (Account::_nbAccounts);
}

int	Account::getTotalAmount(void){
	return (Account::_totalAmount);
}

int	Account::getNbDeposits(void){
	return (Account::_totalNbDeposits);
}

int	Account::getNbWithdrawals(void){
	return (Account::_totalNbWithdrawals);
}

void	Account::_displayTimestamp(void){
	time_t t ;
	time(&t);
	std::string	pr(ctime(&t));
	std::cout << "["<< pr.substr(20,4);
	if(pr.substr(4,3).compare("Jan") == 0)
		std::cout << "01";
	if(pr.substr(4,3).compare("Feb") == 0)
		std::cout << "02";
	if(pr.substr(4,3).compare("Mar") == 0)
		std::cout << "03";
	if(pr.substr(4,3).compare("Apr") == 0)
		std::cout << "04";
	if(pr.substr(4,3).compare("May") == 0)
		std::cout << "05";
	if(pr.substr(4,3).compare("Jun") == 0)
		std::cout << "06";
	if(pr.substr(4,3).compare("Jul") == 0)
		std::cout << "07";
	if(pr.substr(4,3).compare("Aug") == 0)
		std::cout << "08";
	if(pr.substr(4,3).compare("Sep") == 0)
		std::cout << "09";
	if(pr.substr(4,3).compare("Oct") == 0)
		std::cout << "10";
	if(pr.substr(4,3).compare("Nov") == 0)
		std::cout << "11";
	if(pr.substr(4,3).compare("Dec") == 0)
		std::cout << "12";
	std::cout << pr.substr(8,2) << "_";
	std::cout << pr.substr(11,2) << pr.substr(14,2) << pr.substr(17,2) << "] ";
}

void	Account::displayAccountsInfos( void ){
	Account::_displayTimestamp();
	std::cout << "accounts:" << Account::_nbAccounts ;
	std::cout << ";total:" << Account::_totalAmount ;
	std::cout << ";deposits:" << Account::_totalNbDeposits ;
	std::cout << ";withdrawals:" << Account::_totalNbWithdrawals ;
	std::cout << std::endl;
	return;
}

void	Account::displayStatus(void) const{
	Account::_displayTimestamp();
	std::cout << "index:" << Account::_accountIndex;
	std::cout << ";amount:" << Account::_amount;
	std::cout << ";deposits:" << Account::_nbDeposits;
	std::cout << ";withdrawals:" << Account::_nbWithdrawals;
	std::cout << std::endl;
	return;
}

int	Account::checkAmount(void) const{
	return (this->_amount);
}

void	Account::makeDeposit(int deposit){
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex;
	std::cout << ";p_amount:" << this->_amount;
	std::cout << ";deposit:" << deposit;
	this->_amount += deposit;
	this->_nbDeposits++;
	Account::_totalAmount += deposit;
	Account::_totalNbDeposits++;
	std::cout << ";amount:" << Account::_amount;
	std::cout << ";nb_deposits:" << this->_nbDeposits;
	std::cout << std::endl;
	return;
}

bool	Account::makeWithdrawal(int withdrawal){
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex;
	std::cout << ";p_amount:" << this->_amount;
	std::cout << ";withdrawal:";
	if (withdrawal > this->_amount)
	{
		std::cout << "refused" << std::endl;
		return (false);
	}
	this->_amount -= withdrawal;
	this->_nbWithdrawals++;
	Account::_totalAmount -= withdrawal;
	Account::_totalNbWithdrawals++;
	std::cout << withdrawal;
	std::cout << ";amount:" << this->_amount;
	std::cout << ";nb_withdrawals:" << this->_nbWithdrawals;
	std::cout << std::endl;
	return (true);
}