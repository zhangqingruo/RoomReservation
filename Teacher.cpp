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
		case 1:  //�鿴����ԤԼ
			m_orders->checkOrder();
			break;
		case 2:  //���ԤԼ
			m_orders->agreeOrder();
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

void Teacher::showMenu()
{
	std::cout << "��ӭ��ʦ��" << m_name << "��¼��" << std::endl;
	std::cout << "                 ----------------------------------" << std::endl;
	std::cout << "                |                                  |" << std::endl;
	std::cout << "                |          1.�鿴����ԤԼ          |" << std::endl;
	std::cout << "                |                                  |" << std::endl;
	std::cout << "                |          2.���ԤԼ              |" << std::endl;
	std::cout << "                |                                  |" << std::endl;
	std::cout << "                |          0.ע����¼              |" << std::endl;
	std::cout << "                |                                  |" << std::endl;
	std::cout << "                 ----------------------------------" << std::endl;
	std::cout << "��ѡ�����Ĳ�����" << std::endl;
}
