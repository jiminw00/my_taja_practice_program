#include "Event.h"
#include <windows.h>
#include <mmsystem.h>
#include <iostream>
#pragma comment(lib,"winmm.lib")

int	Event::dictionary() {
	if (event_on[1]&&event_on[0]) {
		//
	}
	return 0;
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