
#ifndef PhoneBook_H
#define PhoneBook_H

#include "Contact.hpp"

class PhoneBook
{
	public:
		void run();
		PhoneBook();
	private:
		int addContact();
		void display();
		int idx;
		int size;
		Contact contacts[8];

};

#endif // PhoneBook_H
