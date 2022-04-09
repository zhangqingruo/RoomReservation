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
		case 1:  //����˺�
			addAccount();
			break;
		case 2:  //�鿴�˺�
			checkAccount();
			break;
		case 3:  //�鿴����
			checkComputerRoom();
			break;
		case 4:  //���ԤԼ
			m_orders->clearOrder();
			break;
		case 0:  //ע����¼
			std::cout << "ע���ɹ�" << std::endl;
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
	std::cout << "��ӭ����Ա��" << m_name << "��¼��" << std::endl;
	std::cout << "                 ----------------------------------" << std::endl;
	std::cout << "                |                                  |" << std::endl;
	std::cout << "                |          1.����˺�              |" << std::endl;
	std::cout << "                |                                  |" << std::endl;
	std::cout << "                |          2.�鿴�˺�              |" << std::endl;
	std::cout << "                |                                  |" << std::endl;
	std::cout << "                |          3.�鿴����              |" << std::endl;
	std::cout << "                |                                  |" << std::endl;
	std::cout << "                |          4.���ԤԼ              |" << std::endl;
	std::cout << "                |                                  |" << std::endl;
	std::cout << "                |          0.ע����¼              |" << std::endl;
	std::cout << "                |                                  |" << std::endl;
	std::cout << "                 ----------------------------------" << std::endl;
	std::cout << "��ѡ�����Ĳ�����" << std::endl;
}

void Manager::addAccount()
{
	int select;
	std::cout << "����������˺�����" << std::endl;
	std::cout << "1�����ѧ��" << std::endl;
	std::cout << "2�������ʦ" << std::endl;
	std::cin >> select;
	if (select == 1) {
		std::ofstream ofs(STUDENT_FILE, std::ios::out | std::ios::app);
		readId(STUDENT_FILE);
		int id;
		std::string name, pwd;
		std::cout << "������ѧ�ţ�" << std::endl;
		std::cin >> id;
		while (find(presentId.begin(), presentId.end(), id) == presentId.end())
		{
			std::cout << "ѧ���ظ�������������" << std::endl;
			std::cin >> id;
		}
		std::cout << "������������" << std::endl;
		std::cin >> name;
		std::cout << "���������룺" << std::endl;
		std::cin >> pwd;
		ofs << id << " " << name << " " << pwd << std::endl;
		std::cout << "��ӳɹ�" << std::endl;
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
		std::cout << "������ְ����ţ�" << std::endl;
		std::cin >> id;
		while (find(presentId.begin(), presentId.end(), id) == presentId.end())
		{
			std::cout << "ְ������ظ�������������" << std::endl;
			std::cin >> id;
		}
		std::cout << "������������" << std::endl;
		std::cin >> name;
		std::cout << "���������룺" << std::endl;
		std::cin >> pwd;
		ofs << id << " " << name << " " << pwd << std::endl;
		std::cout << "��ӳɹ�" << std::endl;
		ofs.close();
		presentId.clear();
		system("pause");
		system("cls");
	}
	else {
		std::cout << "�������" << std::endl;
		system("pause");
		system("cls");
	}
}

void Manager::checkAccount()
{
	int select;
	std::cout << "��ѡ��鿴���ݣ�" << std::endl;
	std::cout << "1���鿴����ѧ��" << std::endl;
	std::cout << "2���鿴������ʦ" << std::endl;
	std::cin >> select;
	if (select == 1) {
		std::ifstream ifs(STUDENT_FILE, std::ios::in);
		std::cout << "����ѧ����Ϣ���£�" << std::endl;
		int id;
		std::string name, pwd;
		while (ifs >> id >> name >> pwd)
		{
			std::cout << "ѧ�ţ�" << id << "\t������" << name << "\t����" << pwd << std::endl;
		}
		ifs.close();
		system("pause");
		system("cls");
	}
	else if (select == 2) {
		std::ifstream ifs(TEACHER_FILE, std::ios::in);
		std::cout << "���н�ʦ��Ϣ���£�" << std::endl;
		int id;
		std::string name, pwd;
		while (ifs >> id >> name >> pwd)
		{
			std::cout << "ְ���ţ�" << id << "\t������" << name << "\t����" << pwd << std::endl;
		}
		ifs.close();
		system("pause");
		system("cls");
	}
	else {
		std::cout << "�������" << std::endl;
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
