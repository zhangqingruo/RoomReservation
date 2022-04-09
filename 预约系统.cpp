#include <iostream>
#include "ReservationManager.h"

int main()
{
	int select; //选择身份
	auto orders = new orderFile(ORDER_FILE);
	ReservationManager rm(orders);
	while (true)
	{
		rm.IdentitySelect();
		std::cin >> select;
		switch (select)
		{
		case 1:  //学生代表
			rm.LogInStu();
			break;
		case 2:  //老师
			rm.LogInTea();
			break;
		case 3:  //管理员
			rm.LogInMan();
			break;
		case 0:  //退出
			if (orders != NULL) {
				delete orders;
				orders = NULL;
			}
			rm.exitSystem();
			break;
		default:
			break;
		}
	}
	system("pause");
	return 0;
}