/*ave関数を定義するファイル*/

#include "ave.h"
// プロトタイプ宣言のheaderをひいてくる
double ave(int a, int b, int c)
{
    double d = (a + b + c) / 3.0;
    return d;
}