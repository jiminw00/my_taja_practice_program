#pragma once
#include <string>
#include "Event.h"


class File_related
{
	std::string filename;
	std::string value;
	int fileNumber;
public:

	void which_file();		// ������ ���� ���� 
	void add_file_data();	// ���� ���� ������ �߰�
	void edit_file_data();	// ���� ������ ����
	void del_file_data();	// ���� ������ ����
	class Event ev;
};

