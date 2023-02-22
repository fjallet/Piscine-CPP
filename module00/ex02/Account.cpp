#include "Account.hpp"

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit){
	this->_amount = initial_deposit;
	this->_accountIndex = Account::_nbAccounts;
	std::cout << "[19920104_091532] index:" << this->_accountIndex << ";amount:" << this->_amount << "created"<< std::endl;
	Account::_nbAccounts++;
	Account::_totalAmount += initial_deposit;
	return;
}

Account::~Account(void){
	std::cout << "[19920104_091532] index:" << this->_accountIndex << ";amount:" << this->_amount << "closed"<< std::endl;
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

void	Account::displayAccountsInfos( void ){
	Account::_displayTimestamp();
	std::cout << "accounts:" << Account::_nbAccounts ;
	std::cout << "total:" << Account::_totalAmount ;
	std::cout << "deposits:" << Account::_totalNbDeposits ;
	std::cout << "withdrawals:" << Account::_totalNbWithdrawals ;
	std::cout << std::endl;
	return;
}