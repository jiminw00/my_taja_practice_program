#include "Menu.h"
#include <iostream>

using namespace std;

Menu::Menu() {
    menu_num = 0; // 멤버 변수 menu_num을 초기화
    lang_num = 0; // 멤버 변수 lang_num을 초기화
}

int Menu::menu_select() {
    system("cls");
    do {
        option.change_colors(15);
        cout << "====================나만의 타자 연습 프로그램====================" << endl;
        option.change_colors(14);
        cout << ">>>메뉴 선택<<<" << endl;
        option.change_colors(11);
        cout << " 1. 단어 연습 " << endl;
        cout << " 2. 짧은 글 연습 " << endl;
        cout << " 3. 긴 글 연습 " << endl;
        cout << " 4. 설정 " << endl;
        cout << " 5. 프로그램 종료  " << endl;
        option.change_colors(7);
        option.sound_effects('C');
        option.sound_effects('G');
        cout << " 메뉴를 선택하기 위해서 번호 입력" << endl;

        if (!(cin >> menu_num)) {
            cerr << "정수로 입력해주세요!" << endl;
            cin.clear();
            cin.ignore(INT16_MAX, '\n');
        }
        else if (menu_num > 5 || menu_num < 1) {
            cerr << "유효한 범위의 값을 입력해주세요." << endl;
        }
        else {
            break;
        }
    } while (1);
    return menu_num;
}

int Menu::choose_language() {

    do {
        option.sound_effects('C');
        option.sound_effects('G');
        option.change_colors(14);
        cout << ">>>언어 선택<<<" << endl;
        option.change_colors(11);
        cout << " 1. 한국어 " << endl;
        cout << " 2. 영어 " << endl;
        cout << " 3. C++ " << endl;
        cout << " 4. 메뉴로 돌아가기  " << endl;
        option.change_colors(7);
        cout << " 언어를 선택하기 위해서 번호 입력" << endl;

        if (!(cin >> lang_num)) {
            cerr << "정수로 입력해주세요!" << endl;
            cin.clear();
            cin.ignore(INT16_MAX, '\n');
        }
        else if (lang_num > 4 || lang_num < 1) {
            cerr << "유효한 범위의 값을 입력해주세요." << endl;
        }
        else {
            break;
        }
    } while (1);
    return lang_num;
}

void Menu::menu_switch() {

    while (1) {
        system("cls");
        menu_select();
        system("cls");


        switch (menu_num) {
        case 1:
            choose_language();
            now.do_practice(lang_num, menu_num);
            break;
        case 2:
            choose_language();
            now.do_practice(lang_num, menu_num);
            break;
        case 3:
            choose_language();
            now.do_practice(lang_num, menu_num);
            break;
        case 4:
            option.option_select();
            break;
        case 5:
            programKill();
            break;
        }
        menu_num = 0;
    }
    system("cls");
}

void Menu::programKill() {
    exit(0);
}