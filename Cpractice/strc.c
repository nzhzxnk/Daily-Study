/*form関数とline関数を同じファイルに保存している*/
// 1ファイルに1関数ではないので同じ分類のものをまとめたりするのが良い？
#include "strc.h"
#include <stdio.h>
// printfとかを使っているので<stdio.h>もコンパイルする

void form(char subject[], int *score)
{
    extern int x;
    // グローバル関数であるxを使う
    // xはmain.cに定義されており、strc.cとは別の場所で定義されたものを使用するということでextern int x;と書く    printf("あなたの素点は%d点です。\n", x);
    printf("あなたの%sの点数を入力してください。:", subject);
    scanf("%d", score);
}
void line()
{
    printf("************************\n");
}
