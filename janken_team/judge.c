/* 担当B：勝敗判定 */
#include "janken.h"

void judge_hand(int you, int comp, int *judge)
{
    *judge = (you - comp + 3) % 3;
}
