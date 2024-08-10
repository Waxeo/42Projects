#include "Account.hpp"

//Constructor & Destructor

Account::Account(int initial_deposit) : _amount(initial_deposit)
{
	this->_accountIndex = getNbAccounts();
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	Account::_totalAmount += this->_amount;

	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex 
	<< ";amount:" << this->_amount 
	<< ";created" << std::endl;

	Account::_nbAccounts++;
	return ;
}

Account::~Account( void )
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex 
	<< ";amount:" << _amount 
	<< ";closed" << std::endl;

	return ;
}

//
//Accessors

int	Account::getNbAccounts( void )
{
	return (Account::_nbAccounts);
}

int	Account::getTotalAmount( void )
{
	return (Account::_totalAmount);
}

int	Account::getNbDeposits( void )
{
	return (Account::_totalNbDeposits);
}

int	Account::getNbWithdrawals( void )
{
	return (Account::_totalNbWithdrawals);
}

//
//Display Infos & Status

void Account::_displayTimestamp( void )
{
    std::time_t now = std::time(&now);
    char buffer[80];

    std::strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", std::localtime(&now));

    std::cout << "[" << buffer << "] ";

    return ;
}

void	Account::displayAccountsInfos( void )
{
	_displayTimestamp();
	std::cout << "accounts:" << getNbAccounts() 
	<< ";total:" << getTotalAmount() 
	<< ";deposits:" << getNbDeposits() 
	<< ";withdrawals:" << getNbWithdrawals() << std::endl;
	
	return ;
}

void	Account::displayStatus( void ) const
{
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex 
	<< ";amount:" << this->_amount 
	<< ";deposits:" << this->_nbDeposits 
	<< ";withdrawals:" << this->_nbWithdrawals << std::endl;

	return ;
}

//
//Actions

int		Account::checkAmount( void ) const
{
	return this->_amount;
}

void	Account::makeDeposit( int deposit )
{
	this->_nbDeposits++;
	Account::_totalNbDeposits++;

	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex 
	<< ";p_amount:" << this->_amount
	<< ";deposit:" << deposit 
	<< ";amount:" << this->_amount + deposit
	<< ";nb_deposits:" << this->_nbDeposits << std::endl;

	this->_amount += deposit;
	Account::_totalAmount += deposit;

	return ;
}

bool	Account::makeWithdrawal( int withdrawal )
{
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex 
	<< ";p_amount:" << this->_amount
	<< ";withdrawal:";

	if (withdrawal > checkAmount())
	{
		std::cout << "refused" << std::endl;
		return false;
	}
	this->_nbWithdrawals++;
	this->_amount -= withdrawal;
	Account::_totalNbWithdrawals++;
	Account::_totalAmount -= withdrawal;

	std::cout << withdrawal 
	<< ";amount:" << this->_amount 
	<< ";nb_withdrawals:" << this->_nbWithdrawals << std::endl;

	return true;
}

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;
