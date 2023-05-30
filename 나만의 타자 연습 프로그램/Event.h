#pragma once
class Event
{
protected:
	bool event_on[4];
	int color = 0;
public:
	int	dictionary();		
	void change_colors(int color);	// 글자 색 
	void play_songs( );	// 노래 재생
	
};

