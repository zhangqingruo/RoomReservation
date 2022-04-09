#pragma once
#include "Identity.h"
class Teacher : public Identity
{
public:
	Teacher() = default;
	Teacher(int id, std::string name, std::string pwd, orderFile* orders) :
		tea_id(id), Identity(name, pwd,orders) {}
	void operMenu();
	void showMenu();

private:
	int tea_id;
};

