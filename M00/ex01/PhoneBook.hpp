
#ifndef PhoneBook_H
#define PhoneBook_H

#include "Contact.hpp"

class PhoneBook
{
  private:
	Contact contacts[8];
	int idx;
	int size;

	int addContact();
	void display();

  public:
	void run();
	PhoneBook();
};

#endif // PhoneBook_H
