#include "Account.hpp"
#include <ctime>
#include <iostream>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;


Account::Account( void )
{

}

Account::Account( int initial_deposit )
{
	_amount = initial_deposit;

	std::cout << "[";
	_displayTimestamp();
	std::cout << "]" << " index:" << _nbAccounts << ";amount:" << _amount 
	<< ";created" << std::endl;
	
	_totalAmount += _amount;
	_accountIndex = _nbAccounts;
	_nbAccounts++;
}

Account::~Account( void )
{
	std::cout << "[";
	_displayTimestamp();
	std::cout << "]" << " index:" << _accountIndex << ";amount:" << _amount
	<< ";closed" << std::endl;
}

void	Account::displayAccountsInfos( void )
{
	std::cout << "[";
	_displayTimestamp();
	std::cout << "]" << " accounts:" << _nbAccounts << ";total:" << _totalAmount
	<< ";deposits:" << _totalNbDeposits << ";withdrawals:" << _totalNbWithdrawals
	<< std::endl;
}


void	Account::makeDeposit( int deposit )
{
	int p_amount;

	p_amount = _amount;
	_amount += deposit;
	_totalAmount += deposit;
	_nbDeposits++;
	_totalNbDeposits++;
	std::cout << "[";
	_displayTimestamp();
	std::cout << "]" << " index:" << _accountIndex << ";p_amount:" << p_amount
	<< ";deposit:" << deposit << ";amount:" << _amount
	<< ";nb_deposits:" << _nbDeposits << std::endl;
}

bool	Account::makeWithdrawal( int withdrawal )
{
	int p_amount;

	p_amount = _amount;
	if(withdrawal <= _amount)
	{
		_nbWithdrawals++;
		_amount -= withdrawal;
		_totalAmount -= withdrawal;
		_totalNbWithdrawals++;
		std::cout << "[";
		_displayTimestamp();
		std::cout << "]" << " index:" << _accountIndex << ";p_amount:" << p_amount
		<< ";withdrawal:" << withdrawal << ";amount:" << _amount
		<< ";nb_withdrawals:" << _nbWithdrawals << std::endl;
		return (true);
	}
	std::cout << "[";
	_displayTimestamp();
	std::cout << "]" << " index:" << _accountIndex << ";p_amount:" << p_amount
	<< ";withdrawal:refused" << std::endl;
	return (false);
}

void	Account::displayStatus( void ) const
{
	std::cout << "[";
	_displayTimestamp();
	std::cout << "]" << " index:" << _accountIndex << ";amount:" << _amount
	<< ";deposits:" << _nbDeposits << ";withdrawals:" << _nbWithdrawals << std::endl;
}

void	Account::_displayTimestamp( void )
{
	char        buffer[100];
	time_t      cur_time;
    struct tm   *readable_time;

	cur_time = time(NULL);
    readable_time = localtime(&cur_time);
    
    strftime(buffer, sizeof(buffer), "%Y%m%d_%H%M%S", readable_time);
    std::cout << buffer;
}

int		Account::checkAmount( void ) const
{
	return (_amount);
}

int	Account::getNbAccounts( void )
{
	return (_nbAccounts);
}
int	Account::getTotalAmount( void )
{
	return (_totalAmount);
}
int	Account::getNbDeposits( void )
{
	return (_totalNbDeposits);
}
int	Account::getNbWithdrawals( void )
{
	return (_totalNbWithdrawals);
}



