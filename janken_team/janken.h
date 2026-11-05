#ifndef JANKEN_H
#define JANKEN_H

/* ===== 全員共通のルール（変更するときは全員で相談する） ===== */
#define HAND_GU      0
#define HAND_CHOKI   1
#define HAND_PA      2

#define RESULT_DRAW  0   /* 引き分け */
#define RESULT_LOSE  1   /* あなたの負け */
#define RESULT_WIN   2   /* あなたの勝ち */

#define CONTINUE_YES 1   /* 続ける */
#define CONTINUE_NO  2   /* 終了する */

/* 入力関数の戻り値 */
#define INPUT_OK       0 /* 正しく入力された */
#define INPUT_INVALID  1 /* 入力の誤り */
#define INPUT_EOF      2 /* 入力が終わった（Ctrl+Z 等） */

/* ===== 担当A：input.c（入力。printf は使わない） ===== */
int input_hand(int *you);        /* 0〜2 を *you に格納。戻り値は INPUT_xxx */
int input_continue(int *cont);   /* 1か2 を *cont に格納。戻り値は INPUT_xxx */

/* ===== 担当B：comp.c / judge.c（コンピュータと判定。printf は使わない） ===== */
void init_random(void);                         /* 乱数初期化（最初に1回だけ） */
void decide_comp_hand(int *comp);               /* 0〜2 を *comp に格納 */
const char *hand_name(int hand);                /* 0→"グー" 1→"チョキ" 2→"パー" */
void judge_hand(int you, int comp, int *judge); /* RESULT_xxx を *judge に格納 */

/* ===== 担当C：stats.c / main.c（集計と全体の流れ。printf は使わない） ===== */
void record_result(int *r, int judge);          /* r[judge] を1増やす */
void calc_win_rate(const int *r, double *rate); /* 勝率(%) を *rate に格納 */

/* ===== 担当D：display.c（画面表示はすべてここ） ===== */
void show_hand_prompt(void);                    /* 手の入力案内 */
void show_hand_error(void);                     /* 手の入力の誤り */
void show_comp_hand(int comp);                  /* 「わたしは○○」 */
void show_judge(int judge);                     /* 勝敗の文言 */
void show_continue_prompt(void);                /* 継続の確認 1:yes 2:no */
void show_continue_error(void);                 /* 「誤りがあります」 */
void show_end(void);                            /* 終了メッセージ */
void show_match(const int *r, double rate);     /* 総合勝敗表（勝率つき） */

#endif
