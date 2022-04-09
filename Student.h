#pragma once
#include "Identity.h"
class Student : public Identity
{
public:
	Student() = default;
	Student(int id,std::string name,std::string pwd, orderFile* orders):
		stu_id(id), Identity(name,pwd,orders){}
	void operMenu();
	void showMenu();
	int getId() const { return stu_id; }
	void setId(int id) { stu_id = id; }
	
private:
	int stu_id;
};

