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
			std::cout << ">>>���� �޴� ����<<<" << std::endl;
			change_colors(11);
			std::cout << " 1. ������ ���� ����- �߰� " << std::endl;
			std::cout << " 2. ������ ���� ����- ���� " << std::endl;
			std::cout << " 3. ������ ���� ����- ���� " << std::endl;
			std::cout << " 4. �̺�Ʈ ���� " << std::endl;
			std::cout << " 5. ���� �ܰ� " << std::endl;
			change_colors(7);
			std::cout << " �޴��� �����ϱ� ���ؼ� ��ȣ �Է�" << std::endl;
			std::cin >> option_num;
			if (option_num > 5 || option_num < 1) {
				system("cls");
				std::cerr << "��ȿ�� ������ ���� �Է����ּ���. " << std::endl;
			}
			else if (std::cin.fail()) {
				std::cin.clear();
				std::cin.ignore();
				system("cls");
				throw std::runtime_error("������ �Է����ּ���!!");
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
	if (onoff == "����")change_colors(15);
	else change_colors(8);
}
int Option::option_event_ctl(){
	while (1) {
		std::cin.ignore();
		system("cls");
		sound_effects('C');
		sound_effects('G');
		std::cout << ">>>�̺�Ʈ ����<<<" << std::endl;
		onoff = event_on[0] ?  "����" : "����";
		event_color();
		std::cout << "1. �̺�Ʈ ��ü: " << onoff << std::endl;
		onoff = event_on[1] ?"����" : "����";
		event_color();
		std::cout << "2. ȿ����: " << onoff << std::endl;
		onoff = event_on[2] ? "����" : "����";
		event_color();
		std::cout << "3. �۾� ��: " << onoff << std::endl;
		onoff = event_on[3] ?  "����" : "����";
		event_color(); 
		std::cout << "4. �뷡 ���: " << onoff << std::endl;
		change_colors(14);
		std::cout << " on/off �� �̺�Ʈ ����: ";
		std::cin >> event_num;
		change_colors(7);
		event_on[event_num-1] = !event_on[event_num-1];
		system("cls");
		std::cout << ">>>Ȯ���Ͻðڽ��ϱ�?<<<" << std::endl;
		onoff = event_on[0] ?  "����" : "����";
		event_color();
		std::cout << "1. �̺�Ʈ ��ü: " << onoff << std::endl;
		onoff = event_on[1] ? "����" : "����";
		event_color(); 
		std::cout << "2. ȿ����: " << onoff << std::endl;
		onoff = event_on[2] ?  "����" : "����";
		event_color(); 
		std::cout << "3. �۾� ��: " << onoff << std::endl;
		onoff = event_on[3] ?  "����" : "����";
		event_color(); 
		std::cout << "4. �뷡 ���: " << onoff << std::endl;
		change_colors(14);
		std::cout << " y/n: ";
		while (1) {
			std::cin.ignore();
			std::cin >> onoff;
			if (onoff == "y"|| onoff=="n")break;
			else std::cout << "�ùٸ� ���� �Է��ϼ���.(y/n): " << std::endl;
		}
		if (onoff == "y")break;
		else if (onoff == "n") continue;
	}
	play_songs();
	return 1;
}