# じゃんけんゲーム（4人分担）

| 担当 | ファイル | 作る関数 | ポインタの使いどころ |
|---|---|---|---|
| A | input.c | `int input_hand(int *you)` | 入力した手を `*you` に書き込む |
| B | comp.c | `init_random` / `decide_comp_hand(int *comp)` / `hand_name` | 手を `*comp` に書き込む。名前は `const char *` で返す |
| C | judge.c | `judge_hand(int you, int comp, int *judge)` / `show_judge` | 判定結果を `*judge` に書き込む |
| D | stats.c, main.c | `record_result(int *r, int judge)` / `print_match(const int *r)` / main | 配列は先頭ポインタで渡す |

共通ルール（定数・関数の形）は janken.h に集約。変更するときは全員で相談する。

## ビルドと実行（Windows / gcc）
    gcc -finput-charset=UTF-8 -fexec-charset=CP932 *.c -o janken_team.exe
    janken_team.exe
