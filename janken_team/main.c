/* 担当C：main（各担当の関数をつなぐ） */
#include "janken.h"

/* 正しい手が入るまで繰り返す。入力が終わったら 0、読めたら 1 */
static int read_hand(int *you)
{
    int st;

    while (1) {
        show_hand_prompt();
        st = input_hand(you);
        if (st == INPUT_OK)  return 1;
        if (st == INPUT_EOF) return 0;
        show_hand_error();
    }
}

/* 正しい選択が入るまで繰り返す。入力が終わったら 0、読めたら 1 */
static int read_continue(int *cont)
{
    int st;

    while (1) {
        show_continue_prompt();
        st = input_continue(cont);
        if (st == INPUT_OK)  return 1;
        if (st == INPUT_EOF) return 0;
        show_continue_error();
    }
}

int main(void)
{
    int you, comp, judge, cont;
    double rate;
    int result[3] = { 0, 0, 0 };

    init_random();

    while (1) {
        if (!read_hand(&you)) {
            break;
        }
        decide_comp_hand(&comp);
        show_comp_hand(comp);

        judge_hand(you, comp, &judge);
        show_judge(judge);
        record_result(result, judge);

        if (!read_continue(&cont) || cont == CONTINUE_NO) {
            break;
        }
    }

    show_end();
    calc_win_rate(result, &rate);
    show_match(result, rate);
    return 0;
}
