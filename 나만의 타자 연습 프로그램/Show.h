#pragma once
#include <string>

class Show {
protected:
    int temp;
    double cnt[4] = { 0 };  // 오타수,타수, 정확도, 경과시간
    double sum[4] = { 0 };  // 오타수, 타수 정확도, 경과시간의 각 값 누적
    int len_sum = 0;    //correctness 함수에 사용, 총 연습 길이 누적 
    int all_cnt = 0;    // tassu에 사용, 총 반복 횟수 누적
public:

    int isKorean(int val, int lang_num);
    int typo(std::string user_input, std::string file_input, int lang_num, bool now);
    int tasuu(std::string user_input, int lang_num, int time_lapse, bool now);
    int correctness(std::string user_input, std::string file_input, bool now);
    double timelapse(int timelapse, bool now);
};

