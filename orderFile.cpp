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
	std::cout << "机房开放时间为周一至周五!" << std::endl;
	std::cout << "请输入申请预约的时间：" << std::endl;
	std::cout << "1、周一" << std::endl;
	std::cout << "2、周二" << std::endl;
	std::cout << "3、周三" << std::endl;
	std::cout << "4、周四" << std::endl;
	std::cout << "5、周五" << std::endl;
	std::cin >> date;
	orderRecord.insert(std::make_pair("date", date));
	std::cout << "请输入申请预约时间段：" << std::endl;
	std::cout << "1、上午" << std::endl;
	std::cout << "2、下午" << std::endl;
	std::cin >> interval;
	orderRecord.insert(std::make_pair("interval", interval));
	std::cout << "请选择机房：" << std::endl;
	m_room.printRoom();
	std::cin >> roomId;
	orderRecord.insert(std::make_pair("roomId", roomId));
	m_orderRecords.emplace_back(orderRecord);
	Save();
	std::cout << "预约成功！审核中" << std::endl;
	system("pause");
	system("cls");
}

void orderFile::checkMyOrder(const Student* stu) const
{
	int num = 0;
	if (m_orderRecords.empty()) {
		std::cout << "记录为空！" << std::endl;
		system("pause");
		system("cls");
		return;
	}
	for (size_t i = 0; i < m_orderRecords.size(); ++i) {
		if (std::to_string(stu->getId()) == m_orderRecords[i].at("stuId")) {
			++num;
			std::cout << num << "、 预约日期：" << m_date.at(m_orderRecords[i].at("date"))
				<< "\t时间段：" << m_interval.at(m_orderRecords[i].at("interval"))
				<< "\t机房编号：" << m_orderRecords[i].at("roomId")
				<< "\t状态：" << m_status.at(m_orderRecords[i].at("status"))
				<< std::endl;
		}
	}
	if (num == 0) {
		std::cout << "记录为空！" << std::endl;
	}
	system("pause");
	system("cls");
}

void orderFile::checkOrder() const
{
	if (m_orderRecords.empty()) {
		std::cout << "记录为空！" << std::endl;
		return;
	}
	for (size_t i = 0; i < m_orderRecords.size(); ++i) {
		std::cout << i + 1 << "、 预约日期：" << m_date.at(m_orderRecords[i].at("date"))
			<< "\t时间段：" << m_interval.at(m_orderRecords[i].at("interval"))
			<< "\t学号：" << m_orderRecords[i].at("stuId")
			<< "\t姓名：" << m_orderRecords[i].at("stuName")
			<< "\t机房编号：" << m_orderRecords[i].at("roomId")
			<< "\t状态：" << m_status.at(m_orderRecords[i].at("status"))
			<< std::endl;
	}
	system("pause");
	system("cls");
}

void orderFile::cancelOrder(const Student* stu)
{
	std::vector<size_t> indexs;
	if (m_orderRecords.empty()) {
		std::cout << "记录为空！" << std::endl;
		system("pause");
		system("cls");
		return;
	}
	std::cout << "审核中或预约成功的记录可以取消，请输入取消的记录" << std::endl;
	for (size_t i = 0; i < m_orderRecords.size(); ++i) {
		if (std::to_string(stu->getId()) == m_orderRecords[i].at("stuId")
			&& (m_orderRecords[i].at("status") == "1"
				|| m_orderRecords[i].at("status") == "2"))
		{
			indexs.emplace_back(i);
			std::cout << indexs.size() << "、 预约日期：" << m_date.at(m_orderRecords[i].at("date"))
				<< "\t时间段：" << m_interval.at(m_orderRecords[i].at("interval"))
				<< "\t机房编号：" << m_orderRecords[i].at("roomId")
				<< "\t状态：" << m_status.at(m_orderRecords[i].at("status"))
				<< std::endl;
		}
	}
	if (indexs.empty()) {
		std::cout << "记录为空！" << std::endl;
	}
	std::cout << "请输入取消的记录，0代表返回" << std::endl;
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
		std::cout << "已取消预约" << std::endl;
	}
	system("pause");
	system("cls");
}

void orderFile::agreeOrder()
{
	std::vector<size_t> indexs;
	std::cout << "待审核的预约记录如下：" << std::endl;
	if (m_orderRecords.empty()) {
		std::cout << "记录为空！" << std::endl;
		system("pause");
		system("cls");
		return;
	}
	for (size_t i = 0; i < m_orderRecords.size(); ++i) {
		if (m_orderRecords[i].at("status") == "1")
		{
			indexs.emplace_back(i);
			std::cout << indexs.size() << "、 预约日期：" << m_date.at(m_orderRecords[i].at("date"))
				<< "\t时间段：" << m_interval.at(m_orderRecords[i].at("interval"))
				<< "\t学生学号：" << m_orderRecords[i].at("stuId")
				<< "\t学生姓名：" << m_orderRecords[i].at("stuName")
				<< "\t机房编号：" << m_orderRecords[i].at("roomId")
				<< "\t状态：" << m_status.at(m_orderRecords[i].at("status"))
				<< std::endl;
		}
	}
	if (indexs.empty()) {
		std::cout << "记录为空！" << std::endl;
	}
	std::cout << "请输入取消的记录，0代表返回" << std::endl;
	int select1;
	std::cin >> select1;
	if (select1 == 0) {
		system("pause");
		system("cls");
		return;
	}
	int select2;
	std::cout << "请输入审核结果" << std::endl;
	std::cout << "1、通过" << std::endl;
	std::cout << "2、不通过" << std::endl;
	std::cin >> select2;
	if (select2 == 1) {
		m_orderRecords[indexs[select1 - 1]].at("status") = "2";
	}
	else if (select2 == 2) {
		m_orderRecords[indexs[select1 - 1]].at("status") = "-1";
	}
	Save();
	std::cout << "审核完毕" << std::endl;
	system("pause");
	system("cls");
}

void orderFile::clearOrder()
{
	m_orderRecords.clear();
	std::ofstream ofs(m_orderfile, std::ios::out | std::ios::trunc);
	ofs.close();
	std::cout << "已清空！" << std::endl;
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
