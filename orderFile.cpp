#include "orderFile.h"
#include <iostream>
#include <fstream>


orderFile::orderFile(const char* filename) : m_orderfile(filename)
{
	std::ifstream ifs(m_orderfile, std::ios::in);
	if (!ifs.is_open() || ifs.eof()) {
		ifs.close();
		std::ofstream ofs(m_orderfile, std::ios::out | std::ios::trunc);
		ofs.close();
		return;
	}
	std::string date, interval, stuId, stuName, roomId, status;
	int pos;
	while (ifs >> date >> interval >> stuId >> stuName >> roomId >> status)
	{
		std::map<std::string, std::string> orderRecord;
		pos = date.find(':') + 1;
		orderRecord.insert(std::make_pair("date", date.substr(pos)));
		pos = interval.find(':') + 1;
		orderRecord.insert(std::make_pair("interval", interval.substr(pos)));
		pos = stuId.find(':') + 1;
		orderRecord.insert(std::make_pair("stuId", stuId.substr(pos)));
		pos = stuName.find(':') + 1;
		orderRecord.insert(std::make_pair("stuName", stuName.substr(pos)));
		pos = roomId.find(':') + 1;
		orderRecord.insert(std::make_pair("roomId", roomId.substr(pos)));
		pos = status.find(':') + 1;
		orderRecord.insert(std::make_pair("status", status.substr(pos)));
		m_orderRecords.emplace_back(orderRecord);
	}
	ifs.close();
}

void orderFile::applyOrder(const Student* stu)
{
	std::map<std::string, std::string> orderRecord;
	orderRecord.insert(std::make_pair("stuId", std::to_string(stu->getId())));
	orderRecord.insert(std::make_pair("stuName", stu->getName()));
	orderRecord.insert(std::make_pair("status", "1"));
	std::string date, interval, roomId;
	std::cout << "��������ʱ��Ϊ��һ������!" << std::endl;
	std::cout << "����������ԤԼ��ʱ�䣺" << std::endl;
	std::cout << "1����һ" << std::endl;
	std::cout << "2���ܶ�" << std::endl;
	std::cout << "3������" << std::endl;
	std::cout << "4������" << std::endl;
	std::cout << "5������" << std::endl;
	std::cin >> date;
	orderRecord.insert(std::make_pair("date", date));
	std::cout << "����������ԤԼʱ��Σ�" << std::endl;
	std::cout << "1������" << std::endl;
	std::cout << "2������" << std::endl;
	std::cin >> interval;
	orderRecord.insert(std::make_pair("interval", interval));
	std::cout << "��ѡ�������" << std::endl;
	m_room.printRoom();
	std::cin >> roomId;
	orderRecord.insert(std::make_pair("roomId", roomId));
	m_orderRecords.emplace_back(orderRecord);
	Save();
	std::cout << "ԤԼ�ɹ��������" << std::endl;
	system("pause");
	system("cls");
}

void orderFile::checkMyOrder(const Student* stu) const
{
	int num = 0;
	if (m_orderRecords.empty()) {
		std::cout << "��¼Ϊ�գ�" << std::endl;
		system("pause");
		system("cls");
		return;
	}
	for (size_t i = 0; i < m_orderRecords.size(); ++i) {
		if (std::to_string(stu->getId()) == m_orderRecords[i].at("stuId")) {
			++num;
			std::cout << num << "�� ԤԼ���ڣ�" << m_date.at(m_orderRecords[i].at("date"))
				<< "\tʱ��Σ�" << m_interval.at(m_orderRecords[i].at("interval"))
				<< "\t������ţ�" << m_orderRecords[i].at("roomId")
				<< "\t״̬��" << m_status.at(m_orderRecords[i].at("status"))
				<< std::endl;
		}
	}
	if (num == 0) {
		std::cout << "��¼Ϊ�գ�" << std::endl;
	}
	system("pause");
	system("cls");
}

void orderFile::checkOrder() const
{
	if (m_orderRecords.empty()) {
		std::cout << "��¼Ϊ�գ�" << std::endl;
		return;
	}
	for (size_t i = 0; i < m_orderRecords.size(); ++i) {
		std::cout << i + 1 << "�� ԤԼ���ڣ�" << m_date.at(m_orderRecords[i].at("date"))
			<< "\tʱ��Σ�" << m_interval.at(m_orderRecords[i].at("interval"))
			<< "\tѧ�ţ�" << m_orderRecords[i].at("stuId")
			<< "\t������" << m_orderRecords[i].at("stuName")
			<< "\t������ţ�" << m_orderRecords[i].at("roomId")
			<< "\t״̬��" << m_status.at(m_orderRecords[i].at("status"))
			<< std::endl;
	}
	system("pause");
	system("cls");
}

void orderFile::cancelOrder(const Student* stu)
{
	std::vector<size_t> indexs;
	if (m_orderRecords.empty()) {
		std::cout << "��¼Ϊ�գ�" << std::endl;
		system("pause");
		system("cls");
		return;
	}
	std::cout << "����л�ԤԼ�ɹ��ļ�¼����ȡ����������ȡ���ļ�¼" << std::endl;
	for (size_t i = 0; i < m_orderRecords.size(); ++i) {
		if (std::to_string(stu->getId()) == m_orderRecords[i].at("stuId")
			&& (m_orderRecords[i].at("status") == "1"
				|| m_orderRecords[i].at("status") == "2"))
		{
			indexs.emplace_back(i);
			std::cout << indexs.size() << "�� ԤԼ���ڣ�" << m_date.at(m_orderRecords[i].at("date"))
				<< "\tʱ��Σ�" << m_interval.at(m_orderRecords[i].at("interval"))
				<< "\t������ţ�" << m_orderRecords[i].at("roomId")
				<< "\t״̬��" << m_status.at(m_orderRecords[i].at("status"))
				<< std::endl;
		}
	}
	if (indexs.empty()) {
		std::cout << "��¼Ϊ�գ�" << std::endl;
	}
	std::cout << "������ȡ���ļ�¼��0������" << std::endl;
	int select;
	std::cin >> select;
	if (select == 0) {
		system("pause");
		system("cls");
		return;
	}
	else if (select > 0) {
		m_orderRecords[indexs[select - 1]].at("status") = "0";
		Save();
		std::cout << "��ȡ��ԤԼ" << std::endl;
	}
	system("pause");
	system("cls");
}

void orderFile::agreeOrder()
{
	std::vector<size_t> indexs;
	std::cout << "����˵�ԤԼ��¼���£�" << std::endl;
	if (m_orderRecords.empty()) {
		std::cout << "��¼Ϊ�գ�" << std::endl;
		system("pause");
		system("cls");
		return;
	}
	for (size_t i = 0; i < m_orderRecords.size(); ++i) {
		if (m_orderRecords[i].at("status") == "1")
		{
			indexs.emplace_back(i);
			std::cout << indexs.size() << "�� ԤԼ���ڣ�" << m_date.at(m_orderRecords[i].at("date"))
				<< "\tʱ��Σ�" << m_interval.at(m_orderRecords[i].at("interval"))
				<< "\tѧ��ѧ�ţ�" << m_orderRecords[i].at("stuId")
				<< "\tѧ��������" << m_orderRecords[i].at("stuName")
				<< "\t������ţ�" << m_orderRecords[i].at("roomId")
				<< "\t״̬��" << m_status.at(m_orderRecords[i].at("status"))
				<< std::endl;
		}
	}
	if (indexs.empty()) {
		std::cout << "��¼Ϊ�գ�" << std::endl;
	}
	std::cout << "������ȡ���ļ�¼��0������" << std::endl;
	int select1;
	std::cin >> select1;
	if (select1 == 0) {
		system("pause");
		system("cls");
		return;
	}
	int select2;
	std::cout << "��������˽��" << std::endl;
	std::cout << "1��ͨ��" << std::endl;
	std::cout << "2����ͨ��" << std::endl;
	std::cin >> select2;
	if (select2 == 1) {
		m_orderRecords[indexs[select1 - 1]].at("status") = "2";
	}
	else if (select2 == 2) {
		m_orderRecords[indexs[select1 - 1]].at("status") = "-1";
	}
	Save();
	std::cout << "������" << std::endl;
	system("pause");
	system("cls");
}

void orderFile::clearOrder()
{
	m_orderRecords.clear();
	std::ofstream ofs(m_orderfile, std::ios::out | std::ios::trunc);
	ofs.close();
	std::cout << "����գ�" << std::endl;
	system("pause");
	system("cls");
}

void orderFile::Save()
{
	std::ofstream ofs(m_orderfile, std::ios::out | std::ios::trunc);
	for (auto it = m_orderRecords.begin(); it != m_orderRecords.end(); ++it) {
		ofs << "date:" << it->at("date")
			<< " interval:" << it->at("interval")
			<< " stuId:" << it->at("stuId")
			<< " stuName:" << it->at("stuName")
			<< " roomId:" << it->at("roomId")
			<< " status:" << it->at("status")
			<< std::endl;
	}
	ofs.close();
}
