#pragma once
#include "Identity.h"
#include <vector>

class Manager : public Identity
{
public:
	using Identity::Identity;
	void operMenu();
	void showMenu();
	void addAccount();
	void checkAccount();
	void checkComputerRoom();
private:
	void readId(const char* filename);
	std::vector<int> presentId;
};

