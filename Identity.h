#pragma once
#include <string>
#include <iostream>
#include <fstream>
class orderFile;
class Identity
{
public:
	Identity() = default;
	Identity(std::string name,std::string pwd,orderFile* orders):
		m_name(name),m_pwd(pwd),m_orders(orders){}
	virtual void operMenu() = 0;  //操作界面
	virtual void showMenu() = 0;  //打印菜单
	void setName(std::string name) { m_name = name; }
	void setPwd(std::string pwd) { m_pwd = pwd; }
	std::string getName() const { return m_name; }
	std::string getPwd() const { return m_pwd; }
protected:
	std::string m_name;
	std::string m_pwd;
	orderFile* m_orders;
};
