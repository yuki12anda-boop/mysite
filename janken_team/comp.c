/* 担当B：コンピュータの手 */
#include <stdlib.h>
#include <time.h>
#include "janken.h"

static const char *names[3] = { "グー", "チョキ", "パー" };

void init_random(void)
{
    srand((unsigned int)time(NULL));
}

void decide_comp_hand(int *comp)
{
    *comp = rand() % 3;
}

const char *hand_name(int hand)
{
    return names[hand];
}
