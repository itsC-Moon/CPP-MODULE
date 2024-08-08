#include "PhoneBook.hpp"
#include <string>
PhoneBook::PhoneBook()
{
	this->idx = 0;
	this->size = 0;
}

int PhoneBook::addContact()
{
	idx %= 8;
	if (this->contacts[idx].addInfo() == -1)
		return (-1);
	size += (size < 8);
	idx++;
	return (0);
}
void PhoneBook::display()
{
	for (int i = 0; i < size; i++) 
		contacts[i].print(i);
}
void PhoneBook::run()
{
	std::string cmd;
	std::cout << "Whats can i do for you ADD SEARCH or EXIT\n";
	std::cout << ">> ";
	while (std::getline(std::cin, cmd))
	{
		if (cmd == "EXIT")
			return ;
		else if (cmd == "ADD")
			this->addContact();
		else if (cmd == "SEARCH")
			this->display();
		else
			std::cout << "Invalid Command\n";
		std::cout << ">> ";
	}
}
