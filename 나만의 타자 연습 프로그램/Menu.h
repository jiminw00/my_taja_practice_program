#include "Now.h"
#include "Option.h"

#pragma once
class Menu
{
	int menu_num;	// �޴� ���� ��ȣ
	int lang_num;	// ��� ���� ��ȣ
public:
	Menu();
	int menu_select();	// �޴� ���� 
	void menu_switch();	
	int choose_language();	// ��� ���� 
	void programKill();	//���α׷� ����


private:
	Now now;		// Ÿ�� �Է� ���� Ŭ����
	Option option;	// ���� Ŭ����
};

