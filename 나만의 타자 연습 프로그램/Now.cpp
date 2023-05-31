#include "Now.h"
#include <iostream>
#include <string>
#include <fstream>
#include <chrono>
#include <conio.h>

using namespace std;
using namespace std::chrono;
 

string Now::get_file(int lang_num, int menu_num) {
    this->lang_num = lang_num;
    this->menu_num = menu_num;
    switch (menu_num) {
    case 1:    // �ܾ� ����
        switch (lang_num) {
        case 1:
            return "word_korean.txt";
        case 2:
            return "word_english.txt";
        case 3:
            return "cpp_keyword.txt";
        default:
            return "";
        }
        break;
    case 2:    // ���� ����
        switch (lang_num) {
        case 1:
            return "sentence_korean.txt";
        case 2:
            return "sentence_english.txt";
        case 3:
            return "cpp_func.txt";
        default:
            return "";
        }
        break;
    case 3:    // �� �� ����
        switch (lang_num) {
        case 1:
            return "long_korean.txt";
        case 2:
            return "long_english.txt";
        case 3:
            return "long_keyword.txt";
        default:
            return "";
        }
        break;
    default:
        return "";
    }
}

void Now::do_practice(int lang_num, int menu_num) {
   
    std::string filename = get_file(lang_num, menu_num);

    std::ifstream file(filename);
    if (filename == "") return;
    if (!file.is_open()) {
        std::cerr << filename << " ������ �� �� �����ϴ�." << std::endl;
        system("pause");
        return;
    }
    system("cls");
    ev.sound_effects('C');
    ev.sound_effects('G');
    std::cout << ">>>Ÿ�ڿ��� ����<<<" << std::endl;
    std::cout << "���� �ܰ�� ���ư����� ���� 0�� ��������. " << endl;
    cin.ignore();

    int max = 30; // �ݺ� Ƚ��
    int total=0;
    while (!file.eof()) {
        // ���͸� ������ ī��Ʈ�� ������Ű�� �ڵ�
        std::getline(file, file_input, '\n');
        // ī��Ʈ ����
        total++;
    }
    if (total < max) { max = total; total = 0; }
    file.clear();
    file.seekg(0, ios::beg);

    for (int i = 0; i < max; i++) {
 

        auto start_time = high_resolution_clock::now(); // ���� �ð� ����

            std::getline(file, file_input, '\n');
            if (file_input == "")continue;
            std::cout << file_input << std::endl;

            getline(std::cin, user_input, '\n');
            
            if (user_input == "0" ||i==max-1|| file.eof()) {
                ev.change_colors(14);
                show_status(0, i + 1, max);
                ev.change_colors(7);
                system("pause");
                system("cls");
                break;
            }
            

            auto end_time = high_resolution_clock::now(); // ���� �ð� ����
            time_lapse = duration_cast<milliseconds>(end_time - start_time).count();    // �и��� ������ ����
            system("cls");
            if (show.typo(user_input, file_input, lang_num, 1)) {
                ev.change_colors(4);
                ev.sound_effects('H');
            }
            else {
                ev.sound_effects('C');
                ev.sound_effects('E');
                ev.sound_effects('G');
                ev.change_colors(10);
            }
            cout << file_input << endl;
            cout << user_input << endl;
            ev.change_colors(8);
            show_status(1, i + 1, max);
            ev.change_colors(7);

        
    }

    file.close();
}


void Now::show_status(bool now, int iteration, int total_iterations) {
    // ���� ������ ���     
    if (total_iterations == 0) {
        total_iterations = 1;
        iteration= 0;
    } // 0���� ������ ��� 
    float progress = static_cast<float>(iteration) / total_iterations * 100.0;
    
    if (now == 1) {
          cout << "===============���� ����===============" << endl;
    }
    // ���� ����� ��� 
    else {
        cout << "===============���� ���===============" << endl;
    }

    cout << "���൵: " << progress << "%" << endl;
    cout << "��Ÿ��: " << show.typo(user_input, file_input, lang_num, now) << endl;
    cout << "��Ȯ��: " << show.correctness(user_input, file_input, now) << "%" << endl;
    cout << "Ÿ��: " << show.tasuu( user_input, lang_num, time_lapse, now) << endl;
    cout << "��� �ð�: " << show.timelapse(time_lapse, now) << "��" << endl;
    if (progress == 100) { 
        ev.sound_effects('C');
        ev.sound_effects('E');
        ev.sound_effects('G');
        ev.sound_effects('H');
    }
}