#include "computerRoom.h"
#include <iostream>
#include <fstream>

computerRoom::computerRoom (const char* filename)
{
	std::ifstream ifs(filename, std::ios::in);
	if (!ifs.is_open() || ifs.eof()) {
		ifs.close();
		return;
	}
	int roomId, maxSize;
	while (ifs >> roomId && ifs >> maxSize)
	{
		m_rooms.insert(std::make_pair(roomId, maxSize));
	}
	ifs.close();
}

void computerRoom::printRoom() const
{
	std::cout << "������Ϣ���£�" << std::endl;
	for (auto it = m_rooms.begin(); it != m_rooms.end(); ++it) {
		std::cout << "������ţ�" << it->first
			<< "\t�������������" << it->second << std::endl;
	}
}
