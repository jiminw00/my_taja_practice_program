#pragma once
class Event
{
protected:
	bool event_on[4]={1,1,1,1};
	int color = 0;
public:	
	void sound_effects(int doremi);	// ȿ����
	void change_colors(int color);	// ���� �� 
	void play_songs();	// �뷡 ���

};

