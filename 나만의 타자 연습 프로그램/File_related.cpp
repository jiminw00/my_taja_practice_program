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
            cout << ">>> 수정할 파일 선택 <<<" << endl;
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
            cout << "파일 번호를 입력하세요: ";
            cin >> fileNumber;
            if (cin.fail()) {
                cin.clear();
                cin.ignore();
                throw runtime_error("정수로 입력해주세요!!");
            }
            if (fileNumber < 1 || fileNumber > 9) {
                throw out_of_range("유효한 범위의 값을 입력해주세요.");
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
    // 선택한 파일에 해당하는 파일명 설정
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
    cin.ignore(); // 버퍼 비우기
    cout << "추가할 내용을 입력하세요: ";
    getline(cin, value);

    ofstream file(filename, ios::app);
    if (!file) {
        cerr << "파일을 열 수 없습니다." << endl;
        return;
    }
    ev.change_colors(14);
    file << value << '\n';
    cout << value<<"이(가) 추가되었습니다."<<endl;
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

    cin.ignore(); // 버퍼 비우기
    cout << "수정하고 싶은 데이터 검색: ";
    getline(cin, search_value);

    cin.ignore(); // 버퍼 비우기
    cout << "새로운 값을 입력하세요: ";
    getline(cin, new_value);

    ifstream file(filename);
    if (!file) {
        cerr << "파일을 열 수 없습니다." << endl;
        return;
    }

    string line;
    bool found = false;
    string fileData; // 수정된 파일 데이터를 저장할 변수

    while (getline(file, line)) {
        if (line == search_value) {
            line = new_value;
            found = true;
            cout << search_value << "을 " << line << "(으)로 수정하였습니다." << endl;
        }
        fileData += line + '\n';
    }

    file.close();

    if (!found) {
        cerr << "찾을 수 없는 값입니다." << endl;
        return;
    }

    ofstream outFile(filename);
    if (!outFile) {
        cerr << "파일을 열 수 없습니다." << endl;
        return;
    }

    outFile << fileData; // 수정된 파일 데이터를 새로 작성

    outFile.close();
    ev.change_colors(14);
    cout << "데이터가 수정되었습니다." << endl;
    ev.change_colors(7);
    system("pause");
}

void File_related::del_file_data() {
    ev.sound_effects('C');
    ev.sound_effects('G');
    which_file();
    system("cls");
    string search_value;

    cin.ignore(); // 버퍼 비우기
    cout << "삭제할 데이터를 입력하세요: ";
    getline(cin, search_value);

    ifstream file(filename);
    if (!file) {
        ev.change_colors(4);
        cerr << "파일을 열 수 없습니다." << endl;
        ev.change_colors(7);
        system("pause");
        system("cls");
        return;
    }

    string line;
    bool found = false;
    string fileData; // 수정된 파일 데이터를 저장할 변수

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
        cerr << "찾을 수 없는 값입니다." << endl;
        ev.change_colors(7);
        system("pause");
        return;
    }

    ofstream outFile(filename);
    if (!outFile) {
        ev.change_colors(4);
        cerr << "파일을 열 수 없습니다." << endl;
        ev.change_colors(7);
        system("pause");
        return;
    }

    outFile << fileData; // 수정된 파일 데이터를 새로 작성

    outFile.close();
    ev.change_colors(14);
    cout << "데이터가 삭제되었습니다." << endl;
    ev.change_colors(7);
    system("pause");
}