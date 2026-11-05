#ifndef JANKEN_H
#define JANKEN_H

/* ===== 全員共通のルール（変更するときは全員で相談する） ===== */
#define HAND_GU     0
#define HAND_CHOKI  1
#define HAND_PA     2
#define QUIT       -1

#define RESULT_DRAW 0   /* 引き分け */
#define RESULT_LOSE 1   /* あなたの負け */
#define RESULT_WIN  2   /* あなたの勝ち */

/* ===== 担当A：input.c（人間の入力） ===== */
/* 人間の手を読み込み *you に格納する。
   戻り値: 1=続行, 0=終了(-1入力 または 入力終端) */
int input_hand(int *you);

/* ===== 担当B：comp.c（コンピュータの手） ===== */
void init_random(void);                    /* 乱数初期化（最初に1回だけ） */
void decide_comp_hand(int *comp);          /* 0〜2 を *comp に格納 */
const char *hand_name(int hand);           /* 0→"グー" 1→"チョキ" 2→"パー" */

/* ===== 担当C：judge.c（勝敗判定） ===== */
void judge_hand(int you, int comp, int *judge); /* 結果を *judge に格納 */
void show_judge(int judge);                     /* 結果の文言を表示 */

/* ===== 担当D：stats.c（集計）と main.c ===== */
void record_result(int *r, int judge);     /* r[judge] を1増やす */
void print_match(const int *r);            /* 総合勝敗表を表示 */

#endif
