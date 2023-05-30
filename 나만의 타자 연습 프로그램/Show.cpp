#include "Show.h"
#include <cmath>

using namespace std;
 
int Show::isKorean(int val, int lang_num) {
    if (lang_num==1) return val / 2;
    else return val;
}

int Show::typo(std::string user_input, std::string file_input, int lang_num, bool now) {


    // 길이 차이 더해주기
    temp = user_input.length() - file_input.length();
    cnt[0] += abs(temp);

    // 둘 중 더 길이가 짧은 것 까지만 비교
    temp = user_input.length() < file_input.length() ? user_input.length() : file_input.length();
    for (int i = 0; i < temp ; ++i) {
        if (file_input[i] != user_input[i]) {
             cnt[0]++;
        }
    }

    sum[0] += cnt[0];

    if (now) {
        temp = cnt[0];
        cnt[0] = 0;
        return isKorean(temp, lang_num);
    }
    else {
        temp = sum[0];
        sum[0] = 0;
        return isKorean(temp, lang_num);
    }
}

int Show::tasuu(std::string user_input, int lang_num, int time_lapse, bool now) {

    cnt[1] = user_input.length() * 60 / (time_lapse / 1000.0);
    all_cnt++;
    sum[1] += cnt[1];
    if (now) { 
        temp = cnt[1];
        cnt[1] = 0;
        return  temp; 
    }
    else {
        temp = sum[1]/all_cnt;
        sum[1] = 0, all_cnt = 0;
        return  temp;
    }
}

int Show::correctness(std::string user_input, std::string file_input, bool now) {
    int finlen = 0;
    if (now) {
        cnt[2] = 0;
        // 0으로 나누기 방어 
         finlen = file_input.length();
        int len = std::min(user_input.length(), file_input.length());
        len_sum += finlen ;
        if (file_input.length() == 0)
            finlen = 1, cnt[2]= 1;

        for (int i = 0; i < len; i++) {
           
            if (user_input[i] == file_input[i]) {
                cnt[2]++;
            }
        }
        sum[2] += cnt[2];
        return (int)(((double)cnt[2] / finlen) * 100);
    }

    else {
        int temp2 = len_sum;
        temp = sum[2];
        sum[2] = len_sum= 0;
        return  (int)(((double)temp /temp2) * 100);
    }
}

double Show::timelapse( int time_lapse, bool now) {

    cnt[3] = time_lapse / 1000.0;
    sum[3] += cnt[3];

    if (now) {
        temp = cnt[3];
        cnt[3] = 0;
        return  temp;
    }
    else {
        temp = sum[3];
        sum[3] = 0;
        return  temp;
    }
}