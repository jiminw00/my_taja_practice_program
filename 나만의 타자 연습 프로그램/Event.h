#pragma once
class Event
{
protected:
	bool event_on[4];
	int color = 0;
public:
	int	dictionary();		
	void change_colors(int color);	// ���� �� 
	void play_songs( );	// �뷡 ���
	
};

