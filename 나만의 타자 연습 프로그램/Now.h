#pragma once
#include "Show.h"
#include "Event.h"
#include <string>

class Now
{
	std::string user_input;
	std::string file_input;
	std::string filename;
	int lang_num;
	int menu_num;
	int time_lapse;

public:
	void do_practice(int lang_num, int menu_num);	// Ÿ�� �Է�
	std::string get_file(int lang_num, int menu_num);		// �˸��� ���� �������� �Լ�
	void show_status(bool now, int iteration, int total_iterations);	// ��� �ð�, ���൵, ��Ÿ �� ���

	Show show;	// ���� ���� ���̴� Ŭ����
	Event ev;	// �̺�Ʈ ����
};


