/* 担当A：人間の入力 */
#include <stdio.h>
#include "janken.h"

int input_hand(int *you)
{
    int y, ch;

    while (1) {
        printf("あなたの手は（0）グー（1）チョキ（2）パー（-1）終了：");
        if (scanf("%d", &y) != 1) {
            /* 数字以外：行末まで読み捨てて再入力 */
            while ((ch = getchar()) != '\n' && ch != EOF) {
            }
            if (ch == EOF) {
                return 0;
            }
            printf("数字を入力してください\n");
            continue;
        }
        if (y == QUIT) {
            return 0;
        }
        if (y < HAND_GU || y > HAND_PA) {
            printf("0～2または-1を入力してください\n");
            continue;
        }
        *you = y;          /* ポインタ経由で呼び出し元の変数に書き込む */
        return 1;
    }
}
