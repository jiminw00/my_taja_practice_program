#pragma once
class Event
{
protected:
	bool event_on[4]={1,1,1,1};
	int color = 0;
public:	
	void sound_effects(int doremi);	// 효과음
	void change_colors(int color);	// 글자 색 
	void play_songs();	// 노래 재생

};

