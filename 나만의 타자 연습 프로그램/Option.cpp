#include "Option.h"
#include "Event.h"
#include <iostream>

void Option::option_select() {
	system("cls");
	do {
		try {
			change_colors(14);
			sound_effects('C');
			sound_effects('G');
			std::cout << ">>>설정 메뉴 선택<<<" << std::endl;
			change_colors(11);
			std::cout << " 1. 데이터 파일 관리- 추가 " << std::endl;
			std::cout << " 2. 데이터 파일 관리- 수정 " << std::endl;
			std::cout << " 3. 데이터 파일 관리- 삭제 " << std::endl;
			std::cout << " 4. 이벤트 관리 " << std::endl;
			std::cout << " 5. 이전 단계 " << std::endl;
			change_colors(7);
			std::cout << " 메뉴를 선택하기 위해서 번호 입력" << std::endl;
			std::cin >> option_num;
			if (option_num > 5 || option_num < 1) {
				system("cls");
				std::cerr << "유효한 범위의 값을 입력해주세요. " << std::endl;
			}
			else if (std::cin.fail()) {
				std::cin.clear();
				std::cin.ignore();
				system("cls");
				throw std::runtime_error("정수로 입력해주세요!!");
			}
			else break;
		}
		catch (const std::runtime_error& e) {
			std::cerr << e.what() << std::endl;
		}

		std::cin.clear();
		std::cin.ignore(1000, '\n');

	} while (1);
	option_switch();
	        system("cls");
}
void Option::option_switch() {
	switch (option_num) {
	case 1:
		file.add_file_data();
		break;
	case 2:
		file.edit_file_data();
		break;
	case 3:
		file.del_file_data();
		break;
	case 4:
		option_event_ctl();
		break;
	case 5:
		return;
		break;
	}
}
void Option::event_color() {
	if (onoff == "켜짐")change_colors(15);
	else change_colors(8);
}
int Option::option_event_ctl(){
	while (1) {
		std::cin.ignore();
		system("cls");
		sound_effects('C');
		sound_effects('G');
		std::cout << ">>>이벤트 제어<<<" << std::endl;
		onoff = event_on[0] ?  "켜짐" : "꺼짐";
		event_color();
		std::cout << "1. 이벤트 전체: " << onoff << std::endl;
		onoff = event_on[1] ?"켜짐" : "꺼짐";
		event_color();
		std::cout << "2. 효과음: " << onoff << std::endl;
		onoff = event_on[2] ? "켜짐" : "꺼짐";
		event_color();
		std::cout << "3. 글씨 색: " << onoff << std::endl;
		onoff = event_on[3] ?  "켜짐" : "꺼짐";
		event_color(); 
		std::cout << "4. 노래 재생: " << onoff << std::endl;
		change_colors(14);
		std::cout << " on/off 할 이벤트 선택: ";
		std::cin >> event_num;
		change_colors(7);
		event_on[event_num-1] = !event_on[event_num-1];
		system("cls");
		std::cout << ">>>확정하시겠습니까?<<<" << std::endl;
		onoff = event_on[0] ?  "켜짐" : "꺼짐";
		event_color();
		std::cout << "1. 이벤트 전체: " << onoff << std::endl;
		onoff = event_on[1] ? "켜짐" : "꺼짐";
		event_color(); 
		std::cout << "2. 효과음: " << onoff << std::endl;
		onoff = event_on[2] ?  "켜짐" : "꺼짐";
		event_color(); 
		std::cout << "3. 글씨 색: " << onoff << std::endl;
		onoff = event_on[3] ?  "켜짐" : "꺼짐";
		event_color(); 
		std::cout << "4. 노래 재생: " << onoff << std::endl;
		change_colors(14);
		std::cout << " y/n: ";
		while (1) {
			std::cin.ignore();
			std::cin >> onoff;
			if (onoff == "y"|| onoff=="n")break;
			else std::cout << "올바른 값을 입력하세요.(y/n): " << std::endl;
		}
		if (onoff == "y")break;
		else if (onoff == "n") continue;
	}
	play_songs();
	return 1;
}