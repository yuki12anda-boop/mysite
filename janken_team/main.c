/* 担当D：main（各担当の関数をつなぐ） */
#include <stdio.h>
#include "janken.h"

int main(void)
{
    int you, comp, judge;
    int result[3] = { 0, 0, 0 };

    init_random();

    while (input_hand(&you)) {          /* 0 が返ったら終了 */
        decide_comp_hand(&comp);
        printf("わたしは%s\n", hand_name(comp));

        judge_hand(you, comp, &judge);
        show_judge(judge);

        record_result(result, judge);
    }

    printf("ゲームを終了します\n");
    print_match(result);
    return 0;
}
