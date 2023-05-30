#include "Now.h"
#include "Option.h"

#pragma once
class Menu
{
	int menu_num;	// 메뉴 선택 번호
	int lang_num;	// 언어 선택 번호
public:
	Menu();
	int menu_select();	// 메뉴 선택 
	void menu_switch();	
	int choose_language();	// 언어 선택 
	void programKill();	//프로그램 종료


private:
	Now now;		// 타자 입력 진행 클래스
	Option option;	// 설정 클래스
};

