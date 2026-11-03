#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* result[0]:引き分け result[1]:負け result[2]:勝ち */
void print_match(int r[])
{
    printf("【総合勝敗表】\n");
    printf("引分 負け 勝ち\n");
    printf("%4d %4d %4d\n", r[0], r[1], r[2]);
}

int main(void)
{
    int you, comp, judge;
    int result[3] = { 0, 0, 0 };
    const char *hand[3] = { "グー", "チョキ", "パー" };

    srand((unsigned int)time(NULL));

    while (1) {
        printf("あなたの手 (0)グー (1)チョキ (2)パー (-1)終了：");
        scanf("%d", &you);

        if (you == -1) {
            break;
        }

        comp = rand() % 3;
        printf("わたしは%s\n", hand[comp]);

        judge = (you - comp + 3) % 3;
        if (judge == 0) {
            printf("引き分けです\n");
        } else if (judge == 1) {
            printf("あなたの負けです\n");
        } else {
            printf("あなたの勝ちです\n");
        }
        result[judge]++;               /* 勝敗を記録 */
    }

    print_match(result);               /* 終了時に統計表示 */

    return 0;
}
