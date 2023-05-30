#pragma once
#include <string>
#include "Event.h"


class File_related
{
	std::string filename;
	std::string value;
	int fileNumber;
public:

	void which_file();		// 수정할 파일 선택 
	void add_file_data();	// 파일 끝에 데이터 추가
	void edit_file_data();	// 파일 데이터 수정
	void del_file_data();	// 파일 데이터 삭제
	class Event ev;
};

