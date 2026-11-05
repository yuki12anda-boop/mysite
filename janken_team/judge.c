/* 担当C：勝敗判定 */
#include <stdio.h>
#include "janken.h"

void judge_hand(int you, int comp, int *judge)
{
    *judge = (you - comp + 3) % 3;
}

void show_judge(int judge)
{
    if (judge == RESULT_DRAW) {
        printf("引き分けです\n");
    } else if (judge == RESULT_LOSE) {
        printf("あなたの負けです\n");
    } else {
        printf("あなたの勝ちです\n");
    }
}
