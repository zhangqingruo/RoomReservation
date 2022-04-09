#include "Manager.h"
#include "orderFile.h"
#include "globalFile.h"
#include <algorithm>

void Manager::operMenu()
{
	int select;
	while (true)
	{
		showMenu();
		std::cin >> select;
		switch (select)
		{
		case 1:  //添加账号
			addAccount();
			break;
		case 2:  //查看账号
			checkAccount();
			break;
		case 3:  //查看机房
			checkComputerRoom();
			break;
		case 4:  //清空预约
			m_orders->clearOrder();
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

void Manager::showMenu()
{
	std::cout << "欢迎管理员：" << m_name << "登录！" << std::endl;
	std::cout << "                 ----------------------------------" << std::endl;
	std::cout << "                |                                  |" << std::endl;
	std::cout << "                |          1.添加账号              |" << std::endl;
	std::cout << "                |                                  |" << std::endl;
	std::cout << "                |          2.查看账号              |" << std::endl;
	std::cout << "                |                                  |" << std::endl;
	std::cout << "                |          3.查看机房              |" << std::endl;
	std::cout << "                |                                  |" << std::endl;
	std::cout << "                |          4.清空预约              |" << std::endl;
	std::cout << "                |                                  |" << std::endl;
	std::cout << "                |          0.注销登录              |" << std::endl;
	std::cout << "                |                                  |" << std::endl;
	std::cout << "                 ----------------------------------" << std::endl;
	std::cout << "请选择您的操作：" << std::endl;
}

void Manager::addAccount()
{
	int select;
	std::cout << "请输入添加账号类型" << std::endl;
	std::cout << "1、添加学生" << std::endl;
	std::cout << "2、添加老师" << std::endl;
	std::cin >> select;
	if (select == 1) {
		std::ofstream ofs(STUDENT_FILE, std::ios::out | std::ios::app);
		readId(STUDENT_FILE);
		int id;
		std::string name, pwd;
		std::cout << "请输入学号：" << std::endl;
		std::cin >> id;
		while (find(presentId.begin(), presentId.end(), id) == presentId.end())
		{
			std::cout << "学号重复，请重新输入" << std::endl;
			std::cin >> id;
		}
		std::cout << "请输入姓名：" << std::endl;
		std::cin >> name;
		std::cout << "请输入密码：" << std::endl;
		std::cin >> pwd;
		ofs << id << " " << name << " " << pwd << std::endl;
		std::cout << "添加成功" << std::endl;
		ofs.close();
		presentId.clear();
		system("pause");
		system("cls");
	}
	else if (select == 2) {
		std::ofstream ofs(TEACHER_FILE, std::ios::out | std::ios::app);
		readId(TEACHER_FILE);
		int id;
		std::string name, pwd;
		std::cout << "请输入职工编号：" << std::endl;
		std::cin >> id;
		while (find(presentId.begin(), presentId.end(), id) == presentId.end())
		{
			std::cout << "职工编号重复，请重新输入" << std::endl;
			std::cin >> id;
		}
		std::cout << "请输入姓名：" << std::endl;
		std::cin >> name;
		std::cout << "请输入密码：" << std::endl;
		std::cin >> pwd;
		ofs << id << " " << name << " " << pwd << std::endl;
		std::cout << "添加成功" << std::endl;
		ofs.close();
		presentId.clear();
		system("pause");
		system("cls");
	}
	else {
		std::cout << "输入错误！" << std::endl;
		system("pause");
		system("cls");
	}
}

void Manager::checkAccount()
{
	int select;
	std::cout << "请选择查看内容：" << std::endl;
	std::cout << "1、查看所有学生" << std::endl;
	std::cout << "2、查看所有老师" << std::endl;
	std::cin >> select;
	if (select == 1) {
		std::ifstream ifs(STUDENT_FILE, std::ios::in);
		std::cout << "所有学生信息如下：" << std::endl;
		int id;
		std::string name, pwd;
		while (ifs >> id >> name >> pwd)
		{
			std::cout << "学号：" << id << "\t姓名：" << name << "\t密码" << pwd << std::endl;
		}
		ifs.close();
		system("pause");
		system("cls");
	}
	else if (select == 2) {
		std::ifstream ifs(TEACHER_FILE, std::ios::in);
		std::cout << "所有教师信息如下：" << std::endl;
		int id;
		std::string name, pwd;
		while (ifs >> id >> name >> pwd)
		{
			std::cout << "职工号：" << id << "\t姓名：" << name << "\t密码" << pwd << std::endl;
		}
		ifs.close();
		system("pause");
		system("cls");
	}
	else {
		std::cout << "输入错误！" << std::endl;
		system("pause");
		system("cls");
	}

}

void Manager::checkComputerRoom()
{
	m_orders->m_room.printRoom();
	system("pause");
	system("cls");
}

void Manager::readId(const char* filename)
{
	std::ifstream ifs(filename, std::ios::in);
	if (!ifs.is_open() || ifs.eof())
	{
		ifs.close();
		return;
	}
	int id;
	std::string name, pwd;
	while (ifs >> id >> name >> pwd) {
		presentId.emplace_back(id);
	}
	ifs.close();
}
