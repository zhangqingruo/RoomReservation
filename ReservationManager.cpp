#include "ReservationManager.h"
#include <iostream>
#include <fstream>
#include "globalFile.h"
void ReservationManager::IdentitySelect()
{
	std::cout << "======================  ��ӭ�������ǲ��ͻ���ԤԼϵͳ  =====================" << std::endl;
	std::cout << "������������ݣ�" << std::endl;
	std::cout << "                 -------------------------------" << std::endl;
	std::cout << "                |                               |" << std::endl;
	std::cout << "                |          1.ѧ������           |" << std::endl;
	std::cout << "                |                               |" << std::endl;
	std::cout << "                |          2.��    ʦ           |" << std::endl;
	std::cout << "                |                               |" << std::endl;
	std::cout << "                |          3.�� �� Ա           |" << std::endl;
	std::cout << "                |                               |" << std::endl;
	std::cout << "                |          0.��    ��           |" << std::endl;
	std::cout << "                |                               |" << std::endl;
	std::cout << "                 -------------------------------" << std::endl;
	std::cout << "��������ѡ��:";
}

void ReservationManager::LogInStu()
{
	std::ifstream ifs(STUDENT_FILE, std::ios::in);
	if (!ifs.is_open() || ifs.eof())
	{
		ifs.close();
		std::cout << "�ļ������ڻ�Ϊ�գ�" << std::endl;
		system("pause");
		system("cls");
		return;
	}
	int id, t_id;
	std::string name, pwd, t_name, t_pwd;
	std::cout << "���������ѧ�ţ�" << std::endl;
	std::cin >> id;
	std::cout << "�������û�����" << std::endl;
	std::cin >> name;
	std::cout << "���������룺" << std::endl;
	std::cin >> pwd;
	while (ifs >> t_id >> t_name >> t_pwd)
	{
		if (id == t_id && name == t_name && pwd == t_pwd)
		{
			std::cout << "ѧ����֤��¼�ɹ���" << std::endl;
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
	std::cout << "��֤��¼ʧ�ܣ�" << std::endl;
	system("pause");
	system("cls");
}

void ReservationManager::LogInTea()
{
	std::ifstream ifs(TEACHER_FILE, std::ios::in);
	if (!ifs.is_open() || ifs.eof())
	{
		ifs.close();
		std::cout << "�ļ������ڻ�Ϊ�գ�" << std::endl;
		system("pause");
		system("cls");
		return;
	}
	int id, t_id;
	std::string name, pwd, t_name, t_pwd;
	std::cout << "���������ְ���ţ�" << std::endl;
	std::cin >> id;
	std::cout << "�������û�����" << std::endl;
	std::cin >> name;
	std::cout << "���������룺" << std::endl;
	std::cin >> pwd;
	while (ifs >> t_id >> t_name >> t_pwd)
	{
		if (id == t_id && name == t_name && pwd == t_pwd)
		{
			std::cout << "��ʦ��֤��¼�ɹ���" << std::endl;
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
	std::cout << "��֤��¼ʧ�ܣ�" << std::endl;
	system("pause");
	system("cls");
}

void ReservationManager::LogInMan()
{
	std::ifstream ifs(ADMIN_FILE, std::ios::in);
	if (!ifs.is_open() || ifs.eof())
	{
		ifs.close();
		std::cout << "�ļ������ڻ�Ϊ�գ�" << std::endl;
		system("pause");
		system("cls");
		return;
	}
	std::string name, pwd, t_name, t_pwd;
	std::cout << "�������û�����" << std::endl;
	std::cin >> name;
	std::cout << "���������룺" << std::endl;
	std::cin >> pwd;
	while (ifs>>t_name>>t_pwd)
	{
		if (name == t_name && pwd == t_pwd)
		{
			std::cout << "����Ա��֤��¼�ɹ�!" << std::endl;
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
	std::cout << "��֤��¼ʧ�ܣ�" << std::endl;
	system("pause");
	system("cls");
}

void ReservationManager::exitSystem()
{
	std::cout << "��ӭ�´�ʹ��" << std::endl;
	system("pause");
	exit(0);
}
