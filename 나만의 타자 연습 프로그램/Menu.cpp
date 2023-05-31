#include "Menu.h"
#include <iostream>

using namespace std;

Menu::Menu() {
    menu_num = 0; // ��� ���� menu_num�� �ʱ�ȭ
    lang_num = 0; // ��� ���� lang_num�� �ʱ�ȭ
}

int Menu::menu_select() {
    system("cls");
    do {
        option.change_colors(15);
        cout << "====================������ Ÿ�� ���� ���α׷�====================" << endl;
        option.change_colors(14);
        cout << ">>>�޴� ����<<<" << endl;
        option.change_colors(11);
        cout << " 1. �ܾ� ���� " << endl;
        cout << " 2. ª�� �� ���� " << endl;
        cout << " 3. �� �� ���� " << endl;
        cout << " 4. ���� " << endl;
        cout << " 5. ���α׷� ����  " << endl;
        option.change_colors(7);
        option.sound_effects('C');
        option.sound_effects('G');
        cout << " �޴��� �����ϱ� ���ؼ� ��ȣ �Է�" << endl;

        if (!(cin >> menu_num)) {
            cerr << "������ �Է����ּ���!" << endl;
            cin.clear();
            cin.ignore(INT16_MAX, '\n');
        }
        else if (menu_num > 5 || menu_num < 1) {
            cerr << "��ȿ�� ������ ���� �Է����ּ���." << endl;
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
        cout << ">>>��� ����<<<" << endl;
        option.change_colors(11);
        cout << " 1. �ѱ��� " << endl;
        cout << " 2. ���� " << endl;
        cout << " 3. C++ " << endl;
        cout << " 4. �޴��� ���ư���  " << endl;
        option.change_colors(7);
        cout << " �� �����ϱ� ���ؼ� ��ȣ �Է�" << endl;

        if (!(cin >> lang_num)) {
            cerr << "������ �Է����ּ���!" << endl;
            cin.clear();
            cin.ignore(INT16_MAX, '\n');
        }
        else if (lang_num > 4 || lang_num < 1) {
            cerr << "��ȿ�� ������ ���� �Է����ּ���." << endl;
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