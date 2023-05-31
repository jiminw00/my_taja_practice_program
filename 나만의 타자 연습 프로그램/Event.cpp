#include "Event.h"
#include <windows.h>
#include <mmsystem.h>
#include <iostream>
#pragma comment(lib,"winmm.lib")

void Event::sound_effects(int doremi) {
	if (event_on[1] && event_on[0]) {
		switch (doremi) {
		case 'C':
			Beep(260, 200);//음(도), 지속시간(밀리초)
			break;
		case 'D':
			Beep(290, 200);//음(레), 지속시간(밀리초)
			break;
		case 'E':
			Beep(330, 200);//음(미), 지속시간(밀리초)
			break;
		case 'F':
			Beep(340, 200);//음(파), 지속시간(밀리초)
			break;
		case 'G':
			Beep(380, 200);//음(솔), 지속시간(밀리초)
			break;
		case 'A':
			Beep(430, 200);//음(라), 지속시간(밀리초)
			break;
		case 'B':
			Beep(490, 200);//음(시), 지속시간(밀리초)
			break;
		case 'H':
			Beep(510, 200);//음(높은도), 지속시간(밀리초)
			break;
		}
	}
}

void Event::change_colors( int color) {
	if (event_on[2] && event_on[0]) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
	}
}

void Event::play_songs(){
	if (event_on[3] && event_on[0]) {
	PlaySound( TEXT("hello_world.wav"), 0, SND_ASYNC | SND_LOOP); //노래 재생
	}
	else     PlaySound(NULL, 0, 0);
}