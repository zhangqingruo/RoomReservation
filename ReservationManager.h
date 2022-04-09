#pragma once
#include "Student.h"
#include "Teacher.h"
#include "Manager.h"
#include "orderFile.h"
class ReservationManager
{
public:
	ReservationManager(orderFile* orders):m_orders(orders){}
	~ReservationManager(){}

	void IdentitySelect();
	void LogInStu();
	void LogInTea();
	void LogInMan();
	void exitSystem();

private:
	Identity* person{ NULL };
	orderFile* m_orders;
};

