#include "Account.hpp"
#include <iostream>
#include <ostream>

// [19920104_091532] index:0;amount:42;created
// [19920104_091532] index:1;amount:54;created
// [19920104_091532] index:2;amount:957;created
// [19920104_091532] index:3;amount:432;created
// [19920104_091532] index:4;amount:1234;created
// [19920104_091532] index:5;amount:0;created
// [19920104_091532] index:6;amount:754;created
// [19920104_091532] index:7;amount:16576;created
// [19920104_091532] accounts:8;total:20049;deposits:0;withdrawals:0

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;
int Account::getNbAccounts()
{
	return Account::_nbAccounts;
}

Account::Account(int initial_deposit)
{
	Account::_displayTimestamp();
	this->_accountIndex = Account::_nbAccounts;
	Account::_nbAccounts++;
	this->_amount = initial_deposit;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	Account::_totalAmount += initial_deposit;
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << this->_amount << ";created";
	std::cout << std::endl;
}

void Account::displayStatus() const
{
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "deposits:" << this->_nbDeposits << ";";
	std::cout << "withdrawals:" << this->_nbWithdrawals;
	std::cout << std::endl;
}
void Account::displayAccountsInfos()
{
	Account::_displayTimestamp();
	std::cout << "accounts:" << Account::_nbAccounts << ";";
	std::cout << "total:" << Account::_totalAmount << ";";
	std::cout << "deposits:" << Account::_totalNbDeposits << ";";
	std::cout << "withdrawals:" << Account::_totalNbWithdrawals;
	std::cout << std::endl;
}

void Account::makeDeposit(int deposit)
{
	this->_nbDeposits += 1;
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "p_amount:" << this->_amount << ";";
	std::cout << "deposit:" << deposit << ";";
	std::cout << "amount:" << this->_amount + deposit << ";";
	std::cout << "nb_deposits:" << this->_nbDeposits;
	this->_amount += deposit;
	Account::_totalAmount += deposit;
	Account::_totalNbDeposits++;
	std::cout << std::endl;
}

// [19920104_091532] index:0;p_amount:47;withdrawal:refused
// [19920104_091532] index:1;p_amount:819;withdrawal:34;amount:785;nb_withdrawals:1
// [19920104_091532] index:2;p_amount:1521;withdrawal:657;amount:864;nb_withdrawals:1
// [19920104_091532] index:3;p_amount:434;withdrawal:4;amount:430;nb_withdrawals:1
// [19920104_091532] index:4;p_amount:1321;withdrawal:76;amount:1245;nb_withdrawals:1
// [19920104_091532] index:5;p_amount:23;withdrawal:refused
// [19920104_091532] index:6;p_amount:763;withdrawal:657;amount:106;nb_withdrawals:1
bool Account::makeWithdrawal(int withdrawals)
{
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "p_amount:" << this->_amount << ";";
	std::cout << "withdrawal:";
	if (withdrawals > this->_amount)
	{
		std::cout << "refused";
		std::cout << std::endl;
		return (false);
	}
	this->_amount -= withdrawals;
	this->_nbWithdrawals++;
	Account::_totalAmount -= withdrawals;
	Account::_totalNbWithdrawals++;
	std::cout << withdrawals<<";";
	std::cout << "amount:" << this->_amount<<";";
	std::cout<< "nb_withdrawals:"<<this->_nbWithdrawals;
	std::cout << std::endl;
	return (true);
}
Account::~Account()
{
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << this->_amount << ";closed";
	std::cout << std::endl;
}
void Account::_displayTimestamp(void)
{
	time_t now = std::time(0);
	struct tm *tstruct = std::localtime(&now);
	std::cout << "[";
	std::cout << tstruct->tm_year + 1900;
	std::cout << tstruct->tm_mon;
	std::cout << tstruct->tm_mday;
	std::cout << "_";
	std::cout << tstruct->tm_hour;
	std::cout << tstruct->tm_min;
	std::cout << tstruct->tm_sec;
	std::cout << "] ";
}
