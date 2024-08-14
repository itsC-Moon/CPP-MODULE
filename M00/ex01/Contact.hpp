
#ifndef Contact_H
#define Contact_H

#include <iostream>

class Contact
{
  public:
	int addInfo();
	void print(int idx);
	void printAll();

  private:
	std::string firstName;
	std::string lastName;
	std::string nickName;
	std::string phoneNumber;
	std::string darkestSecret;

	std::string getFixBuffer(std::string &str);
	int getPhoneNumber();
	int getInfo(std::string &feild, std::string feildName);
};

#endif // Contact_H
