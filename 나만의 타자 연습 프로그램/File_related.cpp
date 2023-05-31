#include "File_related.h"
#include <fstream>
#include <iostream>

using namespace std;

void File_related::which_file() {
    while (true) {
        try {
            system("cls");
            ev.sound_effects('C');
            ev.sound_effects('G');
            ev.change_colors(14);
            cout << ">>> ������ ���� ���� <<<" << endl;
            ev.change_colors(11);
            cout << "1. word_korean.txt" << endl;
            cout << "2. word_english.txt" << endl;
            cout << "3. cpp_keyword.txt" << endl;
            cout << "4. sentence_korean.txt" << endl;
            cout << "5. sentence_english.txt" << endl;
            cout << "6. cpp_func.txt" << endl;
            cout << "7. long_korean.txt" << endl;
            cout << "8. long_english.txt" << endl;
            cout << "9. long_keyword.txt" << endl;
            ev.change_colors(7);
            cout << "���� ��ȣ�� �Է��ϼ���: ";
            cin >> fileNumber;
            if (cin.fail()) {
                cin.clear();
                cin.ignore();
                throw runtime_error("������ �Է����ּ���!!");
            }
            if (fileNumber < 1 || fileNumber > 9) {
                throw out_of_range("��ȿ�� ������ ���� �Է����ּ���.");
            }
            break;
        }
        catch (const runtime_error& e) {
            cerr << e.what() << endl;
        }
        catch (const out_of_range& e) {
            cerr << e.what() << endl;
        }
    }
    // ������ ���Ͽ� �ش��ϴ� ���ϸ� ����
    switch (fileNumber) {
    case 1:
        filename = "word_korean.txt";
        break;
    case 2:
        filename = "word_english.txt";
        break;
    case 3:
        filename = "cpp_keyword.txt";
        break;
    case 4:
        filename = "sentence_korean.txt";
        break;
    case 5:
        filename = "sentence_english.txt";
        break;
    case 6:
        filename = "cpp_func.txt";
        break;
    case 7:
        filename = "long_korean.txt";
        break;
    case 8:
        filename = "long_english.txt";
        break;
    case 9:
        filename = "long_keyword.txt";
        break;
    }
}

void File_related::add_file_data() {
    ev.sound_effects('C');
    ev.sound_effects('G');
    which_file();
    system("cls");
    cin.ignore(); // ���� ����
    cout << "�߰��� ������ �Է��ϼ���: ";
    getline(cin, value);

    ofstream file(filename, ios::app);
    if (!file) {
        cerr << "������ �� �� �����ϴ�." << endl;
        return;
    }
    ev.change_colors(14);
    file << value << '\n';
    cout << value<<"��(��) �߰��Ǿ����ϴ�."<<endl;
    ev.change_colors(7);

    system("pause");
}

void File_related::edit_file_data() {
    ev.sound_effects('C');
    ev.sound_effects('G');
    which_file();
    system("cls");
    string search_value;
    string new_value;

    cin.ignore(); // ���� ����
    cout << "�����ϰ� ���� ������ �˻�: ";
    getline(cin, search_value);

    cin.ignore(); // ���� ����
    cout << "���ο� ���� �Է��ϼ���: ";
    getline(cin, new_value);

    ifstream file(filename);
    if (!file) {
        cerr << "������ �� �� �����ϴ�." << endl;
        return;
    }

    string line;
    bool found = false;
    string fileData; // ������ ���� �����͸� ������ ����

    while (getline(file, line)) {
        if (line == search_value) {
            line = new_value;
            found = true;
            cout << search_value << "�� " << line << "(��)�� �����Ͽ����ϴ�." << endl;
        }
        fileData += line + '\n';
    }

    file.close();

    if (!found) {
        cerr << "ã�� �� ���� ���Դϴ�." << endl;
        return;
    }

    ofstream outFile(filename);
    if (!outFile) {
        cerr << "������ �� �� �����ϴ�." << endl;
        return;
    }

    outFile << fileData; // ������ ���� �����͸� ���� �ۼ�

    outFile.close();
    ev.change_colors(14);
    cout << "�����Ͱ� �����Ǿ����ϴ�." << endl;
    ev.change_colors(7);
    system("pause");
}

void File_related::del_file_data() {
    ev.sound_effects('C');
    ev.sound_effects('G');
    which_file();
    system("cls");
    string search_value;

    cin.ignore(); // ���� ����
    cout << "������ �����͸� �Է��ϼ���: ";
    getline(cin, search_value);

    ifstream file(filename);
    if (!file) {
        ev.change_colors(4);
        cerr << "������ �� �� �����ϴ�." << endl;
        ev.change_colors(7);
        system("pause");
        system("cls");
        return;
    }

    string line;
    bool found = false;
    string fileData; // ������ ���� �����͸� ������ ����

    while (getline(file, line)) {
        if (line != search_value) {
            fileData += line + '\n';
        }
        else {
            found = true;
        }
    }

    file.close();

    if (!found) {
        ev.change_colors(4);
        cerr << "ã�� �� ���� ���Դϴ�." << endl;
        ev.change_colors(7);
        system("pause");
        return;
    }

    ofstream outFile(filename);
    if (!outFile) {
        ev.change_colors(4);
        cerr << "������ �� �� �����ϴ�." << endl;
        ev.change_colors(7);
        system("pause");
        return;
    }

    outFile << fileData; // ������ ���� �����͸� ���� �ۼ�

    outFile.close();
    ev.change_colors(14);
    cout << "�����Ͱ� �����Ǿ����ϴ�." << endl;
    ev.change_colors(7);
    system("pause");
}