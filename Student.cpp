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
		case 1:  //����ԤԼ
			m_orders->applyOrder(this);
			break;
		case 2:  //�鿴�ҵ�ԤԼ
			m_orders->checkMyOrder(this);
			break;
		case 3:  //�鿴����ԤԼ
			m_orders->checkOrder();
			break;
		case 4:  //ȡ��ԤԼ
			m_orders->cancelOrder(this);
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

void Student::showMenu()
{
	std::cout << "��ӭѧ������" << m_name << "��¼��" << std::endl;
	std::cout << "                 ----------------------------------" << std::endl;
	std::cout << "                |                                  |" << std::endl;
	std::cout << "                |          1.����ԤԼ              |" << std::endl;
	std::cout << "                |                                  |" << std::endl;
	std::cout << "                |          2.�鿴�ҵ�ԤԼ          |" << std::endl;
	std::cout << "                |                                  |" << std::endl;
	std::cout << "                |          3.�鿴����ԤԼ          |" << std::endl;
	std::cout << "                |                                  |" << std::endl;
	std::cout << "                |          4.ȡ��ԤԼ              |" << std::endl;
	std::cout << "                |                                  |" << std::endl;
	std::cout << "                |          0.ע����¼              |" << std::endl;
	std::cout << "                |                                  |" << std::endl;
	std::cout << "                 ----------------------------------" << std::endl;
	std::cout << "��ѡ�����Ĳ�����" << std::endl;
}
