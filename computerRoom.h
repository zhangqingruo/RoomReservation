#pragma once
#include <map>
class computerRoom
{
public:
	computerRoom(const char* filename);
	~computerRoom(){}
	void printRoom() const;
	std::map<int, int> m_rooms;  //<roomId, maxSize>
};

