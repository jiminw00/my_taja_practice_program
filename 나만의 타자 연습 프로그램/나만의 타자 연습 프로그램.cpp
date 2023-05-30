//  나만의 타자 연습 프로그램
// 
#define _CRT_SECURE_NO_WARNINGS

#include <windows.h>
#include <iostream>
#include <fstream> // 추가: 파일 입출력을 위한 헤더 파일
#include "Menu.h"
#include "Show.h" // 추가: Show 클래스 헤더 파일
#include "Option.h"
#include "Now.h"
using namespace std;

int main() {
    Option op;
    // 콘솔 이름 설정
    SetConsoleTitleA("나만의 타자 연습 프로그램");
    op.play_songs();


    Menu menu;
    menu.menu_switch();

    return 0;
}
