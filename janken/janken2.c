#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    int you, comp, judge;
    const char *hand[3] = { "グー", "チョキ", "パー" };

    srand((unsigned int)time(NULL));   /* 開始時に1度だけ実行 */

    while (1) {
        printf("あなたの手 (0)グー (1)チョキ (2)パー (-1)終了：");
        scanf("%d", &you);

        if (you == -1) {               /* -1 なら終了 */
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
    }

    return 0;
}
