#pragma once
#include "computerRoom.h"
#include "Student.h"
#include "Manager.h"
#include "globalFile.h"
#include <map>
#include <string>
#include <vector>

class Manager;
class orderFile
{
	friend void Manager::checkComputerRoom();
public:
	orderFile(const char* filename);
	~orderFile(){}
	void applyOrder(const Student* stu);
	void checkMyOrder(const Student* stu) const;
	void checkOrder() const;
	void cancelOrder(const Student* stu);
	void agreeOrder();
	void clearOrder();
	void Save();

private:
	const char* m_orderfile;
	const computerRoom m_room{ COMPUTER_FILE };
	std::vector<std::map<std::string, std::string>> m_orderRecords;  //key:date,interval,stuId,stuName,roomId,status
	//存储与输出的转换
	const std::map<std::string, std::string> m_date{
		std::make_pair("1","周一"),
		std::make_pair("2","周二"),
		std::make_pair("3","周三"),
		std::make_pair("4","周四"),
		std::make_pair("5","周五")
	};
	const std::map<std::string, std::string> m_interval{ 
		std::make_pair("1","上午"),
		std::make_pair("2","下午") 
	};
	const std::map<std::string, std::string> m_status{
		std::make_pair("0","预约已取消"),
		std::make_pair("1","审核中"),
		std::make_pair("2","预约成功"),
		std::make_pair("-1","预约失败")
	};
};

