#pragma once
#include "File_related.h"
#include "Event.h"
class Option : public Event
{
	int option_num;	// �ɼ� ���� ��ȣ
	int event_num;	// �̺�Ʈ ��ȣ
	std::string onoff;// �̺�Ʈ �¿���
 
public:
	void option_select();	// ���� ����
	void option_switch();	// ���� ����
	int option_event_ctl();	// �̺�Ʈ ����
	void event_color();		// ��
	File_related file;	// ���� ���� Ŭ���� 
};

