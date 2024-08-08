#include "Contact.hpp"
#include <cstdlib>
#include <iostream>

int Contact::getPhoneNumber()
{
	std::string str;
	std::cout << "Enter phone number: ";
	std::getline(std::cin, str);
	if (str.empty())
		return (std::cout << "phone Number should not be empty\n", 1);
	for (size_t i = 0; i < str.length(); i++)
	{
		if (std::isdigit(str[i]) == 0)
		{
			std::cout << "Invalid phone number" << std::endl;
			return (1);
		}
	}
	this->phoneNumber = str;
	return (0);
}
int Contact::getInfo(std::string &feild, std::string feildName)
{
	std::string str;
	std::cout << "Enter " << feildName << ": ";
	if (!std::getline(std::cin, str))
		return (-1);
	if (str.empty())
		return (std::cout << feildName << " should not be empty\n", 1);
	feild = str;
	return (0);
}

int Contact::addInfo()
{
	int readFlag;
	while (1)
	{
		readFlag = this->getInfo(this->firstName, "firstName");
		if (readFlag == -1)
			return (-1);
		if (readFlag == 0)
			break;
	}
	while (1)
	{
		readFlag = this->getInfo(this->lastName, "lastName");
		if (readFlag == -1)
			return (-1);
		if (readFlag == 0)
			break;
	}
	while (1)
	{
		readFlag = this->getInfo(this->nickName, "nickName");
		if (readFlag == -1)
			return (-1);
		if (readFlag == 0)
			break;
	}
	while (1)
	{
		readFlag = this->getPhoneNumber();
		if (readFlag == -1)
			return (-1);
		if (readFlag == 0)
			break;
	}
	while (1)
	{
		readFlag = this->getInfo(this->darkestSecret, "darkestSecret");
		if (readFlag == -1)
			return (-1);
		if (readFlag == 0)
			break;
	}
	return (1);
}

std::string Contact::getFixBuffer(std::string &str)
{
	std::string buffer(10, ' ');
	for (size_t i = 0; i < 10 && i < str.size(); i++)
		buffer[i] = str[i];
	if (str.size() > 10)
		buffer[9] = '.';
	return buffer;
}

void Contact::print(int idx)
{
	std::cout << idx << std::string(9, ' ') << "|";
	std::cout<< this->getFixBuffer(this->firstName) << "|";
	std::cout<< this->getFixBuffer(this->lastName)<<"|";
	std::cout<< this->getFixBuffer(this->nickName)<<"\n";
}
