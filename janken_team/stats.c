/* 担当D：集計 */
#include <stdio.h>
#include "janken.h"

void record_result(int *r, int judge)
{
    r[judge]++;            /* r[judge] と *(r + judge) は同じ意味 */
}

void print_match(const int *r)
{
    printf("【総合勝敗表】\n");
    printf("引分  負け  勝ち\n");
    printf("%d回   %d回   %d回\n", r[0], r[1], r[2]);
}
