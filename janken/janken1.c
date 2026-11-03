#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    int you, comp, judge;
    const char *hand[3] = { "グー", "チョキ", "パー" };

    srand((unsigned int)time(NULL));

    /* 1. 人間が手を決める */
    printf("あなたの手 (0)グー (1)チョキ (2)パー：");
    scanf("%d", &you);

    /* 2. コンピュータが手を決める */
    comp = rand() % 3;
    printf("わたしは%s\n", hand[comp]);

    /* 3. 勝敗を判定して表示する */
    judge = (you - comp + 3) % 3;
    if (judge == 0) {
        printf("引き分けです\n");
    } else if (judge == 1) {
        printf("あなたの負けです\n");
    } else {
        printf("あなたの勝ちです\n");
    }

    return 0;
}
