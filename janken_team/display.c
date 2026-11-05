/* 担当D：画面表示はすべてここ */
#include <stdio.h>
#include "janken.h"

void show_hand_prompt(void)
{
    printf("あなたの手は（0）グー（1）チョキ（2）パー：");
}

void show_hand_error(void)
{
    printf("誤りがあります。0～2を入力してください\n");
}

void show_comp_hand(int comp)
{
    printf("わたしは%s\n", hand_name(comp));
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

void show_continue_prompt(void)
{
    printf("続けますか？（1）はい（2）いいえ：");
}

void show_continue_error(void)
{
    printf("誤りがあります。1か2を入力してください\n");
}

void show_end(void)
{
    printf("ゲームを終了します\n");
}

void show_match(const int *r, double rate)
{
    printf("【総合勝敗表】\n");
    printf("引分  負け  勝ち  勝率\n");
    printf("%d回   %d回   %d回   %.1f%%\n", r[0], r[1], r[2], rate);
}
