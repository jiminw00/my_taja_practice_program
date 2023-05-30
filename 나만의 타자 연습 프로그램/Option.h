#pragma once
#include "File_related.h"
#include "Event.h"
class Option : public Event
{
	int option_num;	// 옵션 선택 번호
	int event_num;	// 이벤트 번호
	std::string onoff;// 이벤트 온오프
 
public:
	void option_select();	// 설정 선택
	void option_switch();	// 설정 선택
	int option_event_ctl();	// 이벤트 제어
	void event_color();		// 색
	File_related file;	// 파일 관련 클래스 
};

