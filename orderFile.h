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
	//�洢�������ת��
	const std::map<std::string, std::string> m_date{
		std::make_pair("1","��һ"),
		std::make_pair("2","�ܶ�"),
		std::make_pair("3","����"),
		std::make_pair("4","����"),
		std::make_pair("5","����")
	};
	const std::map<std::string, std::string> m_interval{ 
		std::make_pair("1","����"),
		std::make_pair("2","����") 
	};
	const std::map<std::string, std::string> m_status{
		std::make_pair("0","ԤԼ��ȡ��"),
		std::make_pair("1","�����"),
		std::make_pair("2","ԤԼ�ɹ�"),
		std::make_pair("-1","ԤԼʧ��")
	};
};

