# じゃんけんゲーム（4人分担）

## 機能
- 人間（0:グー 1:チョキ 2:パー）とコンピュータがじゃんけんをする
- 1回終わるごとに「続けますか？ 1:はい 2:いいえ」を確認する
- 手や継続の入力が誤りなら「誤りがあります」と表示して再入力させる
- 終了時に総合勝敗表（引分・負け・勝ち・勝率）を表示する

## 分担
| 担当 | ファイル | 関数 | ポインタの使いどころ |
|---|---|---|---|
| A 入力 | input.c | `input_hand(int *you)` / `input_continue(int *cont)` | 入力値を `*you` `*cont` に書き込む。**printf は使わない** |
| B コンピュータ・判定 | comp.c, judge.c | `init_random` / `decide_comp_hand(int *comp)` / `hand_name` / `judge_hand(int you, int comp, int *judge)` | 結果を `*comp` `*judge` に書き込む。**printf は使わない** |
| C 集計・全体の流れ | stats.c, main.c | `record_result(int *r, int judge)` / `calc_win_rate(const int *r, double *rate)` / main | 配列は先頭ポインタで渡す。勝率は `*rate` に書き込む。**printf は使わない** |
| D 表示（全部） | display.c | `show_hand_prompt` `show_hand_error` `show_comp_hand` `show_judge` `show_continue_prompt` `show_continue_error` `show_end` `show_match(const int *r, double rate)` | 配列を `const int *` で受け取り読むだけ |

共通ルール（定数・関数の形・戻り値）は janken.h に集約。変更するときは全員で相談する。

## 仕様の決めごと
- 勝率(%) = 勝ち ÷ 全対戦数 × 100（引き分けも対戦数に含む）。対戦数0のときは 0.0%。
- 入力が終わった場合（Ctrl+Z など）は、終了して勝敗表を表示する。
- 継続の選択は 1:はい 2:いいえ のみ有効。それ以外は「誤りがあります」。

## 入力の戻り値（input.c）
`INPUT_OK`（正しい） / `INPUT_INVALID`（誤り） / `INPUT_EOF`（入力終了）

## ビルドと実行（Windows / gcc）
    gcc -finput-charset=UTF-8 -fexec-charset=CP932 *.c -o janken_team.exe
    janken_team.exe
