#include "ReservationManager.h"
#include <iostream>
#include <fstream>
#include "globalFile.h"
void ReservationManager::IdentitySelect()
{
	std::cout << "======================  欢迎来到传智播客机房预约系统  =====================" << std::endl;
	std::cout << "请输入您的身份：" << std::endl;
	std::cout << "                 -------------------------------" << std::endl;
	std::cout << "                |                               |" << std::endl;
	std::cout << "                |          1.学生代表           |" << std::endl;
	std::cout << "                |                               |" << std::endl;
	std::cout << "                |          2.老    师           |" << std::endl;
	std::cout << "                |                               |" << std::endl;
	std::cout << "                |          3.管 理 员           |" << std::endl;
	std::cout << "                |                               |" << std::endl;
	std::cout << "                |          0.退    出           |" << std::endl;
	std::cout << "                |                               |" << std::endl;
	std::cout << "                 -------------------------------" << std::endl;
	std::cout << "输入您的选择:";
}

void ReservationManager::LogInStu()
{
	std::ifstream ifs(STUDENT_FILE, std::ios::in);
	if (!ifs.is_open() || ifs.eof())
	{
		ifs.close();
		std::cout << "文件不存在或为空！" << std::endl;
		system("pause");
		system("cls");
		return;
	}
	int id, t_id;
	std::string name, pwd, t_name, t_pwd;
	std::cout << "请输入你的学号：" << std::endl;
	std::cin >> id;
	std::cout << "请输入用户名：" << std::endl;
	std::cin >> name;
	std::cout << "请输入密码：" << std::endl;
	std::cin >> pwd;
	while (ifs >> t_id >> t_name >> t_pwd)
	{
		if (id == t_id && name == t_name && pwd == t_pwd)
		{
			std::cout << "学生验证登录成功！" << std::endl;
			system("pause");
			system("cls");
			person = new Student(id, name, pwd, m_orders);
			person->operMenu();
			if (person != NULL) {
				delete person;
				person = NULL;
			}
			return;
		}
	}
	std::cout << "验证登录失败！" << std::endl;
	system("pause");
	system("cls");
}

void ReservationManager::LogInTea()
{
	std::ifstream ifs(TEACHER_FILE, std::ios::in);
	if (!ifs.is_open() || ifs.eof())
	{
		ifs.close();
		std::cout << "文件不存在或为空！" << std::endl;
		system("pause");
		system("cls");
		return;
	}
	int id, t_id;
	std::string name, pwd, t_name, t_pwd;
	std::cout << "请输入你的职工号：" << std::endl;
	std::cin >> id;
	std::cout << "请输入用户名：" << std::endl;
	std::cin >> name;
	std::cout << "请输入密码：" << std::endl;
	std::cin >> pwd;
	while (ifs >> t_id >> t_name >> t_pwd)
	{
		if (id == t_id && name == t_name && pwd == t_pwd)
		{
			std::cout << "教师验证登录成功！" << std::endl;
			system("pause");
			system("cls");
			person = new Teacher(id, name, pwd, m_orders);
			person->operMenu();
			if (person != NULL) {
				delete person;
				person = NULL;
			}
			return;
		}
	}
	std::cout << "验证登录失败！" << std::endl;
	system("pause");
	system("cls");
}

void ReservationManager::LogInMan()
{
	std::ifstream ifs(ADMIN_FILE, std::ios::in);
	if (!ifs.is_open() || ifs.eof())
	{
		ifs.close();
		std::cout << "文件不存在或为空！" << std::endl;
		system("pause");
		system("cls");
		return;
	}
	std::string name, pwd, t_name, t_pwd;
	std::cout << "请输入用户名：" << std::endl;
	std::cin >> name;
	std::cout << "请输入密码：" << std::endl;
	std::cin >> pwd;
	while (ifs>>t_name>>t_pwd)
	{
		if (name == t_name && pwd == t_pwd)
		{
			std::cout << "管理员验证登录成功!" << std::endl;
			system("pause");
			system("cls");
			person = new Manager(name, pwd, m_orders);
			person->operMenu();
			if (person != NULL) {
				delete person;
				person = NULL;
			}
			return;
		}
	}
	std::cout << "验证登录失败！" << std::endl;
	system("pause");
	system("cls");
}

void ReservationManager::exitSystem()
{
	std::cout << "欢迎下次使用" << std::endl;
	system("pause");
	exit(0);
}
