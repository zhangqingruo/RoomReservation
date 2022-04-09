#include "Student.h"
#include "orderFile.h"
#include "globalFile.h"

void Student::operMenu()
{
	int select;
	while (true)
	{
		showMenu();
		std::cin >> select;
		switch (select)
		{
		case 1:  //申请预约
			m_orders->applyOrder(this);
			break;
		case 2:  //查看我的预约
			m_orders->checkMyOrder(this);
			break;
		case 3:  //查看所有预约
			m_orders->checkOrder();
			break;
		case 4:  //取消预约
			m_orders->cancelOrder(this);
			break;
		case 0:  //注销登录
			std::cout << "注销成功" << std::endl;
			system("pause");
			system("cls");
			return;
			break;
		default:
			break;
		}
	}
}

void Student::showMenu()
{
	std::cout << "欢迎学生代表：" << m_name << "登录！" << std::endl;
	std::cout << "                 ----------------------------------" << std::endl;
	std::cout << "                |                                  |" << std::endl;
	std::cout << "                |          1.申请预约              |" << std::endl;
	std::cout << "                |                                  |" << std::endl;
	std::cout << "                |          2.查看我的预约          |" << std::endl;
	std::cout << "                |                                  |" << std::endl;
	std::cout << "                |          3.查看所有预约          |" << std::endl;
	std::cout << "                |                                  |" << std::endl;
	std::cout << "                |          4.取消预约              |" << std::endl;
	std::cout << "                |                                  |" << std::endl;
	std::cout << "                |          0.注销登录              |" << std::endl;
	std::cout << "                |                                  |" << std::endl;
	std::cout << "                 ----------------------------------" << std::endl;
	std::cout << "请选择您的操作：" << std::endl;
}
