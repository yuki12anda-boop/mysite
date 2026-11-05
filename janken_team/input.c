/* 担当A：入力（表示は担当Dの関数に任せるので printf は使わない） */
#include <stdio.h>
#include "janken.h"

/* 整数を1つ読む。数字以外なら行末まで読み捨てて INPUT_INVALID */
static int read_int(int *value)
{
    int ch;

    if (scanf("%d", value) != 1) {
        while ((ch = getchar()) != '\n' && ch != EOF) {
        }
        return (ch == EOF) ? INPUT_EOF : INPUT_INVALID;
    }
    return INPUT_OK;
}

int input_hand(int *you)
{
    int y;
    int st = read_int(&y);

    if (st != INPUT_OK) {
        return st;
    }
    if (y < HAND_GU || y > HAND_PA) {
        return INPUT_INVALID;
    }
    *you = y;                 /* ポインタ経由で呼び出し元の変数に書き込む */
    return INPUT_OK;
}

int input_continue(int *cont)
{
    int c;
    int st = read_int(&c);

    if (st != INPUT_OK) {
        return st;
    }
    if (c != CONTINUE_YES && c != CONTINUE_NO) {
        return INPUT_INVALID;
    }
    *cont = c;
    return INPUT_OK;
}
