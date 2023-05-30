#pragma once
#include <string>

class Show {
protected:
    int temp;
    double cnt[4] = { 0 };  // ��Ÿ��,Ÿ��, ��Ȯ��, ����ð�
    double sum[4] = { 0 };  // ��Ÿ��, Ÿ�� ��Ȯ��, ����ð��� �� �� ����
    int len_sum = 0;    //correctness �Լ��� ���, �� ���� ���� ���� 
    int all_cnt = 0;    // tassu�� ���, �� �ݺ� Ƚ�� ����
public:

    int isKorean(int val, int lang_num);
    int typo(std::string user_input, std::string file_input, int lang_num, bool now);
    int tasuu(std::string user_input, int lang_num, int time_lapse, bool now);
    int correctness(std::string user_input, std::string file_input, bool now);
    double timelapse(int timelapse, bool now);
};

