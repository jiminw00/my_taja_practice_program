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
	void do_practice(int lang_num, int menu_num);	// 타자 입력
	std::string get_file(int lang_num, int menu_num);		// 알맞은 파일 가져오는 함수
	void show_status(bool now, int iteration, int total_iterations);	// 경과 시간, 진행도, 오타 수 출력

	Show show;	// 현재 상태 보이는 클래스
	Event ev;	// 이벤트 수행
};


