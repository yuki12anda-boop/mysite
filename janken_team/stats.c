/* 担当C：集計 */
#include "janken.h"

void record_result(int *r, int judge)
{
    r[judge]++;            /* r[judge] と *(r + judge) は同じ意味 */
}

/* 勝率(%) = 勝ち ÷ 全対戦数 × 100。対戦数0なら0 */
void calc_win_rate(const int *r, double *rate)
{
    int total = r[RESULT_DRAW] + r[RESULT_LOSE] + r[RESULT_WIN];

    if (total == 0) {
        *rate = 0.0;
    } else {
        *rate = (double)r[RESULT_WIN] * 100.0 / total;
    }
}
