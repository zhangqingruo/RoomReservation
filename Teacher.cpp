#include "Teacher.h"
#include "orderFile.h"

void Teacher::operMenu()
{
	int select;
	while (true)
	{
		showMenu();
		std::cin >> select;
		switch (select)
		{
		case 1:  //查看所有预约
			m_orders->checkOrder();
			break;
		case 2:  //审核预约
			m_orders->agreeOrder();
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

void Teacher::showMenu()
{
	std::cout << "欢迎教师：" << m_name << "登录！" << std::endl;
	std::cout << "                 ----------------------------------" << std::endl;
	std::cout << "                |                                  |" << std::endl;
	std::cout << "                |          1.查看所有预约          |" << std::endl;
	std::cout << "                |                                  |" << std::endl;
	std::cout << "                |          2.审核预约              |" << std::endl;
	std::cout << "                |                                  |" << std::endl;
	std::cout << "                |          0.注销登录              |" << std::endl;
	std::cout << "                |                                  |" << std::endl;
	std::cout << "                 ----------------------------------" << std::endl;
	std::cout << "请选择您的操作：" << std::endl;
}
